#include "bobby.h"

bool bobby::schlendern(int x, int y)
{
    turns++;

    //cout << "X " << x << "   Y " << y << endl;
    if(y==maze.endy && x==maze.endx)
    {
        return true;
    }

    switch(dir)
    {
    case 0: //looks down therefore has to check right
        if(maze.getAtC(x,y-1)!='#')
        {
            dir=1;
            y--;
            schlendern(x,y);
        }
        else
        {
            if(maze.getAtC(x+1,y)!='#')
            {
                x++;
                schlendern(x,y);
            }

            else{
                dir=3;
                schlendern(x,y);
            }
        }
        break;

    case 1:
        if(maze.getAtC(x-1,y)!='#')
        {
            dir=2;
            x--;
            schlendern(x,y);
        }
        else
        {
            if(maze.getAtC(x,y-1)!='#')
            {
                y--;
                schlendern(x,y);
            }
            else{
                dir--;
                schlendern(x,y);
            }
        }
        break;

    case 2:
        if(maze.getAtC(x,y+1)!='#')
        {
            dir=3;
            y++;
            schlendern(x,y);
        }
        else
        {
            if(maze.getAtC(x-1,y)!='#')
            {
                x--;
                schlendern(x,y);
            }
            else{
                dir--;
                schlendern(x,y);
            }
        }
        break;

    case 3:
        if(maze.getAtC(x+1,y)!='#')
        {
            dir=0;
            x++;
            schlendern(x,y);
        }
        else
        {
            if(maze.getAtC(x,y+1)!='#')
            {
                y++;
                schlendern(x,y);
            }
            else{
                dir--;
                schlendern(x,y);
            }
        }
        break;

    default:
        cout << "DEFAULT SWITCH ERROR LEL" << endl;
        break;

    }
}



int bobby::solve()
{
    int turns = 0;
    dir=0;


    //if(!schlendern(maze.starty, maze.startx)){
    if(!schlendern(maze.startx,maze.starty)){
        cout << "DA LAEUFT WAS SCHIEF WAT?" << endl;
    }

    return turns;

}

