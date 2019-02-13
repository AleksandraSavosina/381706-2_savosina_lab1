// Stack.cpp: определяет точку входа для консольного приложения.
//
#include "Stack.h"

using namespace std;

int main()
{
  int n;
  cout << "Enter size of stack: ";
  cin >> n;
  TStack<int> help(n);
  int j = 0;
  cout << "Put - 1 / Get - 2 / End - 0" << endl;
  int elem;
  cin >> j;
  while (j != 0)
  {
    switch (j)
    {
    case 1:
      if (help.IsFull())
      {
        cout << "Sorry. Stack is full" << endl;
        break;
      }

      cout << "Put: " << endl;
      cin >> elem;
      help.Put(elem);     
      break;
    case 2:
      if (help.IsEmpty())
      {
        cout << "Sorry. Stack is empty" << endl;
        break;
      }

      cout << "Get: ";
      cout << help.Get() << endl;
      break;
    default:
      break;
    }

    cout << "Enter your choice: ";
    cin >> j;
    if ((j < 0) || (j > 3))
    {
      cout << "!!! Incorrect value !!!" << endl;
      break;
    }
  }
  if (help.IsEmpty() == true)
    cout << "Stack is empty" << endl;
  else
    cout << "Stack is full" << endl;
  return 0;
}

