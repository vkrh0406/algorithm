#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

struct node {
	int key;
	struct node *l, *r;
};

struct node *head, *z;

int search(int search_key)
{
	struct node *x = head->r;
	while (x != z)
	{
		if (x->key == search_key) return x->key;
		x = (x->key > search_key) ? x->l : x->r;

	}
	return -1;
}

void insert(int v)
{
	struct node *p, *x;

	p = head; x = head->r;
	while (x != z)
	{
		p = x;
		if (x->key == v) return;
		x = (x->key > v) ? x->l : x->r;
	}
	x = (struct node*)malloc(sizeof(struct node));
	x->key = v; x->l = z; x->r = z;

	if (p->key > v) p->l = x;
	else p->r = x;
}

void init(int key[], int search_key[])
{
	int i, index, temp[N + 1];

	for (i = 1; i <= N; i++)
	{
		key[i] = i;
		search_key[i] = i;
		temp[i] = 0;

	}
	srand(time(NULL));
	for (i = 1; i <= N; i++)
	{
		index = rand() % N + 1;
		if (temp[index] == 0)
			temp[index] = key[i];
		else {
			while (temp[index] != 0)
			
				index = (index%N) + 1;
				temp[index] = key[i];
			
		}
	}
	for (i = 1; i <= N; i++) key[i] = temp[i];
}
void main()
{
	int i, result, key[N + 1], search_key[N + 1];
	double start_time;

	z = (struct node*)malloc(sizeof(struct node));
	z->l = z; z->r = z;

	head = (struct node*)malloc(sizeof(struct node));
	head->key = 0; head->r = z;

	init(key, search_key);
	for (i = 1; i <= N; i++) insert(key[i]);
	start_time = clock();
	for (i = 1; i <= N; i++)
	{
		result = search(search_key[i]);
		//if (result = -1 || result != search_key[i])
			//printf("탐색 완료. \n");

	}
	printf("이진 트리 탐색의 실행 시간 (N=%d) : %.0f\n", N, clock() - start_time);
	printf("탐색완료");
	system("Pause");
}