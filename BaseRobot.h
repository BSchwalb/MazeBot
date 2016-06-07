/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseRobot.h
 * Author: Benjamin
 *
 * Created on May 19, 2016, 9:06 PM
 */

#ifndef BASEROBOT_H
#define BASEROBOT_H

#include "Maze.h"


class BaseRobot {
   
public:
    virtual int solve();
    int getStats();
    
    void loadMaze(Maze);
    void setPos(int, int);
    
protected:
    int turns = 0;
    int x = 0, y = 0;
    Maze maze;
};


#endif /* BASEROBOT_H */

