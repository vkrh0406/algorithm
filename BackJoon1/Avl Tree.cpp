# include <iostream>

# include <stdlib.h>

# include <conio.h>

# include <fstream>

# include <time.h>



using namespace std;



const int N = 1000000; //백만으로

double key[N + 1] = { 0, };

double search_key[N + 1] = { 0, };



struct node

{

	double element;

	node *left;

	node *right;

	double height;

};



typedef struct node *nodeptr;



class avltree

{

	nodeptr root;

public:

	void insert(double, nodeptr &);

	void find(double, nodeptr &);

	double bsheight(nodeptr);

	nodeptr srl(nodeptr &);

	nodeptr drl(nodeptr &);

	nodeptr srr(nodeptr &);

	nodeptr drr(nodeptr &);

	double max(double, double);

	void init(int);

	void initSearch();

};





void avltree::insert(double x, nodeptr &p)

{

	if (p == NULL)

	{

		p = new node;

		p->element = x;

		p->left = NULL;

		p->right = NULL;

		p->height = 0;

		if (p == NULL)

			cout << "범위초과";

	}



	else

	{

		if (x<p->element)

		{

			insert(x, p->left);

			if ((bsheight(p->left) - bsheight(p->right)) == 2)

			{

				if (x < p->left->element)

					p = srl(p);

				else

					p = drl(p);

			}

		}



		else if (x>p->element)

		{

			insert(x, p->right);

			if ((bsheight(p->right) - bsheight(p->left)) == 2)

			{

				if (x > p->right->element)

					p = srr(p);

				else

					p = drr(p);

			}

		}



		else

			cout << "원소중복";

	}



	double m, n, d;

	m = bsheight(p->left);

	n = bsheight(p->right);

	d = max(m, n);

	p->height = d + 1;

}





void avltree::find(double x, nodeptr &p)

{

	if (p == NULL)

		cout << "탐색오류 ";



	else

		if (x < p->element)

			find(x, p->left);

		else

			if (x>p->element)

				find(x, p->right);

}





double avltree::max(double value1, double value2)

{

	return ((value1 > value2) ? value1 : value2);

}





double avltree::bsheight(nodeptr p)

{

	double t;

	if (p == NULL)

		return -1;

	else

	{

		t = p->height;

		return t;

	}

}





nodeptr avltree::srl(nodeptr &p1)

{

	nodeptr p2;

	p2 = p1->left;

	p1->left = p2->right;

	p2->right = p1;

	p1->height = max(bsheight(p1->left), bsheight(p1->right)) + 1;

	p2->height = max(bsheight(p2->left), p1->height) + 1;

	return p2;

}





nodeptr avltree::srr(nodeptr &p1)

{

	nodeptr p2;

	p2 = p1->right;

	p1->right = p2->left;

	p2->left = p1;

	p1->height = max(bsheight(p1->left), bsheight(p1->right)) + 1;

	p2->height = max(p1->height, bsheight(p2->right)) + 1;

	return p2;

}





nodeptr avltree::drl(nodeptr &p1)

{

	p1->left = srr(p1->left);

	return srl(p1);

}





nodeptr avltree::drr(nodeptr &p1)

{

	p1->right = srl(p1->right);

	return srr(p1);

}



void avltree::init(int k)

{

	ifstream file1, file2;

	root = NULL;



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

				insert(key[j], root);

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

				insert(key[j], root);

				j++;

				i = 0;

			}

		}

		file2.close();

	}

}



void avltree::initSearch()

{

	ifstream searchKeyFile;

	searchKeyFile.open("search_key.txt");



	double start_time;

	char searchCh;

	int i = 0; //4개씩 묶음만들기

	int j = 1; //묶음갯수



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

			if (root != NULL)

				find(search_key[j], root);

			j++;

			i = 0;

		}

	}



	cout << "AVL 트리 탐색의 실행 시간 (N = " << N << ") : " <<

		clock() - start_time << endl;

	cout << "탐색 완료." << endl;



	searchKeyFile.close();

}





void main()

{

	avltree avl;

	int input;



	cout << "원하는 파일의 숫자를 입력하세요" << '\n' << "1. sorted_dict 탐색" << '\n' << "2. dict 탐색" << endl;

	cin >> input;



	if (input == 1 || input == 2)

		avl.init(input);

	else

	{

		cout << "숫자를 잘못 입력했습니다." << endl;

		return;

	}



	cout << "insert finish" << endl;

	avl.initSearch();
	system("pause");
}

