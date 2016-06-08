/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Benjamin Schwalb and Valentin Sagl
 *
 * Created on May 19, 2016, 9:04 PM
 */


#include "MazeManager.h"
#include "BaseRobot.h"
#include "MyRobot1.h"
#include "chantal.h"
#include "bobby.h"
#include <sstream>
#include <thread>

using namespace std;

void fight_();

MazeManager mazeManager;

int main(int argc, char** argv) {

    mazeManager.addMaze("maze1_small.txt");
    mazeManager.addMaze("maze2_unicursal.txt");
    mazeManager.addMaze("maze3_braid.txt");
    mazeManager.addMaze("maze4_braid.txt");
    mazeManager.addMaze("maze5_cavern.txt");

    BaseRobot *robot1;


    bool fight = false;
    char input =' ';

    while(input != 'q') {

        cout << "1) My Robot " << endl << "2) Chantal" << endl << "3) Bobby" << endl << "4) Deathmatch" << endl << endl;
        cout << "Which Robot do you want to use? ";


        cin >> input;
        string name;

        switch(input) {
            case '1':
                robot1 = new MyRobot1();
                name = "MyRobot1";
                break;
            case '2':
                robot1 = new chantal();
                name = "Chantal";
                break;
            case '3':
                robot1 = new bobby();
                name = "Bobby";
                break;
            case '4':
                fight = true;
                fight_();
                break;
            case 'n':
                return 0;
                break;

        }

        if(!fight && input != 'q') {

            cout << endl << endl << "Which maze do you want to load? (0-4) ";
            cin >> input;

            int inmaze = input - '0';

            cout << endl << endl;

            mazeManager.printMaze(inmaze);
            robot1->loadMaze(mazeManager.loadMaze(inmaze));
            robot1->solve();
            cout << name << " running through Maze " << inmaze << ": Turns: " << robot1->getStats() << endl;

            cout << endl << endl << endl;
        }
    }

        return 0;
}



void fight_() {
    MyRobot1 myRobot;
    chantal chantal;
    bobby bobby;

    vector<vector<int>> stats;

    vector<int> v;
    stats.push_back(v);
    stats.push_back(v);
    stats.push_back(v);

    for(int i = 0; i <= 4; i++) {

        /*
        myRobot.loadMaze(mazeManager.loadMaze(i));
        thread t1(myRobot.solve());

        chantal.loadMaze(mazeManager.loadMaze(i));
        thread t2(chantal.solve());

        bobby.loadMaze(mazeManager.loadMaze(i));
        thread t3(bobby.solve());


        myRobot.loadMaze(mazeManager.loadMaze(i));
        thread t1(myRobot.solve());

        myRobot.loadMaze(mazeManager.loadMaze(i));
        thread t1(myRobot.solve());

        myRobot.loadMaze(mazeManager.loadMaze(i));
        thread t1(myRobot.solve());


        t1.join();
        t2.join();
        t3.join();

        */

        myRobot.loadMaze(mazeManager.loadMaze(i));
        myRobot.solve();

        chantal.loadMaze(mazeManager.loadMaze(i));
        chantal.solve();

        bobby.loadMaze(mazeManager.loadMaze(i));
        bobby.solve();



        stats[0].push_back(myRobot.getStats());
        stats[1].push_back(chantal.getStats());
        stats[2].push_back(bobby.getStats());
    }

    cout << endl << "Fight Results: " << endl;

    for(int i = 0; i <= 4; i++) {
        cout << endl << "Maze " << i << ": " << endl;
        cout << "MyRobot: " << stats[0][i] << " turns!" << endl;
        cout << "chantal: " << stats[1][i] << " turns!" << endl;
        cout << "bobby: " << stats[2][i] << " turns!" << endl;
    }


            cout << endl << endl << endl;
}
