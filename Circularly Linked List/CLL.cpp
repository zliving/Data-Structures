#include <iostream>

using namespace std;

class Node {
public:
	Node() {
		next = 0;
	}
	Node(int el, Node *ptr = 0) {
		info = el; next = ptr;
	}

	int info;
	Node *next;
};
class List {
public:
	List() {
		head = tail = 0;
	}

	int isEmpty() {
		return head == 0;
	}

	void addToTail(int);
	void deleteFromTail();
	void print();
private:
	Node *head, *tail;
};

void List::addToTail(int el) {
	if (tail == 0) {
		tail = new Node(el);
	}
	else {
		tail->next = new Node(el);
	}
}

void List::deleteFromTail()
{
	Node *temp, *back;
	for (temp = tail; temp != 0; temp = temp->next)
	{
		temp->next = tail->next;
		delete tail;

	}

}
void List::print()
{
	Node *temp;
	for (temp = tail; temp != 0; temp = temp->next)
	{
		cout << temp->info;
	}
}
void main()
{
	List newList;
	newList.addToTail(5);
	newList.addToTail(3);
	newList.print(); 
}