#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream> 

using namespace std;

const int N = 1000000; //�鸸����

double key[N + 1] = { 0, };

double search_key[N + 1] = { 0, };



class Dict

{

public:

	Dict() {

		z = new node(0, 0, 0);

		z->l = z; z->r = z;

		head = new node(0, 0, z);

	}

	double search(double search_key);

	void insert(double v);

	void init(int k);

	void initSearch();

private:

	struct node {

		double key;

		struct node *l, *r;

		node(double k, struct node *ll, struct node *rr)

		{
			key = k; l = ll, r = rr;
		}

	};

	struct node *head, *z;

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

	struct node *p, *x;

	p = head; x = head->r;

	while (x != z) {

		p = x;

		if (x->key == v) return;

		x = (x->key > v) ? x->l : x->r;

	}

	x = new node(v, z, z);

	if (p->key > v) p->l = x;

	else p->r = x;

}



void Dict::init(int k)

{

	ifstream file1, file2;



	int i = 0; //4���� ���������

	int j = 1; //��������

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

			file1.get(ch); //���Ͽ��� �����ϳ��� ���

			if (i<4)

				key[j] = key[j] * 1000 + (int)ch;

			i++;

			if (i == 5)

			{

				//d.insert(key[j]);

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

			file2.get(ch); //���Ͽ��� �����ϳ��� ���

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

	int i = 0; //4���� ���������

	int j = 1; //��������

	double result;



	if (searchKeyFile.is_open())

		cout << "open" << endl;

	else

		cout << "error" << endl;



	start_time = clock();



	while (!searchKeyFile.eof())

	{

		searchKeyFile.get(searchCh); //���Ͽ��� �����ϳ��� ���

		if (i<4)

			search_key[j] = search_key[j] * 1000 + (int)searchCh;

		i++;

		if (i == 5)

		{

			result = search(search_key[j]);

			if (result == -1 || result != search_key[j]) {

				cout << "Ž�� ����." << endl;

			}

			j++;

			i = 0;

		}



	}



	cout << "���� Ʈ�� Ž���� ���� �ð� (N = " << N << ") : " <<

		clock() - start_time << endl;

	cout << "Ž�� �Ϸ�." << endl;

	


	searchKeyFile.close();
	system("pause");

}



void main()

{

	Dict d;

	int input;



	cout << "���ϴ� ������ ���ڸ� �Է��ϼ���" << '\n' << "1. sorted_dict Ž��" << '\n' << "2. dict Ž��" << endl;

	cin >> input;



	if (input == 1 || input == 2)

		d.init(input);

	else

	{

		cout << "���ڸ� �߸� �Է��߽��ϴ�." << endl;

		return;

	}



	cout << "insert finish" << endl;

	d.initSearch();

}
