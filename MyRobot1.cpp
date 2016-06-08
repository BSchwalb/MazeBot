/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef MYROBOT1_C
#define MYROBOT1_C
#include "MyRobot1.h"

int MyRobot1::solve() {
    turns = 0;
 
    visited.clear();
    
    solve(maze.startx, maze.starty);

    return turns;
}


bool MyRobot1::solve(int nx, int ny) {

    turns++;
    // Make the move (if it's wrong, we will backtrack later.
    setPos(nx,ny);
    point p1;
    p1.x = nx;
    p1.y = ny;
    visited.push_back(p1);

    //cout << "Turn " << turns << ": Pos " << x << ", " << y  << endl;


    // Check if we have reached our goal.
    if (x == maze.endx && y == maze.endy)
    {
        return true;
    }

    // Recursively search for our goal.
    if (nx > 0 && maze.getAt(nx-1, ny) == 0 && !contains(nx-1, ny) && solve(nx - 1, ny))
    {
        return true;
    }
    if (nx < maze.maze[0].size() && maze.getAt(nx+1, ny) == 0 && !contains(nx+1, ny) && solve(nx + 1, ny))
    {
        return true;
    }
    if (ny > 0 && maze.getAt(nx, ny-1) == 0 && !contains(nx, ny-1) && solve(nx, ny - 1))
    {
        return true;
    }
    if (ny < maze.maze.size() && maze.getAt(nx, ny+1) == 0 && !contains(nx, ny+1) && solve(nx, ny + 1))
    {
        return true;
    }

    // Otherwise we need to backtrack and find another solution.
   return false;
}

bool MyRobot1::contains(int x, int y) {
    for(auto const& p: visited) {
        if(p.x == x && p.y == y)
            return true;
    }
    return false;
}

#endif
