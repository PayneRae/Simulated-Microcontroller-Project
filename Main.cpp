#include <iostream>
#include <chrono>
#include <thread>
#include <array>
#include <conio.h>

enum class LEDRate { one_second, zero_two_seconds };

class LEDStateMachine {
public:

    void updateState() {
        using clock = std::chrono::steady_clock;
        auto start = clock::now(); // starting point for clock
        auto next = start; // next is initially start

        bool lastinputpress = false;
        // always true
        while (true)
        {
            //Check the keyboard input
            if (_kbhit())
            {
                int ch = _getch(); // read the entered key
                switch (ch)
                {
                case ('r'):
                    lastinputpress = false;
                    this->currentRate = LEDRate::one_second;
                    break;
                case ('p'):
                    if (lastinputpress)
                    {
                        this->currentRate = LEDRate::one_second;
                    }
                    else
                    {
                        this->currentRate = LEDRate::zero_two_seconds;
                    }
                    lastinputpress = true;
                    break;
                }
            }
            switch (this->currentRate)
            {
            case (LEDRate::one_second):
                auto rate1 = std::chrono::seconds(1);
                next = next + rate1;
                break;
            case (LEDRate::zero_two_seconds):
                auto rate2 = std::chrono::milliseconds(200);
                next = next + rate2;
                break;
            }
            auto now = clock::now();
            //std::cout << "Now: " << std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() << std::endl;
            auto elasped = std::chrono::duration_cast<std::chrono::seconds>(now - start);
            std::cout << "LED ON " << elasped.count() << 'ms' << std::endl;
            std::this_thread::sleep_until(next);
        }
    }

    LEDRate getRate()
    {
        return currentRate;
    }

private:
    LEDRate currentRate{ LEDRate::one_second };

};

int main() {
    LEDStateMachine test_machine;

    std::cout << "Press the character p once to press the button." << std::endl;
    std::cout << "Press the character p more than once to hold the button" << std::endl;
    std::cout << "Press the r character to release the button" << std::endl;

    std::cout << "LED OFF" << std::endl;
    test_machine.updateState();
};

