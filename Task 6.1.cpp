// Task 6.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ifstream fin;
    std::ofstream fout;

    fin.open("code.txt");
    fout.open("code_new.txt");

    std::string temp_string;
    bool not_write = false;  //Для многострочных
    bool skip_line = false;  //Для однострочных 
    bool protecte = false;

    bool del_chertu = false;
    int count_prot = 0;

    while (not fin.eof()) {
         getline(fin, temp_string);
         skip_line = false;
         
         for (auto iter = temp_string.begin(); iter != temp_string.end(); ++iter) {  // Ситуация //n - возможна

             
             if (not not_write and not skip_line and (*iter == '"') and not protecte) {
                 protecte = true;
             }
             
             if (protecte and *iter == '"') {
                 protecte = false;
                 if (iter != temp_string.begin()) {
                     if (*(iter - 1) == '\\') {
                         protecte = true;
                     }
                 }
             }

             if (not protecte and not not_write and not skip_line and (temp_string.end() - iter > 1)) {
                 if (*iter == '/' and *(iter + 1) == '/') {
                     skip_line = true;   //check one string comment
                 }
                 
                 if (not skip_line) {
                     if (*iter == '/' and *(iter + 1) == '*') {
                         not_write = true;
                     }
                 }
             }
             
             if (not protecte and (not_write) and (temp_string.end() - iter > 1)) {
                 if ((*iter == '*' and *(iter + 1) == '/')) {
                     std::cout << "it work" << std::endl;
                     not_write = false;
                     iter += 1; //добавим костыль
                     del_chertu = true;
                 }
                 if (not not_write and not skip_line and not (*iter == '\\') and (*iter == '"')) {
                     protecte = true;
                 }
             }

             if (not skip_line and not not_write) {
                 if (del_chertu) {
                 del_chertu = false;
                 }
                 else {
                     fout << *iter;
                 }
             }
             
         }
         fout << std::endl;
         
         }
    fin.close();
    fout.close();
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
