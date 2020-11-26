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

	Vector2 coords;
	Citizen::Direction direction;
	

	while (start)
	{
		PrintField(game);

		std::cout << "1.Choose Citizen\n2.Next Turn\n3.Exit" << std::endl;
		std::cin >> choose;
		system("cls");

		PrintField(game);
		switch (choose)
		{
		case 1:
			std::cout << "Choose Square(input coordX, coordY)" << std::endl;
			std::cin >> coords.x;
			std::cin >> coords.y;

			game.SelectSquare(coords.x, coords.y);
			system("cls");

			PrintField(game);
			PrintSquareInfo(*game.selectedSquare);

			std::cout << "Choose Citizen" << std::endl;
			std::cin >> choose;
			system("cls");

			game.SelectCitizen(*game.selectedSquare, choose);
			PrintField(game);

			if (game.selectedCitizen == nullptr)
			{
				std::cout << "Error" << std::endl;
				system("pause");
				system("cls");
				break;
			}

			std::cout << "1.Move" << std::endl;
			std::cin >> choose;
			system("cls");

			PrintField(game);
			if(choose)
			{

				std::cout << "Choose direction:\n1.UP\n2.DOWN\n3.LEFT\n4.RIGHT" << std::endl;
				std::cin >> choose;

				switch (choose)
				{
				case 1:
					direction = Citizen::Direction::UP;
				break;

				case 2:
					direction = Citizen::Direction::DOWN;
				break;

				case 3:
					direction = Citizen::Direction::LEFT;
				break;

				case 4:
					direction = Citizen::Direction::RIGHT;
				break;
				}
			}
			
			game.selectedCitizen->Move(direction);
			

		break;

		case 2:
			game.EndTurn();
		break;

		case 3:
			start = false;
		break;
		}
	}
}

void ConsoleInterface::PrintSquareInfo(Square& square)
{
	for (int i = 0; i < 4; i++)
	{
		if (square[i] == nullptr)
			continue;

		if (square.GetID(i) == 1)
			std::cout << i << ".Plankton" << std::endl;
		else if (square.GetID(i) == 2)
			std::cout << i <<".Shark" << std::endl;
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
			PrintSquare(game[i][m].GetStatus());
		}

		std::cout << std::endl;
		for (int f1 = 0; f1 < tempSizeX; f1++)
			std::cout << "-----";
		std::cout << std::endl;

	}


}

void ConsoleInterface::PrintSquare(Square::STATUS squareStatus)
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