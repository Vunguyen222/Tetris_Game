#include "Frame.h"

Frame::Frame() {
	// alloc[i][j] present for which point has been allocated (this is block)
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			// border of frame will be allocated
			alloc[i][j] = false;

			if (j == 0 || j == width - 1) {
				alloc[i][j] = true; 
			}

			if (i == height - 1) {
				alloc[i][j] = true; 
			}

		}
	}

	// line[i] present for the number of block fill in line i 
	for (int k = 0; k < height - 1; k++) {
		line[k] = 0; 
	}
	
	highest = height - 1; 
	score = 0;
}


Frame::~Frame() {

}

bool Frame::fullLine(int index) {
	// not include 2 point of border
	return line[index] == width - 2; 
}

void Frame::setPoint(int x, int y) {
	alloc[y][x] = true;
	line[y]++; 
	if (y < highest) highest = y; 
}

void Frame::lineUpdate() {
	for (int i = 0; i < height - 1; i++) {
		if (fullLine(i)) {
			// go through all block in this line
			for (int j = 1; j < width - 1; j++) {
				for (int k = i; k > 0; k--) {
					alloc[k][j] = alloc[k - 1][j];
				}
				alloc[0][j] = false; 
			}

			// line update
			for (int k = i; k > 0; k--) {
				line[k] = line[k - 1];
			}
			line[0] = 0;
			highest++;
			score += 10;
		}
	}
}


void Frame::printBorder() {
	for (int i = 0; i < width; i++) {
		gotoXY(i, height - 1);
		cout << "-";
	}
	for (int i = 0; i < height - 1; i++) {
		gotoXY(0, i);
		cout << "|";
		gotoXY(width - 1, i);
		cout << "|";
	}
}

void Frame::printBlock() {
	bool toggle = 1; 
	for (int i = 0; i < height - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			if (alloc[i][j] == true) {
				gotoXY(j, i);
				(toggle == 1) ? cout << "[" : cout << "]"; 
				toggle = 1 - toggle;
			}
		}
	}
}

bool Frame::isAllocated(int x, int y) {
	return alloc[y][x];
}

int Frame::Height() { return highest; }

void Frame::Reset() {
	// alloc[i][j] present for which point has been allocated (this is block)
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			// border of frame will be allocated
			alloc[i][j] = false;

			if (j == 0 || j == width - 1) {
				alloc[i][j] = true;
			}

			if (i == height - 1) {
				alloc[i][j] = true;
			}

		}
	}

	// line[i] present for the number of block fill in line i 
	for (int k = 0; k < height - 1; k++) {
		line[k] = 0;
	}

	highest = height - 1;
	score = 0;
}

int Frame::Score() { return score; }