#pragma once
#include "../UI.h"
#include <typeinfo>
#include <iostream>


class ConsoleInterface : public UserInterface
{
public:

	void MainMenu() override;
	void StartGame(int sizeX, int sizeY, int citizenCount = 6);
	
	void PrintSquareInfo(Square& square);
private:

	void PrintField(Game& game);

	void PrintSquare(Square::STATUS squareStatus);


};