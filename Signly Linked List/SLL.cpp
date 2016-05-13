#include <iostream>
#include "intSLList.h"
using namespace std;
IntSLList::~IntSLList() {
	for (IntSLLNode *p; !isEmpty(); ) {
		p = head->next;
		delete head;
		head = p;
	}
}

void IntSLList::addToHead(int el) {
	head = new IntSLLNode(el, head);
	if (tail == 0)
		tail = head;
}

void IntSLList::addToTail(int el) {
	if (tail != 0) {      // if list not empty;
		tail->next = new IntSLLNode(el);
		tail = tail->next;
	}
	else head = tail = new IntSLLNode(el);
}

int IntSLList::deleteFromHead() {
	int el = head->info;
	IntSLLNode *tmp = head;
	if (head == tail)     // if only one node on the list;
		head = tail = 0;
	else head = head->next;
	delete tmp;
	return el;
}

int IntSLList::deleteFromTail() {
	int el = tail->info;
	if (head == tail) {   // if only one node on the list;
		delete head;
		head = tail = 0;
	}
	else {                // if more than one node in the list,
		IntSLLNode *tmp; // find the predecessor of tail;
		for (tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp;      // the predecessor of tail becomes tail;
		tail->next = 0;
	}
	return el;
}

void IntSLList::deleteNode(int el) {
	if (head != 0)                     // if non-empty list;
		if (head == tail && el == head->info) { // if only one
			delete head;                       // node on the list;
			head = tail = 0;
		}
		else if (el == head->info) {  // if more than one node on the list
			IntSLLNode *tmp = head;
			head = head->next;
			delete tmp;              // and old head is deleted;
		}
		else {                        // if more than one node in the list
			IntSLLNode *pred, *tmp;
			for (pred = head, tmp = head->next; // and a non-head node
			tmp != 0 && !(tmp->info == el);// is deleted;
				pred = pred->next, tmp = tmp->next);
				if (tmp != 0) {
					pred->next = tmp->next;
					if (tmp == tail)
						tail = pred;
					delete tmp;
				}
		}
}

bool IntSLList::isInList(int el) const {
	IntSLLNode *tmp;
	for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
	return tmp != 0;
}

void IntSLList::printAll() const {
	for (IntSLLNode *tmp = head; tmp != 0; tmp = tmp->next)
		cout << tmp->info << " ";
	cout << endl;
}
int IntSLList::deleteLast(IntSLLNode *p)
{
	if (p == NULL)
	{
		p = head;
	}
	if (p->next == tail)
	{
		IntSLLNode *temp;
		temp = p;
		delete tail;
		tail = temp;
		tail->next = 0;
		return 0;
	}
	else { return deleteLast(p ->next); }
}
IntSLList IntSLList::Append(IntSLList list1, IntSLList list2)
{
	IntSLLNode *p = list2.head;
	if (p == NULL)
	{
		return list1;
	}
	else {
		addToTail(p->info);
		list2.deleteFromHead();
		Append(list1, list2);
	}
	
}
void IntSLList::Zip(IntSLList list1, IntSLList list2)
{
	IntSLLNode *p = list2.head, *x = list1.head;
	if (p == NULL)
	{
		return;
	}
	else {
		addToTail(p->info);
		addToTail(x->info);
		list1.deleteFromHead();
		list2.deleteFromHead();
		Zip(list1, list2);
	}
}
int main() {
	IntSLList list1, list2, list3; IntSLLNode *node = NULL;
	list1.addToHead(1);
	list1.addToTail(2);
	list1.addToTail(3);
	list1.printAll();
	list1.deleteLast(node);
	list1.printAll();
	list2.addToHead(1);
	list2.addToTail(2);
	list2.addToTail(3);
	list3 = list1.Append(list1,list2);
	list3.printAll();
}
