#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, result, sum;
	cin >> n;
	sum = 0;
	for (int i = 0;i < n;i++)
	{
		string word;
		cin >> word;
		char ap[26];
		for(int i=0;i<26;i++)
			ap[i]=0;
		int index = 0;
		for(int i=0;i<word.length();i++)
		{
			if (i == 0) {
				index = word[i] - 97;
				result = 1;
			}
			else
			{
				if (word[i] != word[i - 1])
				{
					ap[index] = 1;
					index = word[i] - 97;
					if (ap[index] != 0)
					{
						result = -1;
						break;
					}
					else
						result = 1;

				}
				
			}

		}
		if (result == 1)
			sum++;

	}
	cout << sum;

	return 0;
}