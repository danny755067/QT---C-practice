#include <iostream>
#include <string>
using namespace std;


class Point{
    int x, y;
public:
    Point(int a, int b){
        x = a;
        y = b;
    }
    Point(const Point &p){
        cout << "Copy Constructor"<<endl;
        x = p.x;
        x = p.y;
    }
    void set(int a, int b){
        x = a;
        y = b;
    }
    void show(){
        cout<< "( "<<x<<" . "<<y<<" )"<<endl;
    }
};

//函式在這
void fun1(Point point)//Point point = p 拷貝構造函數
{
    point.set(10, 10);
    cout <<"point's x and y are :";
    point.show();
}

void fun2(Point *point)//Point *point = &p 指標
{
    (*point).set(10, 10);
    //也可以寫成point->set(10,10);
    cout <<"point's x and y are :";
    (*point).show();
    //也可以寫成point->show();
}

int main()
{
    Point p(1,1);
    fun1(p);
    cout <<"p's x and y are :";
    p.show();
    fun2(&p);
    cout <<"p's x and y are :";
    p.show();
    return 0;
}

