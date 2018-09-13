#include <iostream>

// 서울대 프로그래밍 13119번 문제 https://www.acmicpc.net/problem/13199

using namespace std;
int main()
{
	int n;

	cin >> n;

	for (int i = 0;i < n;i++)
	{
		int price, money, needCoopon, serviceCoopon;
		cin >> price >> money >> needCoopon >> serviceCoopon;

		int chicken = money / price;
		int hCoopon = chicken*serviceCoopon;
		int moreChick = hCoopon / needCoopon;
		hCoopon = hCoopon - (moreChick*needCoopon);
		hCoopon += moreChick*serviceCoopon;
		int moreChick2 =  hCoopon / needCoopon;
		cout << moreChick2 << endl;


	}



	return 0;

}