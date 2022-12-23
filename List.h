#ifndef LIST_H_
#define LIST_H_

template<typename T>
class List
{
public:
	struct Node	// ������ ���� ������ - ��������� Node
	{
		T item;		// ������� ����
		Node* next;	// ��������� �� ��������� ����
	};

	Node* front;	// ��������� �� ������ ����
	Node* back;		// ��������� �� ��������� ����

public:
	List() : front(nullptr), back(nullptr) { };
	~List();
	void Push(const T& it);	// ���������� ���� � ����� ������
	bool Pop();				// �������� ���� �� ����� ������
	T& Front() { return front->item; };	// ���������� ���������� ������� ����
	T& Back() { return back->item; };	// ���������� ���������� ���������� ����
};


template<typename T>
List<T>::~List()
{
	for (auto point = front; point != nullptr; point = front)
	{
		auto temp = point;		// ���������� ��������� �� ������� ����
		front = front->next;
		delete temp;
	}
}

template<typename T>
void List<T>::Push(const T& it)
{
	Node* temp = new Node;	// ������� ����� ����
	temp->item = it;		// ��������� �������� � ����� ����
	temp->next = nullptr;	// ��������� �� ��������� ���� - nullptr

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
	if (front == nullptr)	// ���� ������ ����
		return false;

	Node* temp = front;
	front = front->next;

	delete temp;			// ������� ��������� ����
	return true;
}

#endif