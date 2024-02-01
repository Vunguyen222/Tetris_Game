#include "Square_Block.h"

Square_Block::Square_Block() {
	numBlock = 4; 
	Central_id = 0; 

	// initial block 
	block[0].first = Point{ 17, 0 };
	block[0].second = Point{ 18, 0 };
	block[1].first = Point{ 19, 0 };
	block[1].second = Point{ 20, 0 };
	block[2].first = Point{ 17, 1 };
	block[2].second = Point{ 18, 1 };
	block[3].first = Point{ 19, 1 };
	block[3].second = Point{ 20, 1 };

	// initial backbone
	backbone[0] = Point{ 17, 0 }; 
	backbone[1] = Point{ 18, 0 }; 
	backbone[2] = Point{ 17, 1 };
	backbone[3] = Point{ 18, 1 };
}

Square_Block :: ~Square_Block() {

}

void Square_Block::setCoordinate() {
	// initial block 
	block[0].first = Point{ 17, 0 };
	block[0].second = Point{ 18, 0 };
	block[1].first = Point{ 19, 0 };
	block[1].second = Point{ 20, 0 };
	block[2].first = Point{ 17, 1 };
	block[2].second = Point{ 18, 1 };
	block[3].first = Point{ 19, 1 };
	block[3].second = Point{ 20, 1 };

	// initial backbone
	backbone[0] = Point{ 17, 0 };
	backbone[1] = Point{ 18, 0 };
	backbone[2] = Point{ 17, 1 };
	backbone[3] = Point{ 18, 1 };
}