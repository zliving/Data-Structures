#include <iostream>
using namespace std;

template <class T>
struct Node
{
	Node(T data) : data(data), next(NULL), prev(NULL) {}
	T data;
	Node * next;
	Node * prev;
};

template <class T>
class DoublyLinkedList
{
public:
	DoublyLinkedList() : head(NULL), tail(NULL) {}
	DoublyLinkedList(const DoublyLinkedList<T> & dll);
	~DoublyLinkedList();
	void addNode(T);
	void deleteNode(T);
	void printBackward(T);
	template <class U>
	friend std::ostream & operator<<(std::ostream & os, const DoublyLinkedList<U> & dll);
private:
	Node<T> * head;
	Node<T> * tail;
};

template <class U>
std::ostream & operator<<(std::ostream & os, const DoublyLinkedList<U> & dll)
{
	Node<U> * tmp = dll.head;
	while (tmp)
	{
		os << tmp->data << " ";
		tmp = tmp->next;
	}

	return os;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	Node<T> * tmp = NULL;
	while (head)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
	head = tail = NULL;
}

template <class T>
void DoublyLinkedList<T>::addNode(T data)
{
	Node<T> * t = new Node<T>(data);

	Node<T> * tmp = head;
	if (tmp == NULL)
	{
		head = tail = t;
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}

		tmp->next = t;
		t->prev = tail;

		tail = t;
	}
}

template <class T>
void DoublyLinkedList<T>::deleteNode(T data)
{
	Node<T> * tmp = head;
	while (tmp && tmp->data != data)
	{
		tmp = tmp->next;
	}

	if (tmp)
	{
		if (tmp->prev && tmp->next)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}
		else if (tmp->prev) 
		{
			tmp->prev->next = tmp->next;
			tail = tmp->prev;
		}
		else if (tmp->next) 
		{
			tmp->next->prev = tmp->prev;
			head = tmp->next;
		}

		delete tmp;
	}
}

template <class T>
void DoublyLinkedList<T>::printBackward(T k)
{
	Node<T> *temp;

	for (temp = tail; temp != NULL; temp = temp->prev)
	{
		
		if (temp->data == k)
		{
			break;
		}
		cout << temp->data << " ";
	}
	cout << endl;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> & dll)
{
	Node<T> * tmp = dll.head;
	while (tmp)
	{
		this->addNode(tmp->data);
		tmp = tmp->next;
	}
}

int main()
{
	DoublyLinkedList<int> newList, newList2;

	newList.addNode(2);
	newList.addNode(3);
	newList.addNode(1);
	newList.addNode(8);
	newList.addNode(3);

	newList2.addNode(3);
	newList2.addNode(4);
	newList2.addNode(5);
	newList2.addNode(6);
	newList2.addNode(7);

	cout << "List 1: " << endl;
	newList.printBackward(2);
	cout << "List 2: " << endl;
	newList2.printBackward(2);
}