#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include "Global.h"

class Shape
{
public:
	Shape();
	~Shape();
	void Rotate(int); 
	void clockRotate();		// clock-wise rotation
	void counterRotate();	// counter clock-wise rotation
	friend void PrintBlock(const Block&);
	void printShape();		
	virtual void setCoordinate();
public:
	// use to represent shape
	Block block[MAX_BLOCK];
	// use to express operator on shape
	Point backbone[MAX_BLOCK];
	// central point id
	int Central_id;
	// number of block
	int numBlock;
};
#endif // !SHAPE_H
