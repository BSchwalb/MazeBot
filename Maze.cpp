



#ifndef MAZE_C
#define MAZE_C
#include "Maze.h"


int Maze::getAt(int x, int y) {
    return maze[x][y];
}

char Maze::getAtC(int x, int y) {
    int pos = maze[x][y];
    if(pos == 0)
        return free;
    if(pos == 1) 
        return wall;
}

void Maze::setAt(int x, int y, int value) {
    maze[x][y] = value;
}

void Maze::addLine(vector<int> line) {
    maze.push_back(line);
    size++;
}

#endif