#pragma once


class Game
{
public:
	bool IsGameActiv = true;
	Game();
	void Render();
	void  MoveUnitTo(int r, int c);
	void Update();
	void UpdateAI();
	void Bullet(int r, int c);
	void Sutdown();
	~Game();
};

