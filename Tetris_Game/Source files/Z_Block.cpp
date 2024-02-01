#include "Z_Block.h"

Z_Block::Z_Block() {
	numBlock = 4;
	Central_id = 2;

	// initial block 
	block[0].first = Point{ 17, 0 };
	block[0].second = Point{ 18, 0 };
	block[1].first = Point{ 19, 0 };
	block[1].second = Point{ 20, 0 };
	block[2].first = Point{ 19, 1 };
	block[2].second = Point{ 20, 1 };
	block[3].first = Point{ 21, 1 };
	block[3].second = Point{ 22, 1 };

	// initial backbone
	backbone[0] = Point{ 18, 0 };
	backbone[1] = Point{ 19, 0 };
	backbone[2] = Point{ 19, 1 };
	backbone[3] = Point{ 20, 1 };
}

Z_Block::~Z_Block() {

}

void Z_Block::setCoordinate() {
	// initial block 
	block[0].first = Point{ 17, 0 };
	block[0].second = Point{ 18, 0 };
	block[1].first = Point{ 19, 0 };
	block[1].second = Point{ 20, 0 };
	block[2].first = Point{ 19, 1 };
	block[2].second = Point{ 20, 1 };
	block[3].first = Point{ 21, 1 };
	block[3].second = Point{ 22, 1 };

	// initial backbone
	backbone[0] = Point{ 18, 0 };
	backbone[1] = Point{ 19, 0 };
	backbone[2] = Point{ 19, 1 };
	backbone[3] = Point{ 20, 1 };
}