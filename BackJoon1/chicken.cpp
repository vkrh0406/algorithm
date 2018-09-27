#include <iostream>

// 서울대 프로그래밍 13119번 문제 https://www.acmicpc.net/problem/13199

int chick(int coopon,int sc,int* cc,int nc, bool a)
{
	
	if (coopon < nc)
	{
		return coopon;
	}
	if (a == true)
		coopon = coopon - nc + sc;
	else if (a == false)
		coopon = coopon - nc;
	(*cc)++;
	if(a==true)
		chick(coopon,sc,cc,nc,true);
	else if(a==false)
		chick(coopon, sc, cc, nc, false);

	return 0;
}


using namespace std;
int main()
{
	int n;
	
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		int price, money, needCoopon, serviceCoopon;
		int cc, cc2;
		
		cin >> price >> money >> needCoopon >> serviceCoopon;
		if (needCoopon <= serviceCoopon)
			return -1;
		chick((money / price) * serviceCoopon, serviceCoopon, &cc, needCoopon,true);
		chick((money / price) * serviceCoopon, serviceCoopon, &cc2, needCoopon,false);
		
		cout<<cc - cc2<<endl;
	}




	return 0;

}


/* 정답

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
int tc;
scanf("%d", &tc);

while (tc--)
{
int p, m, f, c;
scanf("%d %d %d %d", &p, &m, &f, &c);

// a :: 상언 , b :: 두영
int bChicken = m / p;
int bCoupon = m / p * c;
bChicken += bCoupon / f;

int aChicken = m / p;
int aCoupon = m / p * c;

while(aCoupon / f > 0)
{
int total = aCoupon / f;
aChicken += total;
aCoupon = aCoupon - total * f + total * c;
}
printf("%d\n", aChicken - bChicken);
}

return 0;
}

*/