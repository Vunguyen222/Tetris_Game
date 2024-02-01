#pragma once
#ifndef S_BLOCK_H
#define S_BLOCK_H

#include "Shape.h"

class S_Block : public Shape {
public : 
	S_Block(); 
	~S_Block(); 
	void setCoordinate(); 
};

#endif // !S_BLOCK_H
