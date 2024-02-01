#pragma once
#ifndef FRAME_H
#define FRAME_H
#include "Global.h"

class Frame {
private : 
	bool alloc[height][width];
	int line[height - 1];
	// highest point of frame, check game over or not
	int highest;
	// score of player
	int score;
public : 
	// constructor
	Frame(); 
	// destructor
	~Frame(); 
	// check if block fullfill the line
	bool fullLine(int);
	// delete all blocks that fullfill the line and do nothing if they dont
	void lineUpdate();
	void setPoint(int, int); 
	void printBorder();
	void printBlock();
	bool isAllocated(int, int);
	int Height();
	void Reset();
	int Score();
};



#endif