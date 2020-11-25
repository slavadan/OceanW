#include "console.h"

void ConsoleInterface::MainMenu()
{
	bool start = true;

	int sizeX = 4;
	int sizeY = 4;
	int citizenCount = 6;

	while (start)
	{
		int choose;

		std::cout << "1.Start Game\n2.Exit" << std::endl;
		std::cin >> choose;

		system("cls");

		switch (choose)
		{
		case 1:
			std::cout << "Input field size(x, y):" << std::endl;
			std::cin >> sizeX;
			std::cin >> sizeY;
			system("cls");

			
			std::cout << "Input citizen count" << std::endl;
			std::cin >> citizenCount;
			system("cls");

			StartGame(sizeX, sizeY, citizenCount);

		break;

		case 2:
			start = false;
		break;

		default:

			std::cout << "" << std::endl;
			system("pause");
			system("cls");

		}

	}

}

void ConsoleInterface::StartGame(int sizeX, int sizeY, int citizenCount)
{
	Game game(sizeX, sizeY, citizenCount);
	
	

	int choose;
	bool start = true;

	
	while (start)
	{
		PrintField(game);
		std::cin >> choose;
		system("cls");

		switch (choose)
		{
		case 1:
			continue;
		break;

		case 2:
			start = false;
		break;

		}
	}
}

void ConsoleInterface::PrintField(Game& game)
{
	int tempSizeX = game.GetSizeX();
	int tempSizeY = game.GetSizeY();

	for (int i = 0; i < tempSizeY; i++)
	{
		for (int f = 0; f < tempSizeX; f++)
			std::cout << "-----";
		std::cout << std::endl;

		for (int m = 0; m < tempSizeX; m++)
		{
			PrintSqare(game[i][m].GetStatus());
		}

		std::cout << std::endl;
		for (int f1 = 0; f1 < tempSizeX; f1++)
			std::cout << "-----";
		std::cout << std::endl;

	}


}

void ConsoleInterface::PrintSqare(Square::STATUS squareStatus)
{
	char status = 'E';

	switch (squareStatus)
	{
	case Square::STATUS::EMPTY:
		status = ' ';
		break;

	case Square::STATUS::HALF:
		status = 'H';
		break;

	case Square::STATUS::FULL:
		status = 'F';
		break;
	}

	std::cout << "| " << status << " |";
}
