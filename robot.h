#include <ostream>
using namespace std;
#ifndef Robot_h
#define Robot_h


class Robot
{
    private:
    int xLocation;
    int yLocation;
    bool cargoBed;
    char load;
    
    public:
    Robot();
    Robot(int xLocation, int yLocation, bool cargoBed, char load);
    int getxLocation() const;
    void setxLocation(int xLocation);
    int getyLocation() const;
    void setyLocation(int yLocation);
    bool getcargoBed() const;
    void setcargoBed(bool cargoBed);
    char getLoad() const;
    void setLoad(char load);
    bool moveTo (int lx, int ly);
    bool pickUp (int lx, int ly);
    bool dropOff (int lx, int ly);
    friend ostream& operator<<(ostream& out, Robot& robot);
    ~Robot();
    
};
#endif
