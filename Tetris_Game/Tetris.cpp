#include "S_Block.h"
#include "Z_Block.h"
#include "I_Block.h"
#include "J_Block.h"
#include "L_Block.h"
#include "Square_Block.h"
#include "T_Block.h"
#include "Global.h"
#include "Frame.h"

/*-----------------Define object-------------------*/
#define		win		1
#define		lose	2
#define		exit	3

/*----------------Global variable-------------------*/
// 7 Shape in tetris game
S_Block s;
I_Block i; 
Z_Block z; 
J_Block j; 
L_Block l; 
Square_Block square; 
T_Block t; 
Frame frame;
Shape* shape;

// random device
random_device rd;
mt19937 rng(rd());
uniform_int_distribution<int> uni(1, 7);

// flag variable 
bool newTurn;
bool isSquare;
bool down;

// other variable
int target_Score;
int gameOver;
/*------------------Function-------------------------*/

void Instruction() {
	clrscr();
	cout << "Play Game\n";
	cout << "Instruction  <------\n";
	cout << "\tBased on the classic Tetris game and nothing new, player have to follow some rules :\n";
	cout << "\t- There are 7 shape in this game including : I, J, L, S, Square, T and Z block\n";
	cout << "\t- They always fall down and cannot be controlled upward\n";
	cout << "\t- If one line is full, it will be deleted and your score will be added 10 point\n";
	cout << "\t- Your goal is to reach the target point so that win this game. Therefore, try your best\n";
	cout << "\tto remove the lines as much as possible\n";
	cout << "\t- Otherwise, if you stack the shape to the maximum height, you will lose the game, of course :))\n";
	cout << "\t- Some functions we provided are :\n";
	cout << "\t\t a/d : to move left/right\n";
	cout << "\t\t w/s : to rotate counterclockwise/clockwise\n";
	cout << "\t\t Space : to pause the game\n";
	cout << "\t\t Enter : to drop down the shape immediately\n";
	cout << "\t\t Esc : to exit game\n";
	cout << "\tNo matter who you are, as long as you participate in this game, you have to put in a lot of effort\n";
	cout << "\tbecause this game is not easy. However, whether your result is victory or defeat, you deserve to be\n";
	cout << "\tincluded in our list of talented players.\n";
	cout << "\t\tGood luck !!!\n";
	cout << "Exit\n";
	system("pause");
}

void generateShape() {
	int shape_id ;
	shape_id = uni(rng);
	switch (shape_id)
	{
	case 1:
		shape = &s;
		break;
	case 2:
		shape = &i;
		break;
	case 3:
		shape = &j;
		break;
	case 4:
		shape = &z;
		break;
	case 5:
		shape = &l;
		break;
	case 6:
		shape = &square;
		isSquare = true;
		break;
	case 7:
		shape = &t;
		break;
	default:
		break;
	}
	shape->setCoordinate();
}

void Display() {
	frame.printBorder();
	frame.printBlock(); 
	shape->printShape();

	// print target score
	gotoXY(42, 10);
	cout << "TARGET SCORE";
	gotoXY(42, 11);
	cout << target_Score;

	// print your score
	gotoXY(42, 16);
	cout << "YOUR SCORE";
	gotoXY(42, 17);
	cout << frame.Score();

}

