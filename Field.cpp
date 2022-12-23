// Field.cpp -- ����������� ������� ����� Field

#include <iostream>
#include "Field.h"
#include <Windows.h>
#include "List.h"

void Field::Up()	// �������� ������ ����� �� ������� ������� 'w'
{
	Position temp = Snake.Back();	// ��������� �������� ��������� ������ ������

	// ���� ���������� ���������� ������ ������ ��������� � ������������ ������
	if (--temp.y == Apple.y && temp.x == Apple.x)
	{
		Snake.Push(Apple);		// �� ��������� ����� � ���� ������ � ������������ ������
		Field::CreateApple();	// ������ ����� ������ (������ �����)
		score++;				// ��������� ������� ��������� �����
	}
	else	// ���� ���������� �� ������� � �������
	{
		Snake.Push(temp);		// ��������� ����� ����� � ���������� ����������
		Snake.Pop();			// ������� ����� ������
	}
}

void Field::Down()	// �������� ������ ���� �� ������� ������� 's'
{
	Position temp = Snake.Back();	// ��������� �������� ��������� ������ ������

	// ���� ���������� ���������� ������ ������ ��������� � ������������ ������
	if (++temp.y == Apple.y && temp.x == Apple.x)
	{
		Snake.Push(Apple);		// �� ��������� ����� � ���� ������ � ������������ ������
		Field::CreateApple();	// ������ ����� ������ (������ �����)
		score++;				// ��������� ������� ��������� �����
	}
	else	// ���� ���������� �� ������� � �������
	{
		Snake.Push(temp);		// ��������� ����� ����� � ���������� ����������
		Snake.Pop();			// ������� ����� ������
	}
}

void Field::Right()	// �������� ������ ������ �� ������� ������� 'd'
{
	Position temp = Snake.Back();	// ��������� �������� ��������� ������ ������

	// ���� ���������� ���������� ������ ������ ��������� � ������������ ������
	if (++temp.x == Apple.x && temp.y == Apple.y)
	{
		Snake.Push(Apple);		// �� ��������� ����� � ���� ������ � ������������ ������
		Field::CreateApple();	// ������ ����� ������ (������ �����)
		score++;				// ��������� ������� ��������� �����
	}
	else	// ���� ���������� �� ������� � �������
	{
		Snake.Push(temp);		// ��������� ����� ����� � ���������� ����������
		Snake.Pop();			// ������� ����� ������
	}
}

void Field::Left()	// �������� ������ ����� �� ������� ������� 'a'
{
	Position temp = Snake.Back();	// ��������� �������� ��������� ������ ������

	// ���� ���������� ���������� ������ ������ ��������� � ������������ ������
	if (--temp.x == Apple.x && temp.y == Apple.y)
	{
		Snake.Push(Apple);		// �� ��������� ����� � ���� ������ � ������������ ������
		Field::CreateApple();	// ������ ����� ������ (������ �����)
		score++;				// ��������� ������� ��������� �����
	}
	else	// ���� ���������� �� ������� � �������
	{
		Snake.Push(temp);		// ��������� ����� ����� � ���������� ����������
		Snake.Pop();			// ������� ����� ������
	}
}

Field::Field(int x, int y) : columns(x), rows(y)
{
	field = new char*[rows];			// field - ��������� �� ��������� �� ������
	for (int i = 0; i < rows; i++)
		field[i] = new char[columns];	// field[i] - ��������� �� i ������

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (i == 0 || i == rows - 1)
				field[i][j] = '-';		// ������� � ������ �������
			else if (j == 0 || j == columns - 1)
				field[i][j] = '|';		// ������� �������
			else
				field[i][j] = ' ';		// �������� ������������
		}
	}

	// ��� �������� ���� ����� ��������� ������ � ������
	CreateApple();
	CreateSnake();
}

Field::~Field()
{
	for (int i = 0; i < rows; i++)
		delete[] field[i];		// ������� ������� ��������������� ��� ������
	delete[] field;				// ����� ������� ��������� �� ��������� �� ������
}

