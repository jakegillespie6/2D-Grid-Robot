#include <stdio.h>
#include "Robot.h"
#include <iostream>
#include <vector>
using namespace std;

char grid [10][10];

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
bool Robot::moveTo(int lx, int ly)// char grid[10][10])
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



//pickup funcion//
bool Robot::pickUp(int lx, int ly)
{
    if (grid[lx][ly] != '.' && cargoBed == false && load == '.')
    {
        moveTo(lx,ly);
        load = grid[lx][ly];
        cargoBed = true;
        grid[lx][ly]= '.';
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
           load='.';//fix
           return true;
       }
       else
           return false;
}
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
Robot::~Robot(){}
void initialize2D()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            grid[i][j]='.';
        }
    }
    grid[3][8]='B';
    grid[2][6]='C';
}
void clear()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (grid[i][j] != '.')
            {
                Robot R(0,0,false,'.');
                R.pickUp(i, j);
            }
        }
    }
}
bool isclear()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j<10; j++)
        {
            if (grid[i][j] != '.')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    
 
    initialize2D();
    print2D();
    Robot R1(0,0,false,'.');
    Robot R2(5,7,false,'.');
    cout << R1;
    cout << R2;
   
    print2D();
    R1.moveTo(9, 2);
    R2.moveTo(3, 4);
    cout << R1;
    cout << R2;
   
    print2D();
    R1.pickUp(3,8);
    R1.dropOff(9,9);
    R2.pickUp(2, 6);
    R2.dropOff(0, 0);
    cout << R1;
    cout << R2;
    
    print2D();
    while (!isclear())
    {
        clear();
    }
    cout << "\n";
    print2D();
    
    
    return 0;
}
