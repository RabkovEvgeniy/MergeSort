#pragma once

template <typename T>
class List
{
public:
	List();


	~List();

protected:
	
	class Node {
	public:
		T data;
		Node* next;
		Node* prev;

		Node(T Data);
	};

	Node* head;
	Node* tail;
	int size;
};

template<typename T>
inline List<T>::Node::Node(T data)
{
	this->data = data;
}

template<typename T>
inline List<T>::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
