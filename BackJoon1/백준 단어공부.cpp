#include <iostream>
#include <string>

char checkMaxChar(int sum[26])
{
	int max = sum[0];
	int pos = 0;
	for (int i = 1;i < 26;i++)
	{
		if (sum[i] > max) {
			max = sum[i];
			pos = i;
		}
	}
	int check = 0;
	for (int i = 0;i < 26;i++)
	{
		if (sum[i] == max)
			check++;
	}
	if (check >= 2)
		return '?';
	if (check == 1)
		return pos + 65;
}

using namespace std;
int main()
{
	char voca[1000000];
	cin >> voca;
	int aski = 65;
	int sum[26];

	for (int i = 0;i < 26;i++)
		sum[i] = 0;

	for (int i = 0;i < 26;i++)
	{
		
		for (int y = 0;voca[y] != '\0';y++)
		{
			
			if ((int)voca[y] == aski || (int)voca[y] == aski + 32)
			{
				sum[i]++;
			}
		}
		aski++;
	}
	cout<<checkMaxChar(sum);




	return 0;
}