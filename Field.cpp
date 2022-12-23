// Field.cpp -- определение методов класа Field

#include <iostream>
#include "Field.h"
#include <Windows.h>
#include "List.h"

void Field::Up()	// Движение змейки вверх по нажатию клавиши 'w'
{
	Position temp = Snake.Back();	// Сохраняем исходное положение головы змейки

	// Если измененные координаты головы змейки совпадают с координатами яблока
	if (--temp.y == Apple.y && temp.x == Apple.x)
	{
		Snake.Push(Apple);		// То добавляем звено в нашу змейку с координатами яблока
		Field::CreateApple();	// Создаём новое яблоко (старое съели)
		score++;				// Обновляем счётчик съеденных яблок
	}
	else	// Если координаты не совпали с яблоком
	{
		Snake.Push(temp);		// Добавляем новое звено с изменёнными координами
		Snake.Pop();			// Удаляем хвост змейки
	}
}

void Field::Down()	// Движение змейки вниз по нажатию клавиши 's'
{
	Position temp = Snake.Back();	// Сохраняем исходное положение головы змейки

	// Если измененные координаты головы змейки совпадают с координатами яблока
	if (++temp.y == Apple.y && temp.x == Apple.x)
	{
		Snake.Push(Apple);		// То добавляем звено в нашу змейку с координатами яблока
		Field::CreateApple();	// Создаём новое яблоко (старое съели)
		score++;				// Обновляем счётчик съеденных яблок
	}
	else	// Если координаты не совпали с яблоком
	{
		Snake.Push(temp);		// Добавляем новое звено с изменёнными координами
		Snake.Pop();			// Удаляем хвост змейки
	}
}

void Field::Right()	// Движение змейки вправо по нажатию клавиши 'd'
{
	Position temp = Snake.Back();	// Сохраняем исходное положение головы змейки

	// Если измененные координаты головы змейки совпадают с координатами яблока
	if (++temp.x == Apple.x && temp.y == Apple.y)
	{
		Snake.Push(Apple);		// То добавляем звено в нашу змейку с координатами яблока
		Field::CreateApple();	// Создаём новое яблоко (старое съели)
		score++;				// Обновляем счётчик съеденных яблок
	}
	else	// Если координаты не совпали с яблоком
	{
		Snake.Push(temp);		// Добавляем новое звено с изменёнными координами
		Snake.Pop();			// Удаляем хвост змейки
	}
}

void Field::Left()	// Движение змейки влево по нажатию клавиши 'a'
{
	Position temp = Snake.Back();	// Сохраняем исходное положение головы змейки

	// Если измененные координаты головы змейки совпадают с координатами яблока
	if (--temp.x == Apple.x && temp.y == Apple.y)
	{
		Snake.Push(Apple);		// То добавляем звено в нашу змейку с координатами яблока
		Field::CreateApple();	// Создаём новое яблоко (старое съели)
		score++;				// Обновляем счётчик съеденных яблок
	}
	else	// Если координаты не совпали с яблоком
	{
		Snake.Push(temp);		// Добавляем новое звено с изменёнными координами
		Snake.Pop();			// Удаляем хвост змейки
	}
}

Field::Field(int x, int y) : columns(x), rows(y)
{
	field = new char*[rows];			// field - указатель на указатель на строки
	for (int i = 0; i < rows; i++)
		field[i] = new char[columns];	// field[i] - указатель на i строку

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (i == 0 || i == rows - 1)
				field[i][j] = '-';		// Верхняя и нижняя границы
			else if (j == 0 || j == columns - 1)
				field[i][j] = '|';		// Боковые границы
			else
				field[i][j] = ' ';		// Основное пространство
		}
	}

	// При создании поля также создаются яблоко и змейка
	CreateApple();
	CreateSnake();
}

Field::~Field()
{
	for (int i = 0; i < rows; i++)
		delete[] field[i];		// Сначала удаляем последовательно все строки
	delete[] field;				// После удаляем указатель на указатель на строки
}

