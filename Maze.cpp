



#ifndef MAZE_C
#define MAZE_C
#include "Maze.h"

Maze::Maze(int size) {
    this->size = size;
    
    for(int i = 0; i < size; i++) {
        vector t;
        maze.push_back(t);
    }
}

Maze::getAt(int x, int y) {
    return maze[x][y];
}

Maze::setAt(int x, int y, int value) {
    maze[x][y] = value;
}

#endif