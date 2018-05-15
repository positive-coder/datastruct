#ifndef ELIST
#define ELIST
#include "stdlib.h"

//元素的前向声明
template <typename T> class EListEntry;

//单向链表的实现类
template <typename T>
class EList
{
public:
	typedef EListEntry<T> Node;
	typedef T Elm; 
	typedef unsigned long int Len;
	typedef unsigned long int Index;
private:
	Node* head;
	Len len;
	Node& find_pre(const Node& n);

public:
	EList();
	~EList();
	void insert_front(const Elm& e);
	void remove_node(Node& n);
	Elm& find_index(const Index& index);
	Len length();
};

template <typename T>
EList<T>::EList():head(new Node()),len(0)
{
	head->next = nullptr;
	//head->elm = nullptr;
}

template <typename T>
EList<T>::~EList()
{
	if(head != nullptr) 
		for (Len i = 0;i < length();i++)
		{
			Node* n = head;
			head = head->next;
			delete n;
		}
		
}

template <typename T>
typename EList<T>::Elm& EList<T>::find_index(const Index& index)
{
	if (head == nullptr)
	{
		printf("list init err...\n");
		exit(-1);
	}
	if (index > length())
	{
		printf("index out of range...\n");
		exit(-1);
	}

	Node result = head;
	for (int i = 0;i < index;i++)
	{
		result = result->next;
	}
	return result->elm;
}

template <typename T>
typename EList<T>::Len EList<T>::length()
{
	return len;
}

template <typename T>
void EList<T>::insert_front(const Elm& e)
{
	if(head == nullptr) 
	{
		printf("list init err...\n");
		exit(-1);
	}

	Node* newnode = new Node();
	newnode->elm = e;
	newnode->next = head->next;
	head->next = newnode;
	len++;
}

template <typename T>
typename EList<T>::Node& EList<T>::find_pre(const Node& n)
{
	if(head == nullptr) 
	{
		printf("list init err...\n");
		exit(-1);
	}
	Node* ntmp = head;
	while (ntmp->next != nullptr && ntmp->next != &n)
	{
		ntmp = ntmp->next;
	}
	return n;
}

template <typename T>
void EList<T>::remove_node(Node& n)
{
	Node* pre_node = find_pre(n);

	if (pre_node->next != nullptr)
	{
		return;
	}
	pre_node->next = pre_node->next->next;
	delete pre_node->next;
	len--;
}

template <typename T> 
class EListEntry
{
public:
	typedef T Elm;
public:
	EListEntry* next;
	Elm elm;
	EListEntry();
	~EListEntry();
	EListEntry& operator=(EListEntry& r);
};

template <typename T> 
EListEntry<T>::EListEntry():next(nullptr)
{

}

template <typename T> 
EListEntry<T>::~EListEntry()
{
	//if(elm != nullptr) delete elm;
}

template <typename T> 
EListEntry<T>& EListEntry<T>::operator=(EListEntry& r)
{
	if (this == &r)
	{
		return this;
	}
	this->elm = r.elm;
	return this;
}



#endif