// Game.cpp -- ������� ��������� ���� "������"

#include <iostream>
#include <Windows.h>
#include "Field.h"
#include "List.h"

int main()
{

	Field snake(20, 10);	// ������� ������� ����
	snake.Game();			// ��������� ����

	return 0;
}