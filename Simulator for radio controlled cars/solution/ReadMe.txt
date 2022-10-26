==Simulator for radio controlled cars==

This code was written and compiled in Visual Studio Code.

I assume the user do not need a way to stop the program from within the program itself, but can just exit the consol.

When more than one input is requested at one line by the program, any whitespace is ok (the instruction just said 'space').

I am assuming "rotate" means only rotation and not rotation and forward movement.

It is mentioned that the program may be used for other types of cars in the future, I am assuming that the main way the other cars will be different is in their movement. 
That is why there is a car class and then a child class monster_truck that handles movement simulation based on commands. In a different car, sending a F (Forward) might move the car two meters ahead. That can be handled in it's own child class.

Author: Johanna Julén 2020