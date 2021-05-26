#include <stdio.h>
#include <ostream>
#include "Robot-anm1.h"
#include <iostream>
#include <vector>

using namespace std;
// grid global variable

char grid[10][10];

Robot::Robot() {}

Robot::Robot(int xLocation, int yLocation, bool cargoBed, char load)
{
    this->xLocation = xLocation;
    this->yLocation = yLocation;
    this->cargoBed = cargoBed;
    this->load = load;
}
int Robot::getxLocation() const
{
    return xLocation;
}
void Robot::setxLocation(int xLocation)
{
    this->xLocation = xLocation;
}
int Robot::getyLocation() const
{
    return yLocation;
}
void Robot::setyLocation(int yLocation)
{
    this->yLocation = yLocation;
}
bool Robot::getcargoBed() const
{
    return cargoBed;
}
void Robot::setcargoBed(bool cargoBed)
{
    this->cargoBed = cargoBed;
}
char Robot::getLoad() const
{
    return load;
}
void Robot::setLoad(char load)
{
    this->load = load;
}

//moveto function needs more work 
bool Robot::moveTo(int lx, int ly)
{
    if ((lx <= 10) & (ly <= 10))
    {
        if (lx < xLocation)
        {
            while (lx != xLocation)
            {
                xLocation = xLocation + 1;
            }
        }

        else if (lx > xLocation)
        {
            while (lx != xLocation)
            {
                xLocation = xLocation - 1;
            }
        }

        if (ly > yLocation)
        {
            while (ly != yLocation)
            {
                yLocation = yLocation + 1;
            }
        }

        else if (ly < yLocation)
        {
            while (ly != yLocation)
            {
                yLocation = yLocation - 1;
            }
        }

        return true;

    }
    else 
        return false;
}



//pickup function//
bool Robot::pickUp(int lx, int ly)
{
    if (grid[lx][ly] != '.' && cargoBed == false && load == '.')
    {
        moveTo(lx, ly);
        load = grid[lx][ly];
        cargoBed = true;
        grid[lx][ly] = '.';
        return true;
    }
    else
        return false;
}


//drop off function here//
bool Robot::dropOff(int lx, int ly)
{
    if (grid[lx][ly] == '.' && cargoBed == true && load != '.')
    {
        moveTo(lx, ly);
        grid[lx][ly] = load;
        cargoBed = false;
        return true;
    }
    else 
        return false;
}


//print grid function
void print2D()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

ostream& operator<<(ostream& out, Robot& robot)
{
    out << "(" << robot.getxLocation() << ", " << robot.getyLocation() << ") :" << robot.getLoad() << endl;
    return out;
}


//destructor//
Robot::~Robot() {}





int main()
{
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            grid[i][j] = '.';
        }
    }
   
    Robot robo1(0, 0, true, 'o');
    print2D();
    cout << endl;
    robo1.dropOff(0, 0);
    print2D();
    cout << endl;
    robo1.moveTo(3, 4);
    robo1.pickUp(0,0);
    robo1.moveTo(3, 4);
    cout << robo1;
    robo1.setcargoBed(true);
    robo1.setLoad('m');
    cout << endl;
    robo1.dropOff(3, 4);
    print2D();
    
    cout << endl;
    cout << robo1;
    cout << endl;
}
