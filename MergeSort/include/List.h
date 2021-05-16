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

	~List();

	class Node {
	public:
		Node(T Data);
		T data;
	private:	
		Node* next;
		Node* prev;
		friend List<T>;
	};

	List<T>::Node* get_head();

	List<T>::Node* get_tail();

	static List<T>::Node* get_next_node_ptr(List<T>::Node* ptr);

	static List<T>::Node* get_prev_node_ptr(List<T>::Node* ptr);

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
		throw 1;
	}
	size--;
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
		throw 2;
	}
	size--;
}

template<typename T>
inline List<T>::~List()
{
	while (size != 0)
		pop_front();
}

template<typename T>
inline List<T>::Node* List<T>::get_head()
{
	return head;
}

template<typename T>
inline List<T>::Node* List<T>::get_tail()
{
	return tail;
}

template<typename T>
inline List<T>::Node* List<T>::get_next_node_ptr(List<T>::Node* ptr)
{
	if (ptr->next == nullptr)
		return ptr;
	else return ptr->next;
}

template<typename T>
inline List<T>::Node* List<T>::get_prev_node_ptr(List<T>::Node* ptr)
{
	if (ptr->prev == nullptr)
		return ptr;
	else return ptr->prev;

}
