#pragma once
#ifndef I_BLOCK_H
#define I_BLOCK_H

#include "Shape.h"

class I_Block : public Shape {
public : 
	I_Block(); 
	~I_Block(); 
	void setCoordinate(); 
};

#endif // !I_BLOCK_H
