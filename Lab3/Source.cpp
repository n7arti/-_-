#include <iostream>
#include <ctime>
#include <string.h>
#include <fstream>
#include <map>
#include <vector>
const int infoImg = 54;
//const byte ByteEndMessage = 0xFF;
using namespace std;
void encode(char* inputImg, char* outputImg, string text, int size) {
	int count = infoImg + text.length() + 1;

	for (int i = 0; i < size; i++)
		outputImg[i] = inputImg[i];

	for (int i = size; i < count - 4; i++)
	{
		outputImg[i] = char (inputImg[i] & 0xFC);

		switch (outputImg[i] |= ((i - infoImg) % 4))
		{
		case 0: {
			char (text[(i - infoImg) / 4] >> 6 & 0x3);
			break;
		}
		case 1: {
			char (text[(i - infoImg) / 4] >> 4 & 0x3);
			break;
		}
		case 2: {
			char (text[(i - infoImg) / 4] >> 2 & 0x3);
			break;
		}
		case 3: {
			char (text[(i - infoImg) / 4] & 0x3);
			break;
		}
		}
	}

	for (int i = count - 4; i < count; i++)
		outputImg[i] |= 0x3;

}

string decode(char* img, int size) {
	string message ="";

	char _char = 0;
	for (int i = infoImg; i < size; i++)
	{
		switch (_char |= ((i - infoImg) % 4))
		{
		case 0: {
			char (img[i] & 3) << 6;
			break;
		}
		case 1: {
			char (img[i] & 3) << 4;
			break;
		}
		case 2: {
			char (img[i] & 3) << 2;
			break;
		}
		case 3: {
			char (img[i] & 3);
			break;
		}
		}

		if (_char == 0xFF)
			return message;

		if ((i - infoImg) % 4 == 3)
		{
			message += _char;
			_char = 0;
		}
	}
	return message;
}

int main() {
	size_t len;
	string text = "ABCDEFG";

	char* inputImg, * outputImg;

	ifstream fs("1.bmp", ios::binary);

	fs.seekg(0, ios_base::end);
	len = fs.tellg();
	fs.seekg(0, ios_base::beg);

	inputImg = new char[len];
	outputImg = new char[len];

	fs.read(inputImg, len);
	encode(inputImg, outputImg, text, len);
	fs.close();

	ofstream fout("2.bmp", ios::binary);
	for (int i = 0; i < len; i++)
		fout << outputImg[i];
	fout.close();

	text = decode(outputImg, len);
	cout << "Text: " << text << endl;
}