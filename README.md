# Simulated Microcontroller Project

This project describes an entirely simulated microcontroller program (no hardware implementation) close to what would be found on a real embedded device.

## Purpose
The purpose of this program is to change the rate at which a message "LED ON" is printed to the console, either in 1 second or 0.2 second intervals. When the program is ran, the message immediately begins printing with the default rate of 1 second. By pressing the key 'p', the rate changes to 0.2 seconds. If 'p' is pressed again before 'r' is pressed, the rate changes back to 1 second. The 'r' key being pressed at any time changes the output rate to 1 second.

## Concepts Studied
I used a variety of programming concepts common to microcontroller programming to accomplish this purpose. These include enumerated classes, switch statements, and manipulation. It was through these concepts that I was able to produce a functioning state machine capable of responsing to key presses instantaneously. Additionaly, chrono, thread, and conio.h were included.

## Order of Execution
In Main(), an object test_machine is declared of class LEDStateMachine. After some helpful messages are printed to the screen, the method updateState() is called on test_machine. When the method is entered, first we set the std:chrono clock we are using to stead_clock. This mimicks a timer, perfect for our purpose. Start and next variables are declared and intialized based on this clock. We declare variable lastinputpress and intilaize it to false to record the last pressed input. Next we enter the while loop, which is always executing until the program is terminated. We use an if condition to check for keyboard input, declare a character to access the pressed key, and set up the condition (switch statement) to fulfill the purpose outlined above. Private data memebers are used to access the same variable throughout the LEDStateMachine class. After an interval is calculated, it is added to the next varaible, which allows a sleep_until statment to appropriately time the message outputs.

## Future Improvements
There are a number of additional improvements that could be implemented in this project, especially as other simulations are included and the number of states per simulation increase. In particular, one could make each state its own class, complete with inline functions, concrete classes with overwriting, and more. This could provide increased performance more noticble the more complex the state machine needs to be.
