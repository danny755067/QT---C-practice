#include <iostream>

using namespace std;

int main()
{

    int* j = new int[]; //其實就是宣告int j[5];
    cout << &j[0] << endl;
    cout << j << endl; //等效上面一行地址
    cout << &j << endl; //這個不知道是什麼鬼地址
    delete j ;
    int *p;
    p = new int[];
    cout << &p[0] << endl;
    cout << p << endl; //等效上面一行地址
    cout << &p << endl;//這個不知道是什麼鬼地址
    delete p;
    return 0;
}

