#ifndef LIST
#define LIST

template <typename T> class ListEntry;

template <typename T>
class List
{
public:
	typedef ListEntry<T> Node;
	typedef unsigned long Len;
private:
	Node* head;
	Len len;
public:
	Len Length();
	void insert_front(T t);
	Node find(T t);
	void remove_node(Node n);
	List():head(new Node()),len(0);
	~List();
};

//创建List的时候，初始化head(此时head的Next域，elm域都为空)，长度len为0
template <typename T>
List::List():head(new Node()),len(0)
{
}

template <typename T>
List::~List()
{
	if(head != nullptr) delete head;
}

template <typename T>
List::Len List::Length()
{
	return len;
}

template <typename T>
void List::insert_front(T t)
{

}

template <typename T>
List::Node List::find(T t)
{

}

template <typename T>
void List::remove_node(Node n);



//List的实体（节点）
template <typename T> class ListEntry
{
private:
	//List元素类型，本类型声明为泛型来实现通用
	typedef T ElementType;

public:
	//指向下一个节点的指针
	ListEntry* Next;

	//链表元素域
	ElementType* elm;

	//构造函数
	ListEntry():Next(nullptr),elm(nullptr);

	//析构函数，当节点销毁时删除元素
	~ListEntry();
};

template <template T>
ListEntry::ListEntry():Next(nullptr),elm(nullptr)
{
}

template <template T>
ListEntry::~ListEntry()
{
	if(elm != nullptr)
	{
		delete elm;
	}
}


#endif