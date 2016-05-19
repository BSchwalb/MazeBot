/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Maze.h
 * Author: Benjamin
 *
 * Created on May 19, 2016, 9:06 PM
 */

#ifndef MAZE_H
#define MAZE_H


#include <iostream>

class Maze {

public:
    int getAt(int x, int y); // 0 = free, 1 = wall  - may use for trails/notes
    void setAt(int x, int y);
    int size;
    int startx, starty, endx, endy; // x & y  coordinates of start/end of maze, get this in constructor
    
private:
    int** maze = NULL;
};



#endif /* MAZE_H */

