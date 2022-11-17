#include <iostream>
#include <ctime>
#include <string.h>
#include <fstream>
#include <map>

using namespace std;
map<char, int> cipher = {
	{'�', 1}, {'�', 2}, {'�',3}, {'�',4}, {'�',5}, {'�',6}, {'�',7}, {'�',8}, {'�',9},
	{'�',10}, {'�',11}, {'�',12}, {'�',13}, {'�',14}, {'�',15}, {'�', 16}, {'�',17},
	{'�',18}, {'�',19}, {'�',20}, {'�',21}, {'�',22}, {'�',23}, {'�',24},{'�',25},
	{'�',26}, {'�',27}, {'�',28}, {'�',29}, {'�',30}, {'�',31}, {'�',32},{'�',33},
	{' ',34}, {'0',35}, {'1',36}, {'2',37}, {'3',38}, {'4',39}, {'5',40}, {'6',41}, {'7',42}, {'8',43}, {'9',44}
};
map<int, char> cipherD = {
	{1, '�'}, {2, '�'}, {3,'�'}, {4,'�'}, {5,'�'}, {6,'�'}, {7,'�'}, {8,'�'}, {9,'�'},
	{10,'�'}, {11,'�'}, {12,'�'}, {13,'�'}, {14,'�'}, {15,'�'}, {16,'�'}, {17,'�'},
	{18,'�'}, {19,'�'}, {20,'�'}, {21,'�'}, {22,'�'}, {23, '�'}, {24,'�'},{25,'�'},
	{26,'�'}, {27,'�'}, {28,'�'}, {29,'�'}, {30,'�'}, {31,'�'}, {32,'�'},{33,'�'},
	{34,' '}, {35,'0'}, {36,'1'}, {37,'2'}, {38,'3'}, {39,'4'}, {40,'5'}, {41,'6'}, {42,'7'}, {43,'8'}, {44,'9'}
};
int* C;
int len;

int mymod(int b, int n, int m) {
	int ost =1;
	for (int i = 1; i < n + 1; i++) 
		ost = (ost * b) % m;
	return ost;

}

void encrypt(int e, int n) {
	char* str;
	int Ti;
	ifstream fs("file.txt", ios::binary);
	fs.seekg(0, ios_base::end);
	len = fs.tellg();
	fs.seekg(0, ios_base::beg);
	str = new char[len];
	C = new int[len];
	fs.get(str, len + 1);
	for (int i = 0; i < len; i++) {
		C[i] = mymod(cipher[str[i]],e,n);
		cout << C[i] << ",";
	}
	cout << endl;

}

void decipher(int d, int n) {
	string res = "";
	for (int i = 0; i < len; i++) 
		res += cipherD[mymod(C[i],d, n)];
	cout << res << endl;
}

int primeNumber()
{
	int a, count;
	while (true) {
		count = 0;
		a = rand() %100 + 1;
		for (int i = 1; i < a + 1; i++)
			if (a % i == 0)
				count++;
		if (count == 2)
			break;
	}
	return a;
}

int chooseE(int n, int phi) {
	int e, count;
	while (true) {
		count = 0;
		e = rand() % (n - 1) + 1;
		for (int i = 1; i < e + 1; i++)
			if ((e % i == 0) & (phi % i == 0))
				count++;
		if (count == 1)
			break;
	}
	return e;
}

int chooseD(int e, int phi) {
	int d = 0, k = 1;
	do {
		d = k * phi + 1;
		k++;
	} while (d % e != 0);
	d /= e;
	return d;
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int e, n, d = 0, p, q, phi, comand = 0;
	p = primeNumber();
	q = primeNumber();
	//p = 7;
	//q = 13;
	n = p * q;
	phi = (p - 1) * (q - 1);
	e = chooseE(n, phi);
	//e = 5;
	d = chooseD(e, phi);
	while (comand != 3) {
		cout << "1 - �����������" << endl;
		cout << "2 - ������������" << endl;
		cout << "3 - �����" << endl;
		cin >> comand;
		switch (comand)
		{
		case 1: {
			cout << "�������� ���� (" << e << ", " << n << ")" << endl;
			encrypt(e, n);
			break;
		}
		case 2: {
			cout << "�������� ���� (" << d << ", " << n << ")" << endl;
			decipher(d, n);
			break;
		}
		default:
			break;
		}
	}
	return 0;
}