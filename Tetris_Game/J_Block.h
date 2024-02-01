#pragma once
#ifndef J_BLOCK_H
#define J_BLOCK_H
#include "Shape.h"

class J_Block : public Shape {
public : 
	J_Block(); 
	~J_Block(); 
	void setCoordinate(); 
};

#endif