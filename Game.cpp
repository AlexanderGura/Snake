// Game.cpp -- основая программа игры "Змейка"

#include <iostream>
#include <Windows.h>
#include "Field.h"
#include "List.h"

int main()
{

	Field snake(20, 10);	// Передаём размеры поля
	snake.Game();			// Запускаем игру

	return 0;
}