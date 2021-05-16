# CSC252-TeamProject
Team project for Advanced C++ final
In this project you will define a Robot class and command robot objects to move to different
locations within an 10X10 grid (or board) to pickup and drop-off loads in different cells of the
grid. The loads are assumed to be characters. For simplicity we assume the grid is a global
variable. The Robot class must have the following data members


a. A private data field xLocation (an int type) : Holds the x-component of the location of
the robot object on the grid

b. A private data field yLocation(an int type) : Holds the y-component of the location of
the robot object on the grid

c. A private data field cargoBed (a bool type) : Indicates whether the robot has any cargo
(load)

d. A private data field load (a char type) : Holds the content of the load, set to character ‘.’
(a dot) when robot has no load.
The class Robot must have the following public functions:

a. A constructor that receives parameters to initialize all private date members [3pts]

b. Include get/set functions for all private data members [5pts]
2

c. The function bool MoveTo(int lx, int ly). This function checks to see whether the
location (lx, ly) is within the boundary of the grid, if not returns false. Otherwise, the
function checks the current position of the robot object at (xLocation, yLocation) then
using loops moves the robot object (one cell at a time) to the new location given by
parameters lx and ly. The robot can only move one cell at a time to its neighboring cells
on the left, right, up, or down [3 pts]

d. The function bool pickup (int lx, int ly). Invoking this function will command robot to
pick up a character (load) on the grid at location (lx, ly) and place it in its cargoBed. The
robot object must verify that there is a character load at location (lx, ly) and that the robot
has empty cargoBed. When a character is picked up, it should be removed from the grid.
If the robot is not currently at location (lx, ly), it should be moved to the specified
location first, then picking up the load. The function leaves the robot object at the pickup
location [3 pts]

e. The function bool dropOff(int lx, int ly). Invoking this function will command the robot
object to drop-off a character (load) on the grid location (lx, ly) on the grid. The robot
object must verify that there is no character at location (lx, ly) on the board and that the
robot has a character in its cargoBed to drop-off. When a character is dropped-off, it
should be removed from the cargoBed of the robot object and placed at the given
location on the board. If the robot is not currently at location (lx, ly), it should be moved
to the specified location first and then the drop-off should take place. The function leaves
the robot at the drop-off location [3pts]

f. Overload the operator “<<” for the Robot class to print the location of the robot on the
grid as well as its load, something like (5, 8) :P indicating that the robot object is at
position (5, 8) on the grid and carrying the letter ‘P’ as a load. [3pts]

g. Write a nonmember function print2D() that reveries a 2 dimensional array of characters
(the grid) and displays it in a row/column format. [10pts]

h. Write a main function to test the operation of the robot. Your program should define a 2-
dimensional array (or a vector of vectors) representing the grid char grid [10][10]. Make
this array global and initialize all the elements in the 2-dimensional array to “.”, which is
interpreted as empty cells. Then, place character ‘B’ at location (3, 8) and ‘C’ at (2, 6).
Use the print2D() function to print the grid. [5pts]

i. Create two robot objects R1 and R2, place them at a random location on the board with
no load. Print the robots. [5pts]

j. Use the moveTo() function to place R1 at location (9,2 ) and R2 at location (3, 4). Print
the robots and the board. [5pts]
3

k. Direct R1 to pick up ‘B’ at location (3, 8) and place it at location (9, 9). Print the robots
and the board [5pts]

l. Direct R2 to pick up ‘C’ at location (2, 6) and place it at location (0, 0). Print the robots
and the board [5pts]

m. Write a nonmember function clear() that receives a 2-dimentional array of character type
(the grid) with a void return type. The function traverses through all the elements of the
array and if it finds a character at any location (i, j) on the board, it should dynamically
create a Robot object, set the robot at that location where the character is located and pick
up the load. When this task is done the robot must be deleted. Call the function clear()
and pass the grid as the argument. Next the grid should be clear of all characters. Print the
grid [5pts]
