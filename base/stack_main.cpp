#include "Stack.h"

int main()
{
	int n;
	cout << "hi" << endl;
	cin >> n;
	
	TStack<int> Help(n);

	if (Help.IsEmpty() == true)
	{
		cout << "Stack is empty" << endl;
	}
	else
		cout << "Stack is full" << endl;

    return 0;
}

