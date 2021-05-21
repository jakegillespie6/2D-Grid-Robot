#include <stdio.h>
#include "Robot.h"

Robot::Robot(){}
Robot:: Robot(int xLocation, int yLocation, bool cargoBed, char load)
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

//moveto function here//
bool Robot::moveTo(int lx, int ly, char grid[10][10])
{
    
}



//pickup funcion//
bool Robot::pickUp(int lx, int ly, char grid[10][10])
{
    if (grid[lx][ly] != '.' && cargoBed == false && load == '.')
    {
        moveTo(lx,ly,grid);
        load = grid[lx][ly];
        cargoBed = true;
        grid[lx][ly]= '.';
        return true;
    }
    return false;
}


//drop off function here//
bool Robot::dropOff(int lx, int ly, char grid[10][10])
{
    
}


//destructor//
Robot::~Robot(){}
