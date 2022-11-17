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
//    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
//    ifstream fs("file1.txt", ios::binary); // открыли файл для чтения
//    if (!fs)
//    {
//        cout << "Файл не открыт\n\n";
//        return -1;
//    }
//    else {
//        //становимся в конец файла
//         fs.seekg(0, ios_base::end);
//        //Получаем текущую позицию
//        len = fs.tellg();
//        cout << "Размер файла (в байтах): " << len << endl;
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