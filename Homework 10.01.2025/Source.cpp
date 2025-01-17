#include <iostream>  


using namespace std; 

int main() {
    system("chcp 1251>null");
    setlocale(LC_ALL, "uk_UA.UTF-8");
    srand(time(NULL));

    cout << "Перевірка української мови" << endl;

    cout << "Hello, World!" << endl;  
    return 0;  
}
