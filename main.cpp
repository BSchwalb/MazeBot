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
#include "BaseRobot.h"
#include "MyRobot1.h"

using namespace std;

MazeManager mazeManager;

int main(int argc, char** argv) {

    mazeManager.addMaze("maze1_small.txt");
    mazeManager.addMaze("maze2_unicursal.txt");
    mazeManager.addMaze("maze3_braid.txt");
    mazeManager.addMaze("maze4_braid.txt");
    mazeManager.addMaze("maze5_cavern.txt");
    
    MyRobot1 myRobot1;
    
    mazeManager.printMaze(0);
    myRobot1.loadMaze(mazeManager.loadMaze(0));
    myRobot1.solve();
    cout << "MyRobot1: Maze 1: Turns: " << myRobot1.getStats() << endl;
    
    mazeManager.printMaze(4);
    myRobot1.loadMaze(mazeManager.loadMaze(4));
    myRobot1.solve();
    cout << "MyRobot1: Maze 4: Turns: " << myRobot1.getStats() << endl;
    
    
    return 0;
}

