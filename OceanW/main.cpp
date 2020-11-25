#include "UI/console.h"

void Display(UserInterface* GUI)
{
	GUI->MainMenu();
}

int main()
{
	UserInterface* UI = new ConsoleInterface();
	Display(UI);

	return 0;
}