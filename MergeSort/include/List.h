#pragma once


template <typename T>
class List
{
public:
	List();

	void push_front(T data);

	void push_back(T data);

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
