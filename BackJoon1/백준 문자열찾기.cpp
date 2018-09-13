

#include <iostream>

using namespace std;
int main()
{
	int aski = 97;

	char word[101];
	int soo[26];
	cin >> word;
	int index;

	for (int i = 0;i < 26;i++)
		soo[i] = -1;

	for (int i = 0;word[i]!='\0';i++)
	{
		index = word[i] - 97;
		if (soo[index] == -1)
			soo[index] = i;

	}
	for (int i = 0;i < 26;i++)
		cout << soo[i] << ' ';

	
	cin >> word;
	return 0;
}
	