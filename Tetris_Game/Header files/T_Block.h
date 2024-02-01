#pragma once
#ifndef T_BLOCK_H
#define T_BLOCK_H

#include "Shape.h"

class T_Block : public Shape {
public:
	T_Block(); 
	~T_Block(); 
	void setCoordinate();
};

#endif 