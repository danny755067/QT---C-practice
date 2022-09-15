#include <iostream>
using namespace std;
class Sample {
public:
    int v /*,w ,z*/ ;
    // 在此处补充你的代码
    Sample(const Sample &a) {
        cout << "call the copy construct" << endl;
        cout << "v = " << v <<endl;
        v = a.v + 2;
        cout << "v after call the copy construct = " << v << endl;
    }
    Sample(int x) {
        cout << "v = " << v << endl;
        v = x ;
        cout << "v after x = " << v << endl;
    }
    Sample (){
        cout << "v before initial = " << v << endl;
        v = 5;
        cout << "v = " << v << endl;
    }
};
void PrintAndDouble(Sample o)
{
    cout << o.v;
    cout << endl;
}


int main()
{
    Sample a(5); //
    //cout << a.w << endl;
    //cout << a.z << endl;
    Sample b = a;        // 拷贝构造
    PrintAndDouble(b);
    Sample c = 20;
    PrintAndDouble(c);
    Sample d ;// 这里就是赋值，没有拷贝构造
    cout << d.v << endl;
    //cout << d.w << endl;
    //cout << d.z << endl;
    d = a;
    cout << d.v << endl;
    //cout << d.w << endl;
    //cout << d.z << endl;
    system("pause");
    return 0;
}
