#pragma once
#include "../UI.h"
#include <iostream>


class ConsoleInterface : public UserInterface
{
public:



	void MainMenu() override;
	void StartGame(int sizeX, int sizeY, int citizenCount = 6);
	
	void PrintSqareInfo(int coordX, int coordY)
	{


	}
	
private:

	void PrintField(Game& game);

	void PrintSqare(Square::STATUS squareStatus);



};