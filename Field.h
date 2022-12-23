// Field.h -- ���������� ������ Field

#ifndef FIELD_H_
#define FIELD_H_

#include "List.h"

class Field
{
private:
	char** field;	// ��������� ������(�������) �������� - ���� ����
	int rows;		// ���������� �����
	int columns;	// ���������� ��������
	int score = 0;	// ������� ��������� �����

	struct Position	// ���������, ��������� ��������� ���������� �������� ����
	{
		int x;
		int y;
	};

	Position Apple;			// ���������, ���������� �� ���������� ������
	List<Position> Snake;	// ������ ��������, ������ �� ������� - ���������� �������� ������

protected:
	void Up();		// �������� ������ �����
	void Down();	// �������� ������ ����
	void Right();	// �������� ������ ������
	void Left();	// �������� ������ �����


public:
	Field(int x, int y);	// �������� ����
	~Field();				// �������� ����
	void CreateSnake();		// �������� ������ �� ����
	void CreateApple();		// �������� ������ �� ����
	bool GetKey();			// ���������� ����������� �������� ������ (true - ������� ���, false - ����������)
	int Score() const { return score; }		// ���������� ������� ��������� �����
	
	void Show() const;		// ����������� ���� � �������
	void ShowSnake() const;	// ����������� ������ �� ����
	void Clear();			// ������� ����

	void Game();			// ������ ����
	void Move();			// �������� ������ �� ������� �������

};

#endif