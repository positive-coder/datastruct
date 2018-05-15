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
	Node find_pre(Node* n);

public:
	EList();
	~EList();
	void insert_front(Elm* e);
	void remove_node(Node* n);
	Elm& find_index(Index index);
	Len length();
};

template <typename T>
EList<T>::EList():head(new Node()),len(0)
{
	head->next = nullptr;
	head->elm = nullptr;
}

template <typename T>
EList<T>::~EList()
{
	if(head != nullptr) 
		for (int i = 0;i < length();i++)
		{
			Node* n = head;
			head = head->next;
			delete n;
		}
		
}

template <typename T>
typename EList<T>::Elm& EList<T>::find_index(Index index)
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
	return *(result->elm);
}

template <typename T>
typename EList<T>::Len EList<T>::length()
{
	return len-1;
}

template <typename T>
void EList<T>::insert_front(Elm* e)
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
typename EList<T>::Node EList<T>::find_pre(Node* n)
{
	if(head == nullptr) 
	{
		printf("list init err...\n");
		exit(-1);
	}
	Node* ntmp = head;
	while (n->next != nullptr && n->next != e)
	{
		n = n->next;
	}
	return n;
}

template <typename T>
void EList<T>::remove_node(Node* n)
{
	Node* curn = find_pre(n);

	if (curn->next != nullptr)
	{
		return;
	}
	curn->next = curn->next->next;
	delete curn->next;
	len--;
}

template <typename T> 
class EListEntry
{
public:
	typedef T Elm;
public:
	EListEntry* next;
	Elm* elm;
	EListEntry();
	~EListEntry();
};

template <typename T> 
EListEntry<T>::EListEntry():next(nullptr),elm(nullptr)
{

}

template <typename T> 
EListEntry<T>::~EListEntry()
{
	//if(elm != nullptr) delete elm;
}




#endif