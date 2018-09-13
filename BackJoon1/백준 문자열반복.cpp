#include <iostream>
#include <string>
using namespace std;
string testcase(string str, int r)
{
	string restr;
	for (int i = 0;i < str.length();i++)
	{
		for (int y = 0;y < r;y++)
		{
			restr += str[i];
		}
	}
	return restr;
}
int main()
{
	int t;
	cin >> t;

	for (int i = 0;i < t;i++)
	{
		int r;
		cin >> r;

		string str;
		cin >> str;

		cout << testcase(str, r) << endl;
	}
	
	return 0;
}