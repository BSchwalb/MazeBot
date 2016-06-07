

#ifndef BASEROBOT_C
#define BASEROBOT_C
#include "BaseRobot.h"

using namespace std;

int BaseRobot::solve() {
    return 999999;
}


void BaseRobot::loadMaze(Maze maze) {
    this->maze = maze;
    x = maze.startx;
    y = maze.starty;
}

void BaseRobot::setPos(int x, int y) {
    maze.setAt(this->x, this->y, 0);
    this->x = x;
    this->y = y;
}

int BaseRobot::getStats() {
    return turns;
}

#endif