#include <iostream>

using namespace std;
//可以這樣寫，以前沒寫過宣告型態後給值
void function(int *a = 0){
    cout << a<< endl;
}

int main()
{
    function();//地址會顯示000000000因為函數自己有做初始化
    int i;
    cout << &i<<endl;

    function(&i);//賦值就會蓋上去了
    return 0;
}
