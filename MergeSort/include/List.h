#pragma once
#include <string>

template <typename T>
class List
{
public:
	List();

	void push_front(T data);

	void push_back(T data);

	void pop_back();

	void pop_front();

	class Node {
	public:
		Node(T Data);
		T data;
	private:	
		Node* next;
		Node* prev;
		friend List<T>;
	};

protected:
	
	Node* head;
	Node* tail;
	int size;

};

template<typename T>
inline List<T>::Node::Node(T data)
{
	this->data = data;
	next = nullptr;
	prev = nullptr;
}

template<typename T>
inline List<T>::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline void List<T>::push_front(T data)
{
	Node* new_node = new Node(data);
	if (size != 0)
	{
		new_node->next = head;
		new_node->prev = nullptr;
		head = new_node;
	}
	else
	{
		head = new_node;
		tail = new_node;
		new_node->next = nullptr;
		new_node->prev = nullptr;
	}
	size++;
}

template<typename T>
inline void List<T>::push_back(T data)
{
	Node* new_node = new Node(data);
	if (size != 0)
	{
		new_node->next = nullptr;
		new_node->prev = tail;
		tail = new_node;
	}
	else
	{
		head = new_node;
		tail = new_node;
		new_node->next = nullptr;
		new_node->prev = nullptr;
	}
	size++;
}

template<typename T>
inline void List<T>::pop_back()
{
	Node* ptr = tail;
	if (size == 1)
	{
		delete tail;
		tail = nullptr;
		head = nullptr;
	}
	else if (size != 0) 
	{
		tail = ptr->prev;
		ptr->prev->next = nullptr;
		delete ptr;
	}
	else
	{
		throw std::string("try pop_back in empty list");
	}
}

template<typename T>
inline void List<T>::pop_front()
{
	Node* ptr = head;
	if (size == 1)
	{
		delete head;
		tail = nullptr;
		head = nullptr;
	}
	else if (size != 0)
	{
		head = ptr->next;
		ptr->next->prev = nullptr;
		delete ptr;
	}
	else
	{
		throw std::string("try pop_front in empty list");
	}
}
