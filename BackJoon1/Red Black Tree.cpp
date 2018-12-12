#include <iostream>

#include <time.h>

#include <stdlib.h>

#include <fstream>



using namespace std;

const int black = 0;

const int red = 1;



const int N = 1000000;



double key[N + 1], search_key[N + 1];



struct node {

	int b;

	double key;

	struct node *l, *r;

	node(int bb, double k, struct node *ll, struct node *rr)

	{
		b = bb, key = k; l = ll, r = rr;
	};

} *head, *z, *gg, *g, *p, *x;



void split(double v);

struct node *rotate(double v, struct node *y);



class Dict

{

public:

	Dict() {

		z = new node(black, 0, 0, 0);

		z->l = z; z->r = z;

		head = new node(black, 0, 0, z);

	}

	double search(double search_key);

	void insert(double v);

	void init(int k);

	void initSearch();

};



double Dict::search(double search_key)

{

	struct node *x = head->r;

	while (x != z) {

		if (x->key == search_key) return x->key;

		x = (x->key > search_key) ? x->l : x->r;



	}

	return -1;

}



void Dict::insert(double v)

{

	x = head; p = head; g = head;

	while (x != z) {

		gg = g; g = p; p = x;

		if (x->key == v) return;

		x = (x->key > v) ? x->l : x->r;

		if (x->l->b && x->r->b) split(v);

	}

	x = new node(red, v, z, z);

	if (p->key > v) p->l = x;

	else p->r = x;

	split(v); head->r->b = black;

}



void split(double v)

{

	x->b = red; x->l->b = black; x->r->b = black;

	if (p->b) {

		g->b = red;

		if (g->key > v != p->key > v) p = rotate(v, g);

		x = rotate(v, gg);

		x->b = black;

	}

}



struct node *rotate(double v, struct node *y)

{

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





void Dict::init(int k)

{

	ifstream file1, file2;



	int i = 0; //4개씩 묶음만들기

	int j = 1; //묶음갯수

	char ch;



	if (k == 1)

	{

		file1.open("sorted_dict.txt");

		if (file1.is_open())

			cout << "open" << endl;

		else

			cout << "error" << endl;



		while (!file1.eof())

		{

			file1.get(ch); //파일에서 문자하나씩 얻기

			if (i<4)

				key[j] = key[j] * 1000 + (int)ch;

			i++;

			if (i == 5)

			{

				insert(key[j]);

				j++;

				i = 0;

			}

		}

		file1.close();

	}



	else if (k == 2)

	{

		file2.open("dict.txt");

		if (file2.is_open())

			cout << "open" << endl;

		else

			cout << "error" << endl;



		while (!file2.eof())

		{

			file2.get(ch); //파일에서 문자하나씩 얻기

			if (i<4)

				key[j] = key[j] * 1000 + (int)ch;

			i++;

			if (i == 5)

			{

				insert(key[j]);

				j++;

				i = 0;

			}

		}

		file2.close();

	}

}



void Dict::initSearch()

{

	ifstream searchKeyFile;

	searchKeyFile.open("search_key.txt");



	double start_time;

	char searchCh;

	int i = 0; //4개씩 묶음만들기

	int j = 1; //묶음갯수

	double result;



	if (searchKeyFile.is_open())

		cout << "open" << endl;

	else

		cout << "error" << endl;



	start_time = clock();



	while (!searchKeyFile.eof())

	{

		searchKeyFile.get(searchCh); //파일에서 문자하나씩 얻기

		if (i<4)

			search_key[j] = search_key[j] * 1000 + (int)searchCh;

		i++;

		if (i == 5)

		{

			result = search(search_key[j]);

			if (result == -1 || result != search_key[j]) {

				cout << "탐색 오류." << endl;

			}

			j++;

			i = 0;

		}

	}



	cout << "레드 블랙 트리의 실행 시간 (N = " << N << ") : " <<

		clock() - start_time << endl;

	cout << "탐색 완료." << endl;



	searchKeyFile.close();
	system("pause");
}





void main()

{

	Dict d;

	int input;



	cout << "원하는 파일의 숫자를 입력하세요" << '\n' << "1. sorted_dict 탐색" << '\n' << "2. dict 탐색" << endl;

	cin >> input;



	if (input == 1 || input == 2)

		d.init(input);

	else

	{

		cout << "숫자를 잘못 입력했습니다." << endl;

		return;

	}



	cout << "insert finish" << endl;

	d.initSearch();

}

