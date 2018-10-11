#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10000000
#define TRUE 1
#define FALSE 0
int b[N + 1];

void swap(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}
void CheckSort(int a[], int n)
{
	int i, Sorted;
	Sorted = TRUE;
	for (i = 1; i < n; i++)
	{
		if (a[i] > a[i + 1]) Sorted = FALSE;
		if (!Sorted) break;
	}
	if (Sorted) printf("정렬 완료\n");
	else printf("정렬 오류 발생. \n");

}

void InsertionSort(int a[], int n)
{
	int i, j;
	int v;
	for (i = 2; i <= n; i++)
	{
		v = a[i];
		j = i;

		while (a[j - 1] > v)
		{
			a[j] = a[j - 1];
			j--;

		}
		a[j] = v;
	}
}
void MergeGo(int a[], int l, int m, int r)
{

	int i = l;
	int j = m + 1;
	int k = l;
	
	while (i <= m && j <= r)
	{
		if (a[i] < a[j])
		{
			b[k] = a[i];
			k++;
			i++;
		}
		else {
			b[k] = a[j];
			k++;j++;
		}
	}
	if (i > m)
	{
		for (int p = j;p <= r;p++)
		{
			b[k] = a[p];
			k++;
		}
	}
	else
		for (int p = i;p <= m;p++)
		{
			b[k] = a[p];
			k++;
		}

	for (int p = l;p <= r;p++)
	{
		a[p] = b[p];
	}
	
}
void BubbleSort(int a[], int n)
{
	int i, j;
	for (i = n; i >= 1; i--)
	{
		for (j = 1; j < i; j++)
		{
			if (a[j] > a[j + 1])
				swap(a, j, j + 1);
		}
	}
}

void NatureMergeSort(int a[], int n)
{
	int i = 1;  //for
	int rumcount = 1;  //rum count
	int rum[N+1];
	rum[0] = 0;
	for (i = 1;i <= N;i++)
	{
		if (i == N) {
			rum[rumcount] = i;
			rumcount++;
		}
		else if (a[i] > a[i + 1])
		{
			rum[rumcount] = i;
			rumcount++;
		}
		
		

	}
	rumcount--;
	//printf("%d", rumcount);
	//for (int i = 1;i <= N;i++)
		//printf("%d ", rum[i]);

	while (1 < rumcount)
	{

		for (i = 1;i <= rumcount;i += 2)
		{
			MergeGo(a, rum[i - 1]+1, rum[i], rum[i + 1]);
		}
		int k = 1;

		for (i = 2;i <= rumcount;i += 2)
			rum[k++] = rum[i];
		if ((rumcount % 2) != 0)
			rum[k] = rum[i - 1];
		else
			k--;
		rumcount = k;
	}

	



}

void CockSort(int a[], int n)
{
	int j;
	int f = 1;
	while(n!=f)
	{
		for (j = f; j < n; j++)
		{
			if (a[j] > a[j + 1])
				swap(a, j, j + 1);
		}
		n--;
		if (n == f)break;
		for (j = n; j > f; j--)
		{
			if (a[j] < a[j - 1])
				swap(a, j, j - 1);
		}
		f++;
		
		
	}
	return;
}

void MergeSort(int a[], int l, int r)
{
	int m;
	
	if (r > l)
	{
		m = (r + l) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		MergeGo(a, l, m, r);
	}
}



void SelectionSort(int a[], int n)
{
	int i, j, min;
	for (i = 1; i < n; i++)
	{
		min = i;
		for (j = i + 1; j <= n; j++)
			if (a[j] < a[min]) min = j;

		swap(a, min, i);
	}
}

void QuickSort(int a[], int l, int r)
{
	int i;
	if (r > l)
	{
		i = partition(a, l, r);
		QuickSort(a, l, i - 1);
		QuickSort(a, i + 1, r);

	}
}
int partition(int a[], int l, int r)
{
	int v, i, j, temp;
	v = a[r];
	i = l - 1;
	j = r;

	for (;;)
	{
		do
		{
			i++;
		} while (a[i]<v);
		do
		{
			j--;
		} while (a[j]>v);
		if (i >= j) break;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;

	}
	temp = a[i];
	a[i] = a[r];
	a[r] = temp;
	return i;
}

int main()
{
	int i, a[N + 1];
	
	double start_time;
	a[0] = -1;
	srand(time(NULL));

	for (int k = 0; k < 2; k++) {
		for (i = 1; i <= N; i++) a[i] = rand();


		start_time = clock();
		//BubbleSort(a, N);
		//SelectionSort(a, N);
		//InsertionSort(a, N);
		//CockSort(a, N);
		NatureMergeSort(a, N);
		//MergeSort(a, 1, N);
		//QuickSort(a, 1, N);
		printf("선택 정렬의 실행 시간 (N=%d) : %.0f \n", N, clock() - start_time);
		/*for (i = 1; i <= N; i++) printf(" %d", a[i]);*/
		CheckSort(a, N);
	}

	return 0;

}

