#include "T_Block.h"

T_Block::T_Block() {
	numBlock = 4; 
	Central_id = 1; 

	// initial block 
	block[0].first = Point{ 17, 1 };
	block[0].second = Point{ 18, 1 };
	block[1].first = Point{ 19, 1 };
	block[1].second = Point{ 20, 1 };
	block[2].first = Point{ 19, 0 };
	block[2].second = Point{ 20, 0 };
	block[3].first = Point{ 21, 1 };
	block[3].second = Point{ 22, 1 };

	// initial backbone
	backbone[0] = Point{ 18, 1 };
	backbone[1] = Point{ 19, 1 };
	backbone[2] = Point{ 19, 0 };
	backbone[3] = Point{ 20, 1 };
}

T_Block :: ~T_Block() {

}

void T_Block::setCoordinate() {
	// initial block 
	block[0].first = Point{ 17, 1 };
	block[0].second = Point{ 18, 1 };
	block[1].first = Point{ 19, 1 };
	block[1].second = Point{ 20, 1 };
	block[2].first = Point{ 19, 0 };
	block[2].second = Point{ 20, 0 };
	block[3].first = Point{ 21, 1 };
	block[3].second = Point{ 22, 1 };

	// initial backbone
	backbone[0] = Point{ 18, 1 };
	backbone[1] = Point{ 19, 1 };
	backbone[2] = Point{ 19, 0 };
	backbone[3] = Point{ 20, 1 };
}