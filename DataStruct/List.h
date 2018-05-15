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

//����List��ʱ�򣬳�ʼ��head(��ʱhead��Next��elm��Ϊ��)������lenΪ0
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



//List��ʵ�壨�ڵ㣩
template <typename T> class ListEntry
{
private:
	//ListԪ�����ͣ�����������Ϊ������ʵ��ͨ��
	typedef T ElementType;

public:
	//ָ����һ���ڵ��ָ��
	ListEntry* Next;

	//����Ԫ����
	ElementType* elm;

	//���캯��
	ListEntry():Next(nullptr),elm(nullptr);

	//�������������ڵ�����ʱɾ��Ԫ��
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