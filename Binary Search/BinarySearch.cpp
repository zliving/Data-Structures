#include <iostream>

using namespace std;
int count;

int occurences(int arr[], int first, int last, int occurance)
{
	int mid = (first + last) / 2;
	if (first<last)
	{
		if (arr[mid] == occurance)
		{
			cout << "Found : "<<occurance;
		}
		occurences(arr, first, mid, occurance);
		occurences(arr, mid + 1, last, occurance);
	}
	return 0;
}

int main()
{
	bool x = false;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	occurences(arr, 0, 8, 1);
	return 0;
}