/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyRobot1.h
 * Author: Benjamin
 *
 * Created on 07. Juni 2016, 17:33
 */

#ifndef MYROBOT1_H
#define MYROBOT1_H
#include "BaseRobot.h"
#include <vector>

struct point {
  int x;
  int y;
} ;

class MyRobot1 : public BaseRobot {
    public:
    int solve();
    bool solve(int, int);
    bool contains(int, int);
    vector<point> visited;
    
};


#endif /* MYROBOT1_H */

