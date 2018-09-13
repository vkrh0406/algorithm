#include <iostream>
#include <string>

using namespace std;
int main()
{
	int n;
	int stack[100000];
	int index = 0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		char command[10001];
		cin >> command;

		if (strcmp(command, "push") == 0)
		{
			int value;
			cin >> value;
			index++;
			stack[index] = value;
			

		}
		else if (strcmp(command, "pop") == 0)
		{
			if (index != 0)
			{
				
				cout << stack[index] << endl;
				index--;
			}
			else
				cout << "-1" << endl;
		}
		else if (strcmp(command, "size") == 0)
		{
			cout << index << endl;
		}
		else if (strcmp(command, "empty") == 0)
		{s
			if (index == 0)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (strcmp(command, "top") == 0)
		{
			if (index != 0)
			{
				
				cout << stack[index] << endl;
			}
			else
				cout << "-1" << endl;
		}
	}



	return 0;
}