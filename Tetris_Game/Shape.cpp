#include "Shape.h"

Shape::Shape() {
	numBlock = 0;
	Central_id = 0;
	for (int i = 0; i < MAX_BLOCK; i++) {
		block[i].first = Point{ 0,0 };
		block[i].second = Point{ 0,0 };
		backbone[i] = Point{ 0,0 };
	}
}

/*Rotate backbone and then rotate block too*/
void Shape::Rotate(int degree) {
	for (int i = 0; i < numBlock; i++) {
		if (i != Central_id) {
			int x = backbone[i].x; 
			int y = backbone[i].y; 
			int x0 = backbone[Central_id].x; 
			int y0 = backbone[Central_id].y; 

			// rotate left or right
			switch (degree)
			{
			case 90:
				backbone[i].x = -(y - y0) + x0; 
				backbone[i].y = (x - x0) + y0; 
				break;
			default:
				backbone[i].x = (y - y0) + x0; 
				backbone[i].y = -(x - x0) + y0; 
				break;
			}

			// adjust coordinate of block but remain the coordinate of backbone, central point not changed
			block[i].first.x = backbone[i].x + (backbone[i].x - backbone[Central_id].x);
			block[i].first.y = backbone[i].y;

			block[i].second.x = block[i].first.x + 1; 
			block[i].second.y = block[i].first.y; 
		}
	}
}

void Shape::clockRotate() {
	Rotate(90);
}

void Shape::counterRotate() {
	Rotate(-90);
}

void Shape::printShape() {
	for (int i = 0; i < numBlock; i++) {
		PrintBlock(block[i]);
	}
}

void Shape::setCoordinate() {
	for (int i = 0; i < MAX_BLOCK; i++) {
		block[i].first = Point{ 0,0 };
		block[i].second = Point{ 0,0 };
		backbone[i] = Point{ 0,0 };
	}
}

Shape :: ~Shape() {

}