#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define N 100000
#define M 20
int b[N + 1];


void checksort(int a[], int n)
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


void swap(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void QuickSort(int a[], int l, int r)  //일반적인 퀵정렬 함수
{
	int i, j, v;
	if (r > l)
	{
		v = a[r];
		i = l - 1;
		j = r;
		for (;;)
		{
			while (a[++i] < v);
			while (a[--j] > v);
			if (i >= j) break;
			swap(a, i, j);
		}
		swap(a, i, r);
		QuickSort(a, l, i - 1);
		QuickSort(a, i + 1, r);
	}
}

void InsertionSort(int a[], int l, int r) // 작은 부분화일 퀵정렬에 필요한 삽입정렬함수
{
	int i, j, v;
	for (i = l + 1;i <= r;i++)
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

void QuickSort2(int a[], int l, int r) //작은 부분화일을 고려한 퀵 정렬 이때 #define M 20 이 선언되어 있어야함
{
	int i, j, v;
	if (r - l <= M)InsertionSort(a, l, r);
	else {
		v = a[r]; i = l - 1; j = r;
		for (;;) {
			while (a[++i] < v);
			while (a[--j] > v);
			if (i >= j) break;
			swap(a, i, j);
		}
		swap(a, i, r);
		QuickSort2(a, l, i - 1);
		QuickSort2(a, i + 1, r);
	}
}

void QuickSort3(int a[], int l, int r) //중간 값 분할을 사용한 퀵정렬
{
	int i, j, m, v;
	if (r - l > 1) {
		m = (l + r) / 2;
		if (a[l] > a[m])	swap(a, l, m);
		if (a[l] > a[r])	swap(a, l, r);
		if (a[m] > a[r])	swap(a, m, r);
		swap(a, m, r - 1);
		v = a[r - 1]; i = l; j = r - 1;
		for (;;) {
			while (a[++i] < v);
			while (a[--j] > v);
			if (i >= j) break;
			swap(a, i, j);
		}
		swap(a, i, r - 1);
		QuickSort3(a, l, i - 1);
		QuickSort3(a, i+1, r);
	}
	else if (a[l] > a[r]) swap(a, l, r);
}



void heapify(int a[], int h, int m)
{
	int j, v;
	v = a[h];
	for (j = 2 * h; j <= m; j *= 2) {
		if (j < m && a[j] < a[j + 1]) j++;
		if (v >= a[j]) break;
		else a[j / 2] = a[j];
	}
	a[j / 2] = v;
}

void HeapSort(int a[], int n) {//히프정렬
	int i;
	for (i = n / 2; i >= 1; i--)
		heapify(a, i, n);

	for (i = n - 1; i >= 1; i--) {
		swap(a, 1, i + 1);
		heapify(a, 1, i);

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
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}

	if (i > m)
		for (int p = j;p <= r;p++)
			b[k++] = a[p];
	else
		for (int p = i;p <= m;p++)
			b[k++] = a[p];



	for (int p = l;p <= r;p++)
		a[p] = b[p];

}


void NatureMergeSort(int a[], int n)
{
	int i = 1;  //for
	int runcount = 1;  //run count
	int run[N + 1];
	run[0] = 0;


	for (i = 1;i <= N;i++)  // run 만들기
	{
		if (i == N) {
			run[runcount] = i;

		}
		else if (a[i] > a[i + 1])
		{
			run[runcount] = i;
			runcount++;
		}

	}
	int mergecount = 0;

	while (TRUE)  //자연 병합 시작
	{

		for (i = 1;i <= runcount;i += 2)
		{
			MergeGo(a, run[i - 1] + 1, run[i], run[i + 1]);
			mergecount++;
		}
		int k = 1; //새로 만들 런 임시 인덱스

		for (i = 2;i <= runcount;i += 2)
			run[k++] = run[i];
		if ((runcount % 2) != 0)
			run[k] = run[i - 1];
		else
			k--;
		runcount = k;
		if (runcount <= 1)
		{
			printf("병합 횟수 : %d \n", mergecount);

			return;
		}
	}

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



int main()
{
	int i, a[N + 1];

	double start_time;
	a[0] = -1;
	srand(time(NULL));

	for (int k = 0; k < 1; k++) {

		//for (i = 1; i <= N; i++) a[i] = rand();

		//start_time = clock();
		////QuickSort2(a, 1, N);
		//HeapSort(a, N);
		//printf(" 일반적인 퀵정렬의 실행 시간 (N=%d) : %.0f \n", N, clock() - start_time);
		//checksort(a, N);
		//for (i = 1; i <= 100; i++) printf("%d ", a[i]);


		for (i = 1; i <= N; i++) a[i] = rand();
		start_time = clock();

		//cocksort(a, n);
		HeapSort(a, N);
		//mergesort(a, 1, n);

		printf("자연병합 정순 정렬의 실행 시간 (n=%d) : %.0f \n", N, clock() - start_time);
		/*for (i = 1; i <= n; i++) printf(" %d", a[i]);*/
		checksort(a, N);

		for (i = 1; i <= N; i++) a[i] = rand();
		start_time = clock();

		//cocksort(a, n);
		MergeSort(a,1,N);
		//mergesort(a, 1, n);

		printf("자연병합 정순 정렬의 실행 시간 (n=%d) : %.0f \n", N, clock() - start_time);
		/*for (i = 1; i <= n; i++) printf(" %d", a[i]);*/
		checksort(a, N);
		


		//for (i = 1; i <= N; i++) a[i] = rand();
		//start_time = clock();

		////CockSort(a, N);
		//NatureMergeSort(a, N);
		////MergeSort(a, 1, N);

		//printf("자연병합 랜덤 정렬의 실행 시간 (N=%d) : %.0f \n", N, clock() - start_time);
		///*for (i = 1; i <= N; i++) printf(" %d", a[i]);*/
		//checksort(a, N);



	}

	return 0;

}

