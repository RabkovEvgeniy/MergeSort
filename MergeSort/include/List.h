#pragma once
#include <string>
#include <cmath>
#include <iostream>

template <typename T>
class List
{
public:
	static int M;
	static int C;
	List();

	void push_front(T data);

	void push_back(T data);
	
	void pop_back();

	void clear();

	void pop_front();

	void FillRund(int size);
	void FillInc(int size);
	void FillDec(int size);

	T check_sum();

	int run_num();

	int get_size();
	
	void print();

	void merge(List<T>& A, int ASize, List<T>& B, int BSize);

	void MergeSort();

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

	void operator=(List<T>& A);
	
	~List();
protected:
	
	Node* head;
	Node* tail;
	int size;
	
	void separate(int n, List<T>& A, List<T>& B);

};

template <typename T>
int List<T>::C = 0;
template <typename T>
int List<T>::M = 0;


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
		head->prev = new_node;
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
		tail->next = new_node;
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
inline void List<T>::clear()
{
	while(size!=0)
	pop_back();
	M = C = 0;
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
inline void List<T>::FillRund(int size)
{
	for (int i = 0; i < size; i++)
	{
		this->push_back(rand() % size);
	}
}

template<typename T>
inline void List<T>::FillInc(int size)
{
	for (int i = 0; i < size; i++)
	{
		this->push_back(i);
	}
}

template<typename T>
inline void List<T>::FillDec(int size)
{
	for (int i = 0; i < size; i++)
	{
		this->push_back(size - i);
	}
}

template<typename T>
inline T List<T>::check_sum()
{
	T sum = 0;
	for (Node* ptr = get_head(); ptr!=nullptr; ptr = ptr->next)
	{
		sum += ptr->data;
	}
	return sum;
}

template<typename T>
inline int List<T>::run_num()
{
	int count=1;
	for (Node* ptr = get_head(); ptr->next != nullptr; ptr = ptr->next)
	{
		if (ptr->data > ptr->next->data)
			count++;
	}
	return count;
}

template<typename T>
inline int List<T>::get_size()
{
	return this->size;
}

template<typename T>
inline void List<T>::print()
{
	Node* it = head;
	for (int i = 0; i < size; i++)
	{
		std::cout << it->data << " ";
		if (it->next != nullptr)
			it = it->next;
	}
	std::cout << std::endl;
}

template<typename T>
inline void List<T>::merge(List<T>& A, int ASize, List<T>& B, int BSize)
{
	
	while ((A.size != 0 && ASize != 0) || (B.size != 0 && BSize != 0  ))
	{
		if(A.size == 0 || ASize == 0)
		{
			M++;
			this->emplace_back_node(B.get_first_node());
			BSize--;
		}
		else if (B.size == 0 || BSize == 0)
		{
			M++;
			this->emplace_back_node(A.get_first_node());
			ASize--;
		}
		else
		{
			M++;
			C++;
			if (A.head->data > B.head->data) {
				this->emplace_back_node(B.get_first_node());
				BSize--;
			}
			else {
				this->emplace_back_node(A.get_first_node());
				ASize--;
			}
		}
	}
}

template<typename T>
inline void List<T>::MergeSort()
{
	int max = size, i, j;
	List<T> c1,c2,a, b;
	this->separate(1,c1, c2);
	for (i = 1; i < max; i*=2)
	{
		j = 0;
		while (c1.size != 0 || c2.size != 0)
		{
			if (j % 2 == 0)
				a.merge(c1, i, c2, i);
			else
				b.merge(c1, i, c2, i);
			j++;
		}
		c1 = a;
		c2 = b;
	}
	*this = c1;
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
		tail->next = new_node;
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

template<typename T>
inline void List<T>::operator=(List<T>& A)
{
	this->head = A.head;
	this->tail = A.tail;
	this->size = A.size;
	A.head = A.tail = nullptr;
	A.size = 0;
}

template<typename T>
inline void List<T>::separate(int n, List<T>& A, List<T>& B)
{
	M += size;
	for (int i = 0; size!=0;i++)
	{
		if ((i / n) % 2 == 0)
			A.emplace_back_node(this->get_first_node());
		else
			B.emplace_back_node(this->get_first_node());
	}
}