void Field::CreateSnake()
{
	std::srand(std::time(0));	// ��� ���������� ������������

	Position tempPos;
	tempPos.x = rand() % columns;		// ����� ��������� ��������� �� ���������� x
	if (tempPos.x == 0)					// ���� ������ �� ����� ������� - ��� ������
		tempPos.x++;
	else if (tempPos.x == columns - 1)	// ���� ������ �� ������ ������� - ��� �����
		tempPos.x--;

	tempPos.y = rand() % rows;			// ����� ��������� ��������� �� ���������� x
	if (tempPos.y == 0)					// ���� ������ �� ������� ������� - ��� ����
		tempPos.y++;
	else if (tempPos.y == rows - 1)		// ���� ������ �� ������ ������� - ��� �����
		tempPos.y--;

	Snake.Push(tempPos);	// ��������� ������ ������ - ������ ���� front
	field[tempPos.y][tempPos.x] = '#';
}

void Field::CreateApple()
{
	Apple.x = rand() % columns;			// ����� ��������� ��������� �� ���������� x
	if (Apple.x == 0)					// ���� ������ �� ����� ������� - ��� ������
		Apple.x++;
	else if (Apple.x == columns - 1)	// ���� ������ �� ������ ������� - ��� �����
		Apple.x--;

	Apple.y = rand() % rows;			// ����� ��������� ��������� �� ���������� x
	if (Apple.y == 0)					// ���� ������ �� ������� ������� - ��� ����
		Apple.y++;
	else if (Apple.y == rows - 1)		// ���� ������ �� ������ ������� - ��� �����
		Apple.y--;

	field[Apple.y][Apple.x] = '@';
}

bool Field::GetKey()	// ���������� ����������� �������� ������
{
	char ch = std::cin.get();

	switch (ch)
	{
		// ��� �����
		case 'W':
		case 'w':
			Field::Up();
			break;

		// ��� ����
		case 'S':
		case 's':
			Field::Down();
			break;

		// ��� ������
		case 'D':
		case 'd':
			Field::Right();
			break;

		// ��� �����
		case 'A':
		case 'a':
			Field::Left();
			break;
	}

	// ���� ��������� � ������� ������ - ��������� ����
	if (Snake.Back().x == 0 || Snake.Back().x == columns - 1)
		return false;

	// ���� ��������� � ������� ��� ������ ������ - ��������� ����
	if (Snake.Back().y == 0 || Snake.Back().y == rows - 1)
		return false;

	return true;	// ��� �������
}

void Field::Show() const	// ����������� ���� � �������
{
	for (int i = 0; i < rows; i++)		// ������� ��������� �� �������
	{
		for (int j = 0; j < columns; j++)
			std::cout << field[i][j];	// ����� ��������� �� �������� � ������� �������
		std::cout << std::endl;			// ����� ������� ������ ��������� �� ����� ������
	}
}

void Field::ShowSnake() const	// ����������� ������ � �������
{
	// ������ ������ �� ������ �� ������ (�� ������ ������ � �����)
	for (auto pt = Snake.front; pt != nullptr; pt = pt->next)
	{
		if (pt == Snake.back && pt != Snake.front || Snake.back == Snake.front)
			field[pt->item.y][pt->item.x] = '#';	// '#' - ������ ������
		else
			field[pt->item.y][pt->item.x] = '.';	// '.' - �������� ������
	}
}

void Field::Clear()		// ������� ����
{
	for (int i = 1; i < rows - 1; i++)	// ������� ��������� �� �������
		for (int j = 1; j < columns - 1; j++)
		{
			if (field[i][j] == '@')		// ���� ���������� �� ������ - ����������
				continue;
			else
				field[i][j] = ' ';		// ����� ��������� �� �������� � ������� ��������
		}
}

void Field::Game()		// ������ ����
{
	bool SnakeIsAlive = true;	// ������ ����
	while (SnakeIsAlive)		// ���� ������ ���� - ��� ����
	{
		Clear();		// ����� ������ ����� ������� ���� ����
		ShowSnake();	// ����������� �� ���� ������

		// ������� ����, ���������� ���� � �������� ����������� ���� ������ (� �����)
		std:: cout << "Score: " << Score() << std::endl;

		Show();
		Move();
		//SnakeIsAlive = GetKey();

		Sleep(100);

		system("cls");	// ������� ������
	}

	std::cout << "Game over. Your score = " << Score() << "\n";	// ���� ���������, ����� �����
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
