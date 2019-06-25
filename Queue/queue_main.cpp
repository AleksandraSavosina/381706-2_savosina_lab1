#include "Queue.h";
#include <iostream>

using namespace std;

int main()
{
  int n = 5;
  cout << "Enter size of queue: ";
  cin >> n;
  TQueue<int> help(n);
  int j = 0;
  cout << "Put - 1 / Get - 2 / End - 0" << endl;
  int elem;
  cin >> j;
  while (j != 0)
  {
    switch (j)
    {
      case 1:
        if (help.IsFull() == true)
        {
	  cout << "Sorry. Queue is full" << endl;
	  break;
	}
	  else
        {
          cout << "Put: " << endl;
          cin >> elem;
          help.Put(elem);
        }
      break;
    case 2:
      if (help.IsEmpty() == true)
      {
        cout << "Sorry. Queue is empty" << endl;
        break;
      }
      else
      {
        cout << "Get: ";
        cout << help.Get() << endl;
      }
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

  if (help.IsEmpty())
    cout << "Queue is empty" << endl;
  else
    cout << "Queue is full" << endl;
	
  return 0;

}
