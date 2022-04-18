#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>


int main()
{

    std::ifstream fin;
    std::ofstream fout;

    
    fout.open("test.txt");
    for (int i = 0; i < 10; i++) {
        fout << i << " " << "6666666" << std::endl;
    }
    fout.close();
    fin.open("test.txt");

    int N = 0;
    std::cout << "Input number of string" << std::endl;
    std::cin >> N;
    std::string temp_str; 
    int j = 0;
    while (not fin.eof()) {
        std::getline(fin, temp_str);
        if (j != N+1) { 
            j += 1;
        }
        if (j == N+1) {
            std::cout << "your string is: " << temp_str << std::endl;
            break;
        }
    }

    fin.close();
}
    



