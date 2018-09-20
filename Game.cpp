#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <Conio.h>
#include "level.h"
#include "enemy.h"
#include "Hero.h"

using namespace std;

const int maxUnit = 10;
enemy Data[maxUnit];
Hero hero;


unsigned char level[x][y];

int Count;
int cristal = 0;


HANDLE consoleHand = 0;

Game::Game()
{
	consoleHand = GetStdHandle(STD_OUTPUT_HANDLE);

	Count = 0;
	for (int r = 0; r < x; r++) {
		for (int c = 0; c < y; c++) {
			unsigned char CellSymbol = level0[r][c];

			switch (CellSymbol)
			{
			case'#': level[r][c] = Symbol_Wall;
				break;
			case 'h': level[r][c] = Symbol_Hero;
				hero.x = r;
				hero.y = c;
				break;
			case'e': level[r][c] = Symbol_Exit;
				break;
			case 'o': level[r][c] = Symbol_enemy;
				Data[Count].x = r;
				Data[Count].y = c;
				Count++;
				break;
			case' ': level[r][c] = Symbol_Empty;
				break;
			}
		}
	}
}

void  Game::Render() {
	COORD cursor;
	cursor.X = 0;
	cursor.Y = 0;
	SetConsoleCursorPosition(consoleHand, cursor);

	cout << "\Money: " << cristal;
	cout << endl << "\t HP: " << hero.Health;
	cout << endl << "\t";
	for (int r = 0; r < x; r++) {
		for (int c = 0; c < y; c++) {
			unsigned char Symbol = level[r][c];
			cout << Symbol;
		}
		cout << endl << "\t";
	}
}

void Game::MoveUnitTo(int r, int c) {
	unsigned char destination = level[r][c];
	bool canMoveToCell = false;
	switch (destination)
	{
	case Symbol_Empty: canMoveToCell = true;
		break;
	case Symbol_Exit: if (cristal == Count) IsGameActiv = false;
		break;
	}
	if (canMoveToCell) {
		level[hero.x][hero.y] = Symbol_Empty;
		hero.x = r;
		hero.y = c;
		level[hero.x][hero.y] = Symbol_Hero;
	}


}

void Game::Bullet(int r, int c) {
	unsigned char destination = level[x][y];
	bool canMoveBullet = false;
	switch (destination)
	{
	case Symbol_Empty: canMoveBullet = true;
		break;
	}
	switch (Symbol_Hero)
	{
		if (canMoveBullet) {
	case '>': level[r][c + 1] = bullet;
		break;
	case '<': level[r][c - 1] = bullet;
		break;
	case '^': level[r - 1][c] = bullet;
		break;
	case 'v': level[r + 1][c] = bullet;
		break;
		}
	}
}

void Game::Update() {
	unsigned char inputChar = _getch();
	inputChar = tolower(inputChar);
	switch (inputChar) {
	case 'w':
		Symbol_Hero = '^';
		MoveUnitTo(hero.x - 1, hero.y);
		break;
	case 's':
		Symbol_Hero = 'v';
		MoveUnitTo(hero.x + 1, hero.y);
		break;
	case 'a':
		Symbol_Hero = '<';
		MoveUnitTo(hero.x, hero.y - 1);
		break;
	case 'd':
		Symbol_Hero = '>';
		MoveUnitTo(hero.x, hero.y + 1);
		break;
	case 'q':
		Bullet(hero.x, hero.y);

		break;
	}

	int DistinalX[maxUnit];
	int DistinalY[maxUnit];
	for (int i = 0; i < Count; i++) {
		DistinalX[i] = abs(Data[i].x - hero.x);
		DistinalY[i] = abs(Data[i].y - hero.y);

		if ((DistinalX[i] + DistinalY[i]) == 1) {
			Data[i].health = Data[i].health - hero.Damage;
			if (Data[i].health <= 0) {
				level[Data[i].x][Data[i].y] = Symbol_crystal;

				level[Data[i].x][Data[i].y] = Symbol_Empty;
				Data[i].x = 0;
				Data[i].y = 0;
				cristal++;

			}

		}
	}
}



void Game::Sutdown() {
	system("cls");
	cout << endl << "\t" << "|||Game over!!!|||" << endl;
	system("pause");
}

Game::~Game()
{


}
