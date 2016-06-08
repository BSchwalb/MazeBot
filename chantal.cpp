#include "chantal.h"

bool chantal::flanieren(int x, int y)
{


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
            turns++;
            flanieren(x,y);
        }
        else
        {
            if(maze.getAtC(x+1,y)!='#')
            {
                x++;
                turns++;
                flanieren(x,y);
            }

            else{
                dir=3;
                flanieren(x,y);
            }
        }
        break;

    case 1:
        if(maze.getAtC(x-1,y)!='#')
        {
            dir=2;
            x--;
            turns++;
            flanieren(x,y);
        }
        else
        {
            if(maze.getAtC(x,y-1)!='#')
            {
                y--;
                turns++;
                flanieren(x,y);
            }
            else{
                dir--;
                flanieren(x,y);
            }
        }
        break;

    case 2:
        if(maze.getAtC(x,y+1)!='#')
        {
            dir=3;
            y++;
            turns++;
            flanieren(x,y);
        }
        else
        {
            if(maze.getAtC(x-1,y)!='#')
            {
                x--;
                turns++;
                flanieren(x,y);
            }
            else{
                dir--;
                flanieren(x,y);
            }
        }
        break;

    case 3:
        if(maze.getAtC(x+1,y)!='#')
        {
            dir=0;
            x++;
            turns++;
            flanieren(x,y);
        }
        else
        {
            if(maze.getAtC(x,y+1)!='#')
            {
                y++;
                turns++;
                flanieren(x,y);
            }
            else{
                dir--;
                flanieren(x,y);
            }
        }
        break;

    default:
        cout << "DEFAULT SWITCH ERROR LEL" << endl;
        break;

    }
}

void chantal::findD()
{
    int redoflag=0;
    for(int i = 1; i < maze.size-2; i++)
    {
        for(int j = 1; j < maze.maze[i].size()-1; j++)
        {
            int bordercount=0;
            if(maze.getAtC(i,j)==' ')
            {
                if(maze.getAtC(i+1,j)=='#')
                {
                    bordercount++;
                }
                if(maze.getAtC(i-1,j)=='#')
                {
                    bordercount++;
                }
                if(maze.getAtC(i,j+1)=='#')
                {
                    bordercount++;
                }
                if(maze.getAtC(i,j-1)=='#')
                {
                    bordercount++;
                }
                if(bordercount==3)
                {
                    maze.setAt(i,j,1);
                    redoflag++;
                }
            }

        }
    }
    if(redoflag>0){
        findD();
    }
    else{
       /* for(int i = 0; i < maze.size; i++) {
        for(int j = 0; j < maze.maze[i].size(); j++) {
            cout << maze.getAtC(i, j);
        }
        cout << endl;
        }
        * */

        flanieren(maze.startx,maze.starty);
    }
}

int chantal::solve(){
    dir = 0;
    turns=0;
    findD();
    return turns;
}
