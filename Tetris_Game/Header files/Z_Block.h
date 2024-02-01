#pragma once
#ifndef Z_BLOCK_H
#define Z_BLOCK_H
#include "Shape.h"

class Z_Block : public Shape {
public: 
	Z_Block();
	~Z_Block();
	void setCoordinate();
};

#endif // !Z_BLOCK_H
