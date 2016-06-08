CC=g++
CFLAGS=-Wall -g -O -std=c++11

all: mazebot
mazebot: main.o BaseRobot.o MyRobot1.o bobby.o chantal.o MazeManager.o Maze.o 
		${CC} ${CFLAGS} -o mazebot main.o BaseRobot.o MyRobot1.o bobby.o chantal.o MazeManager.o Maze.o  
main.o: main.cpp Maze.h 
		${CC} ${CFLAGS} -c main.cpp
BaseRobot.o: BaseRobot.cpp BaseRobot.h
		${CC} ${CFLAGS} -c BaseRobot.cpp
MyRobot1.o: MyRobot1.cpp MyRobot1.h
		${CC} ${CFLAGS} -c MyRobot1.cpp
bobby.o: bobby.cpp bobby.h
		${CC} ${CFLAGS} -c bobby.cpp
chantal.o: chantal.cpp chantal.h
		${CC} ${CFLAGS} -c chantal.cpp
MazeManager.o: MazeManager.cpp MazeManager.h
		${CC} ${CFLAGS} -c MazeManager.cpp
Maze.o: Maze.cpp Maze.h
		${CC} ${CFLAGS} -c Maze.cpp
clean:
		rm -f main.o BaseRobot.o MyRobot1.o bobby.o chantal.o MazeManager.o Maze.o 
