#pragma once


template <typename T>
class List
{
public:
	List();

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
