#include <stdio.h>
#include <stdlib.h>	
#include <time.h>
#include <fstream>

#define black 0
#define red 1
#define N 1000000

struct node {
	int b;
	int key;
	struct node *l, *r;
}*head, *z, *gg, *g, *p, *x;

void split(int v);

struct node *rotate(int v, struct node *y);

int search(int search_key)
{
	struct node *x = head->r;

	while (x != z) {
		if (x->key == search_key) return x->key;
		x = (x->key > search_key) ? x->l : x->r;
	}
	return -1;
}

void insert(int v) 
{
	x = head; p = head; g = head;
	while(x != z) {
		gg = g; g = p; p = x;
		if (x->key == v) return;
		x = (x->key > v) ? x->l : x->r;
		if (x->l->b && x->r->b) split(v);
	}

	x = (struct node*)malloc(sizeof(struct node));
	x->b = red; x->key = v;
	x->l = z; x->r = z;
	if (p->key > v) p->l = x;
	else p->r = x;
	split(v);
	head->r->b = black;
}

void split(int v)
{
	x->b = red; x->l->b = black; x->r->b = black;
	if (p->b) {
		g->b = red;
		if (g->key > v != p->key > v) p = rotate(v, g);
		x = rotate(v, gg);
		x->b = black;
	}
}

struct node* rotate(int v, struct node *y) {
	struct node *gc, *c;
	c = (y->key > v) ? y->l : y->r;

	if (c->key > v) {
		gc = c->l; c->l = gc->r; gc->r = c;
	}
	else {
		gc = c->r; c->r = gc->l; gc->l = c;
	}
	if (y->key > v) y->l = gc;
	else y->r = gc;
	return gc;
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
	for (i = 1; i <= N; i++) {
		index = rand() % N + 1;
		if (temp[index] == 0)
			temp[index] = key[i];
		else {
			while (temp[index] != 0) 
			index = (index % N) + 1;
			temp[index] = key[i];			
		}
	}
	for (i = 1; i <= N; i++)
		key[i] = temp[i];
}

int main()
{
	int i, result, key[N + 1], search_key[N + 1];
	double start_time;

	z = (struct node*)malloc(sizeof(struct node));
	z->b = black; z->key = 0;
	z->l = z; z->r = z;

	head = (struct node*)malloc(sizeof(struct node));
	head->b = black; head->key = 0;
	head->l = 0; head->r = z;

	init(key, search_key);
	for (i = 1; i <= N; i++) insert(key[i]);
	start_time = clock();
	for (i = 1; i <= N; i++) {
		result = search(search_key[i]);
		if (result == -1 || result != search_key[i])
			printf("탐색 오류.\n");
	}
	printf("레드 블랙 트리의 실행시간 (N = %d) : %.0f\n", N, clock() - start_time);

	printf("탐색 완료. \n");
	system("pause");
}
