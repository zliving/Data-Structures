#include <iostream>

using namespace std;

class que
{
public:
	int quelist[10] = { 0,0,0,0,0,0,0,0,0,0 }, last = 0;
	void enque(int);
	void deque();
	bool isEmpty();
	void print();
};

void que::enque(int d)
{
	if (quelist[9] != NULL)
	{
		cout << "The que is full check back later" << endl;
	}
	else if (quelist[0] == NULL)
	{
		quelist[0] = d;
		
	}
	else
	{
		quelist[(last + 1)] = d;
		last++;
	}

}
void que::deque()
{
	if (quelist[0] == NULL) {
		cout << "the list is empty" << endl;
	}
	else {
		cout << quelist[0];
		for (int i = 0; i <= last; i++) {
			quelist[i] = quelist[i + 1];
		}
		last--;
	}
}
bool que::isEmpty()
{
	if (quelist == NULL)
	{
		return true;
	}
	else { return false; }
}
void que::print()
{
	for (int x = 0; x <= last; x++)
	{
		cout << quelist[x] << endl;
	}
}
int main()
{
	int menu,val;
	que que;
	bool x = true;
	while (x)
	{
		cout << "1.Enqueue" << endl;
		cout << "2.Dequeue" << endl;
		cout << "3.Display" << endl;
		cout << "4.Quit" << endl;
		cout << "Enter your choice:";
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case(1) :
			cout << "What number do you want to enqueue?" << endl;
			cin >> val;
			que.enque(val);
			break;
		case(2) :
			cout << "The data dequed is "<< endl;
			que.deque();
			cout << endl;
			break;
		case(3) :
			que.print();
			break;
		case(4) :
			x = false;
			break;
		}
	}
	return 0;
}