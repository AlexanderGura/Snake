#ifndef LIST_H_
#define LIST_H_

template<typename T>
class List
{
public:
	struct Node	// Каждый узел списка - структура Node
	{
		T item;		// Элемент узла
		Node* next;	// Указатель на следующий узел
	};

	Node* front;	// Указатель на первый узел
	Node* back;		// Указатель на последний узел

public:
	List() : front(nullptr), back(nullptr) { };
	~List();
	void Push(const T& it);	// Добавление узла в конец списка
	bool Pop();				// Удаление узла из конца списка
	T& Front() { return front->item; };	// Возвращает содержимое первого узла
	T& Back() { return back->item; };	// Возвращает содержимое последнего узла
};


template<typename T>
List<T>::~List()
{
	for (auto point = front; point != nullptr; point = front)
	{
		auto temp = point;		// Выставляем указатель на текущий узел
		front = front->next;
		delete temp;
	}
}

template<typename T>
void List<T>::Push(const T& it)
{
	Node* temp = new Node;	// Создали новый узел
	temp->item = it;		// Установка значения в новом узле
	temp->next = nullptr;	// Указатель на следующий узел - nullptr

	if (front == nullptr)
	{
		front = temp;
		back = temp;
	}
	else
	{
		back->next = temp;
		back = back->next;
	}
}

template<typename T>
bool List<T>::Pop()
{
	if (front == nullptr)	// Если список пуст
		return false;

	Node* temp = front;
	front = front->next;

	delete temp;			// Удаляем последний узел
	return true;
}

#endif