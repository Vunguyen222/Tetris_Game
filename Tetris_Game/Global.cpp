#include "Global.h"

void PrintBlock(const Block& blk) {
	gotoXY(blk.first.x, blk.first.y);
	std::cout << "[";
	gotoXY(blk.second.x, blk.second.y);
	std::cout << "]";
}