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

	int get_size();
	

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

	Node* get_head();

	Node* get_first_node();

	void emplace_back_node(Node* ptr);

	Node* get_tail();

	static Node* get_next_node_ptr(Node* ptr);

	static Node* get_prev_node_ptr(Node* ptr);

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
inline int List<T>::get_size()
{
	return this->size;
}

template<typename T>
inline List<T>::~List()
{
	while (size != 0)
		pop_front();
}

template<typename T>
inline typename List<T>::Node* List<T>::get_head(){
	return head;
}

template<typename T>
inline typename List<T>::Node* List<T>::get_first_node()
{
	Node* ptr = head;
	if (size == 1)
	{
		tail = nullptr;
		head = nullptr;
	}
	else if (size != 0)
	{
		head = ptr->next;
		ptr->next->prev = nullptr;
	}
	else
	{
		throw 2;
	}
	size--;
	return ptr;
}

template<typename T>
inline void List<T>::emplace_back_node(Node* new_node)
{
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
inline typename List<T>::Node* List<T>::get_tail()
{
	return tail;
}

template<typename T>
inline typename List<T>::Node* List<T>::get_next_node_ptr(List<T>::Node* ptr)
{
	if (ptr->next == nullptr)
		return ptr;
	else return ptr->next;
}

template<typename T>
inline typename List<T>::Node* List<T>::get_prev_node_ptr(List<T>::Node* ptr)
{
	if (ptr->prev == nullptr)
		return ptr;
	else return ptr->prev;

}
