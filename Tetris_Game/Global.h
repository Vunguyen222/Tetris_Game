#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H

#include <math.h>
#include "console.h"
#include <iostream> 
#include <conio.h>
#include <Windows.h>
#include <random>

using namespace std; 

#define MAX_BLOCK	5
#define width		40
#define height		30

struct Point {
	int x, y;
};

struct Block {
	Point first, second;
};

void PrintBlock(const Block&);
#endif