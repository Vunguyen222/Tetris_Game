#include "I_Block.h"

I_Block::I_Block() {
	numBlock = 4;
	Central_id = 2;

	// initial block 
	block[0].first = Point{ 15, 0 };
	block[0].second = Point{ 16, 0 };
	block[1].first = Point{ 17, 0 };
	block[1].second = Point{ 18, 0 };
	block[2].first = Point{ 19, 0 };
	block[2].second = Point{ 20, 0 };
	block[3].first = Point{ 21, 0 };
	block[3].second = Point{ 22, 0 };

	// initial backbone
	backbone[0] = Point{ 17, 0 };
	backbone[1] = Point{ 18, 0 };
	backbone[2] = Point{ 19, 0 };
	backbone[3] = Point{ 20, 0 };
}

void I_Block::setCoordinate() {
	// initial block 
	// initial block 
	block[0].first = Point{ 15, 0 };
	block[0].second = Point{ 16, 0 };
	block[1].first = Point{ 17, 0 };
	block[1].second = Point{ 18, 0 };
	block[2].first = Point{ 19, 0 };
	block[2].second = Point{ 20, 0 };
	block[3].first = Point{ 21, 0 };
	block[3].second = Point{ 22, 0 };

	// initial backbone
	backbone[0] = Point{ 17, 0 };
	backbone[1] = Point{ 18, 0 };
	backbone[2] = Point{ 19, 0 };
	backbone[3] = Point{ 20, 0 };
}


I_Block :: ~I_Block() {}