void Field::CreateSnake()
{
	std::srand(std::time(0));	// Для обновления рандомизации

	Position tempPos;
	tempPos.x = rand() % columns;		// Задаём рандомное положение по координате x
	if (tempPos.x == 0)					// Если попали на левую границу - шаг вправо
		tempPos.x++;
	else if (tempPos.x == columns - 1)	// Если попали на правую границу - шаг влево
		tempPos.x--;

	tempPos.y = rand() % rows;			// Задаём рандомное положение по координате x
	if (tempPos.y == 0)					// Если попали на верхнюю границу - шаг вниз
		tempPos.y++;
	else if (tempPos.y == rows - 1)		// Если попали на нижнюю границу - шаг вверх
		tempPos.y--;

	Snake.Push(tempPos);	// Добавляем голову змейки - первый узел front
	field[tempPos.y][tempPos.x] = '#';
}

void Field::CreateApple()
{
	Apple.x = rand() % columns;			// Задаём рандомное положение по координате x
	if (Apple.x == 0)					// Если попали на левую границу - шаг вправо
		Apple.x++;
	else if (Apple.x == columns - 1)	// Если попали на правую границу - шаг влево
		Apple.x--;

	Apple.y = rand() % rows;			// Задаём рандомное положение по координате x
	if (Apple.y == 0)					// Если попали на верхнюю границу - шаг вниз
		Apple.y++;
	else if (Apple.y == rows - 1)		// Если попали на нижнюю границу - шаг вверх
		Apple.y--;

	field[Apple.y][Apple.x] = '@';
}

bool Field::GetKey()	// Считывание направления движения змейки
{
	char ch = std::cin.get();

	switch (ch)
	{
		// Ход вверх
		case 'W':
		case 'w':
			Field::Up();
			break;

		// Ход вниз
		case 'S':
		case 's':
			Field::Down();
			break;

		// Ход вправо
		case 'D':
		case 'd':
			Field::Right();
			break;

		// Ход влево
		case 'A':
		case 'a':
			Field::Left();
			break;
	}

	// Если врезались в боковые стенки - остановка игры
	if (Snake.Back().x == 0 || Snake.Back().x == columns - 1)
		return false;

	// Если врезались в верхнюю или нижнюю стенки - остановка игры
	if (Snake.Back().y == 0 || Snake.Back().y == rows - 1)
		return false;

	return true;	// Ход удачный
}

void Field::Show() const	// Отображение поля в консоли
{
	for (int i = 0; i < rows; i++)		// Сначала пробегаем по строкам
	{
		for (int j = 0; j < columns; j++)
			std::cout << field[i][j];	// Потом пробегаем по столбцам и выводим элемент
		std::cout << std::endl;			// После прохода строки переходим на новую строку
	}
}

void Field::ShowSnake() const	// Отображение змейки в консоли
{
	// Проход змейки от хвоста до головы (от начала списка к концу)
	for (auto pt = Snake.front; pt != nullptr; pt = pt->next)
	{
		if (pt == Snake.back && pt != Snake.front || Snake.back == Snake.front)
			field[pt->item.y][pt->item.x] = '#';	// '#' - голова змейки
		else
			field[pt->item.y][pt->item.x] = '.';	// '.' - туловище змейки
	}
}

void Field::Clear()		// Очистка поля
{
	for (int i = 1; i < rows - 1; i++)	// Сначала пробегаем по строкам
		for (int j = 1; j < columns - 1; j++)
		{
			if (field[i][j] == '@')		// Если наткнулись на яблоко - пропускаем
				continue;
			else
				field[i][j] = ' ';		// Потом пробегаем по столбцам и очищаем элементы
		}
}

void Field::Game()		// Запуск игры
{
	bool SnakeIsAlive = true;	// Змейка жива
	while (SnakeIsAlive)		// Пока змейка жива - идёт игра
	{
		Clear();		// Перед каждым ходом очищаем наше поле
		ShowSnake();	// Отоборажаем на поле змейку

		// Выводим счёт, отображаем поле и получаем направление хода змейки (и ходим)
		std:: cout << "Score: " << Score() << std::endl;

		Show();
		Move();
		//SnakeIsAlive = GetKey();

		Sleep(100);

		system("cls");	// Очистка экрана
	}

	std::cout << "Game over. Your score = " << Score() << "\n";	// Игра закончена, вывод счёта
}

void Field::Move()
{
	if (GetKeyState(VK_UP) & 0x8000)
	{
		Up();
	}

	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		Down();
	}

	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		Right();
	}

	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		Left();
	}
}
