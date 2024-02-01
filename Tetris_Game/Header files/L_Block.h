#pragma once
#ifndef L_BLOCK_H
#define L_BLOCK_H
#include "Shape.h"

class L_Block : public Shape {
public: 
	L_Block(); 
	~L_Block(); 
	void setCoordinate();
};

#endif