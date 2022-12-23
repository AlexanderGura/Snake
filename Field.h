// Field.h -- объявление класса Field

#ifndef FIELD_H_
#define FIELD_H_

#include "List.h"

class Field
{
private:
	char** field;	// Двумерный массив(матрица) символом - наше поле
	int rows;		// Количество строк
	int columns;	// Количество столбцов
	int score = 0;	// Счётчик съеденных яблок

	struct Position	// Структура, содежащая декартовы координаты элемента поля
	{
		int x;
		int y;
	};

	Position Apple;			// Структура, отвечающая за координаты яблока
	List<Position> Snake;	// Список структур, каждая из которых - координаты элемента змейки

protected:
	void Up();		// Движение змейки вверх
	void Down();	// Движение змейки вниз
	void Right();	// Движение змейки вправо
	void Left();	// Движение змейки влево


public:
	Field(int x, int y);	// Создание поля
	~Field();				// Удаление поля
	void CreateSnake();		// Создание змейки на поле
	void CreateApple();		// Создание яблока на поле
	bool GetKey();			// Считывание направления движения змейки (true - удачный ход, false - неудачныый)
	int Score() const { return score; }		// Возвращает счётчик съеденных яблок
	
	void Show() const;		// Отображение поля в консоли
	void ShowSnake() const;	// Отображение змейки на поле
	void Clear();			// Очистка поля

	void Game();			// Запуск игры
	void Move();			// Движение змейки по нажатию стрелок

};

#endif