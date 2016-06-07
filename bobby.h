#ifndef BOBBY_H
#define BOBBY_H

#include "BaseRobot.h"


class bobby : public BaseRobot
{
    public:

    bool schlendern(int x, int y);
    int solve();

    protected:
        int dir; //0 down, then clockwise since start is always on top
    private:
};

#endif // BOBBY_H
