//#include <iostream>
//#include <map>
//#include <fstream>
//using namespace std;
//
//int main() {
//    int len;
//    
//    map< char, int > result;
//    multimap<char, int>::iterator it;
//    setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
//    ifstream fs("file1.txt", ios::binary); // ������� ���� ��� ������
//    if (!fs)
//    {
//        cout << "���� �� ������\n\n";
//        return -1;
//    }
//    else {
//        //���������� � ����� �����
//         fs.seekg(0, ios_base::end);
//        //�������� ������� �������
//        len = fs.tellg();
//        cout << "������ ����� (� ������): " << len << endl;
//        fs.seekg(0, ios_base::beg);
//        char let;
//        int buf;
//        map <char, int> ::iterator it;
//        for (int i = 0; i < len; i++) {
//            fs.get(let);
//            it = result.find(let);
//            if (it != result.end()) {
//                buf = it->second + 1;
//                result.at(let) = buf;
//            }
//            else {
//                result.insert(pair< char, int >(let, 1));
//            }
//        }
//        cout << endl;
//        for (pair< char, int > el:result) {
//            cout << el.first  << ": " << el.second << endl;
//        }
//    }
//    fs.close();
//	return 0;
//}