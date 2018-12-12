#include <iostream>

using namespace std;

const int TRUE = 1;
const int FALSE = 0;

class PQ
{

	
public:
	int *heap, *info;
	int n;

	PQ(int size = 100) {
		heap = new int[size];
		info = new int[size];
		n = 0;
	}
	~PQ() { delete heap; }
	void insert(int v, int x);
	int remove();
	int isEmpty() { if (n == 0) return TRUE; else return FALSE; }
};

void PQ::insert(int v, int x)
{
	int i;
	n++;
	for (i = n; ; ) {
		if (i == 1) break;
		if (v >= heap[i / 2]) break;

		heap[i] = heap[i / 2];
		info[i] = info[i / 2];
		i /= 2;
	}
	heap[i] = v;
	info[i] = x;
}

int PQ::remove()
{
	int i, j, x, v, temp_v, temp_x;
	x = info[1];
	temp_v = heap[n];
	temp_x = info[n];
	n--;
	i = 1;
	j = 2;
	while (j <= n) {
		if (j < n && heap[j] > heap[j + 1]) j++;
		if (temp_v <= heap[j]) break;
		heap[i] = heap[j];
		info[i] = info[j];
		i = j;
		j *= 2;
	}
	heap[i] = temp_v;
	info[i] = temp_x;
	return x;
}

int index(char c)
{
	if (c == 32) return 0;
	else return (c - 64);
}
int indexDecode(int c)
{
	if (c == 0)
		return 32;
	else return c + 64;
}

int main()
{
	char text[100] = "VISION QUESTION ONION CAPTION GRADUATION EDUCATION";
	int count[100], dad[100], len[27], code[27];
	int huffman[400];
	PQ pq(100);
	int i, j, k, t, t1, t2, x, M = strlen(text), cnt = 0;

	for (i = 0; i < 100; i++) {
		count[i] = 0;
		dad[i] = 0;
	}
	for (i = 0; i < M; i++) count[index(text[i])]++;

	for (i = 0; i <= 26; i++)
		if (count[i]) pq.insert(count[i], i);

	for (; !pq.isEmpty(); i++) {
		t1 = pq.remove(); t2 = pq.remove();
		dad[i] = 0; dad[t1] = i; dad[t2] = -i;
		count[i] = count[t1] + count[t2];
		if (!pq.isEmpty()) pq.insert(count[i], i);
	}

	for (k = 0; k <= 26; k++) {
		i = 0; x = 0; j = 1;
		if (count[k])
			for (t = dad[k]; t; t = dad[t], j += j, i++)
				if (t < 0) {
					x += j; t = -t;
				}
		code[k] = x; len[k] = i;
	}


	for (int i = 0;i < 300;i++)  //허프만 코드 3으로 초기화
	{
		huffman[i] = 3;
	}
	k = 0; //허프만 코드 인덱스로 사용하기위해 초기화

	for (j = 0; j <= M; j++) {
		for (i = len[index(text[j])]; i > 0; i--) {
			cout << ((code[index(text[j])] >> i - 1) & 1);
			huffman[k++] = ((code[index(text[j])] >> i - 1) & 1);
			cnt++;
			if (cnt % 70 == 0) cout << endl;
		}
	}
	cout << endl;

	
	/*for (int i = 0; i < 300;i++)
	{
		cout << huffman[i] << endl;
	}*/
	

	//-------------------------------------------------------------------------------------
	//허프만 코드 디코딩 부분


	j = 41;
	for (int i = 0;i < 300;)
	{
		
		if (j <= 26)
		{
			
			char h = indexDecode(j);
			cout << h;
			j = 41;
		}
		if (huffman[i] == 3)
			break;

		k = j;
		if (huffman[i++] == 1)
			k *= -1;

		int tempcount = j;
		while (true)
		{
			tempcount--;

			if (dad[tempcount] == k) {
				j = tempcount;
				break;
			}
		}
	}


	return 0;
}