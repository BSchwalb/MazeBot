/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Benjamin
 *
 * Created on May 19, 2016, 9:04 PM
 */

#include <cstdlib>

#include "MazeManager.h"

using namespace std;

MazeManager mazeManager;

int main(int argc, char** argv) {

    mazeManager.addMaze("maze1_small.txt");
    mazeManager.printMaze(0);
    
    return 0;
}