void Control() {
	// press enter and the shape will fall down immediatetly - can not control 
	if (down) return;
	if (_kbhit()) {
		char key = _getch();
		switch (key)
		{
		case 'w':
			// rotate counter-clockwise except square
			if (isSquare) return;
			shape->counterRotate();
			// rotate in narrow spaces
			for (int i = 0; i < shape->numBlock; i++) {
				if (frame.isAllocated(shape->block[i].first.x, shape->block[i].first.y)
				|| frame.isAllocated(shape->block[i].second.x, shape->block[i].second.y)) {
					shape->clockRotate();
					return;
				}
			}
			break;
		case 's':
			// rotate clockwise except square
			if (isSquare) return;
			shape->clockRotate();
			// rotate in narrow spaces
			for (int i = 0; i < shape->numBlock; i++) {
				if (frame.isAllocated(shape->block[i].first.x, shape->block[i].first.y)
				|| frame.isAllocated(shape->block[i].second.x, shape->block[i].second.y)) {
					shape->counterRotate();
					return;
				}
			}
			break;
		case 'a':
			// move left
			// if shape is at the end of left border
			// or if left of shape is block
			for (int i = 0; i < shape->numBlock; i++) {
				if (frame.isAllocated(shape->block[i].first.x - 1, shape->block[i].first.y)) {
					return;
				}
			}
			// is valid, allow move left
			for (int i = 0; i < shape->numBlock; i++) {
				// move with distance equal 1 block
				shape->block[i].first.x -= 2;
				shape->block[i].second.x -= 2;
				shape->backbone[i].x -= 2;
			} 
			break;
		case 'd':
			// move right 
			// if shape is at the end of the right border
			// or if right of shape is block
			for (int i = 0; i < shape->numBlock; i++) {
				if (frame.isAllocated(shape->block[i].second.x + 1, shape->block[i].second.y)) {
					return;
				}
			}
			for (int i = 0; i < shape->numBlock; i++) {
				// move with distance equal 1 block
				shape->block[i].first.x += 2;
				shape->block[i].second.x += 2;
				shape->backbone[i].x += 2;
			}
			break;
		case 32: // space
			system("pause");
			break;
		case 13: // enter
			down = true;
			break;
		case 27: // esc
			gameOver = exit;
			break;
		default:
			break;
		}
		
	}
}

void Process() {
	bool setpoint = false;
	// reach the block below
	for (int i = 0; i < shape->numBlock; i++) {
		if (!setpoint) {
			if (frame.isAllocated(shape->block[i].first.x, shape->block[i].first.y + 1)
				|| frame.isAllocated(shape->block[i].second.x, shape->block[i].second.y + 1)) {
				setpoint = true;
				// back to first block
				i = -1;
			}
		}
		else {
			frame.setPoint(shape->block[i].first.x, shape->block[i].first.y);
			frame.setPoint(shape->block[i].second.x, shape->block[i].second.y);
		}
	}

	if (setpoint) {
		// generate new shape, reset isSquare
		newTurn = true;
		isSquare = false;
		// reset down
		down = false;
	}

	//full line, delete line
	frame.lineUpdate();

	// win game ? 
	if (frame.Score() == target_Score) gameOver = win;

	//game over - gameOver game ? 
	if (frame.Height() == 0) gameOver = lose ;
}

void Dropdown() {
	for (int i = 0; i < shape->numBlock; i++) {
		shape->block[i].first.y++;
		shape->block[i].second.y++;
		shape->backbone[i].y++;
	}
}

void playGame() {
	// determine new turn
	newTurn = true;
	gameOver = 0;
	isSquare = false;
	down = false;
	target_Score = 1000;

	// the players neither win nor gameOver -- they are playing game
	while (!gameOver) {
		clrscr();
		// khoi tao 
		if (newTurn) {
			generateShape();
			newTurn = false;
		}
		// hien thi 
		Display(); 
		// dieu khien
		Control();
		// xu ly
		Process();
		Dropdown();
		if (!down) {
			Sleep(200);
		}
		else {
			Sleep(10);
		}
	}

	clrscr();
	gotoXY(15, 15);
	if (gameOver == win) {
		cout << "Congratulations !! You have won this game :))";
	}
	else if(gameOver == lose) {
		cout << "So sorry !! You lost this game :((";
	}
	else {
		cout << "Good bye !! See you soon <3";
	} 
	Sleep(2500);
	frame.Reset();
}


int main() {
	int option = 0; 
	while (true) {
		clrscr();
		if (option == 0) {
			cout << "Play Game    <------\n"; 
			cout << "Instruction\n"; 
			cout << "Exit\n"; 
		}
		else if (option == 1) {
			cout << "Play Game\n";
			cout << "Instruction  <------\n";
			cout << "Exit\n";
		}
		else {
			cout << "Play Game\n";
			cout << "Instruction\n";
			cout << "Exit         <------\n";
		}

		if (_kbhit()) {
			char character = _getch();
			if (character == 'w' || character == 'W') {
				option--;
				if (option < 0) option = 0;
			}
			else if (character == 's' || character == 'S') {
				option++;
				if (option > 2) option = 2;
			}
			else if (character == 13) {
				if (!option) playGame();
				else if (option == 1) Instruction();
				else break;
			}
			else {
				cout << "\nPlease choose your option \n";
				Sleep(2000);
			}
		}
		Sleep(200);
	}
	return 0; 
}