#ifndef CHANTAL_H
#define CHANTAL_H

#include "BaseRobot.h"

class chantal : public BaseRobot
{
    public:

    bool flanieren(int x, int y);
    int solve();
    void findD();
    protected:
        int dir=0;
    private:
};

#endif // CHANTAL_H
