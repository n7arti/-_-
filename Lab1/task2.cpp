#include <iostream>
#include <map>
#include <fstream>
using namespace std;

string encrypt(char** mas, int row) {
	char column;
	int buf;
	string result = "";
	ifstream fs("key.txt", ios::binary); // открыли файл для чтения
	if (!fs)
	{
		cout << "Файл не открыт\n\n";
	}
	else {
		for (int i = 0; i < 5; i++) {
			fs.get(column);
			buf = column - '0';
			for (int j = 0; j < row; j++) {
				result += mas[j][buf - 1];
			}
		}
	}
	fs.close();
	return result;
}

string decipher(char** mas, int row) {
	char column;
	int buf;
	char** convert;
	convert = new char* [row];
	for (int i = 0; i < row; i++) {
		convert[i] = new char[5];
	}
	string result = "";
	ifstream fs("key.txt", ios::binary); // открыли файл для чтения
	if (!fs)
	{
		cout << "Файл не открыт\n\n";
	}
	else {
		for (int i = 0; i < 5; i++) {
			fs.get(column);
			buf = column - '0';
			for (int j = 0; j < row; j++) {
				convert[j][buf - 1]= mas[j][i];
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < 5; j++)
				if (convert[i][j] != 'z')
					result += convert[i][j];
		}
	}
	fs.close();
	return result;
}

int main() {
	int len, column, row, comand;
	column = 5;
	string result;
	char** mas;
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	cout << "Выберите режим: " << endl;
	cout << "1 - Зашифровать" << endl;
	cout << "2 - Расшифровать" << endl;
	cin >> comand;
	switch (comand) {
	case 1: {
		ifstream fs("file1.txt", ios::binary); // открыли файл для чтения
		if (!fs)
		{
			cout << "Файл не открыт\n\n";
			return -1;
		}
		else {
			//становимся в конец файла
			fs.seekg(0, ios_base::end);
			//Получаем текущую позицию
			len = fs.tellg();
			fs.seekg(0, ios_base::beg);
			row = ceil((double)len / column);
			mas = new char* [row];
			for (int i = 0; i < row; i++) {
				mas[i] = new char[column];
			}
			char let;
			int buf;
			map <char, int> ::iterator it;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					fs.get(let);
					if ((i == row - 1) & (j > len % 5 - 1) & (len % 5 != 0))
						mas[i][j] = 'z';
					else
						mas[i][j] = let;
				}
			}
			result = encrypt(mas, row);
			cout << "Зашифрованная фраза: " << result << endl;

		}
		fs.close();
		break;
	}
	case 2: {
		ifstream fs("file2.txt", ios::binary); 
		if (!fs)
		{
			cout << "Файл не открыт\n\n";
			return -1;
		}
		else {
			fs.seekg(0, ios_base::end);
			len = fs.tellg();
			fs.seekg(0, ios_base::beg);
			row = ceil((double)len / column);
			mas = new char* [row];
			for (int i = 0; i < row; i++) {
				mas[i] = new char[column];
			}
			char let;
			int buf;
			map <char, int> ::iterator it;
			for (int j = 0; j < column; j++) {
				for (int i = 0; i < row; i++) {
					fs.get(let);
					mas[i][j] = let;
				}
			}
			result = decipher(mas, row);
			cout << "Расшифрованная фраза: " << result << endl;

		}
		fs.close();
		break;
	}
	}
	return 0;
}