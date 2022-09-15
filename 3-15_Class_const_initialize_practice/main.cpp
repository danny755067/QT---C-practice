#include <iostream>
#include <string>
using namespace std;

//const 用法練習

class Student{
public:
    Student(string n, string i):name(n){
        //name = n; //從這邊給初始值會報錯，const 和別名類型都需要用初始化表 ':'來初始化
        id = i;
    }
    void showStudent(){
        cout <<"name:\t"<<name<<"\tid:\t"<<id<<endl;

    }
    //其實可以直接取一樣名字showStudent，const具有重載函數性質，但為了方便學習取不一樣的

    //☆☆☆☆☆☆☆☆☆☆☆
    //注意函式const要放後面，放void前面會報錯

    /*重載函數版本
    void showStudent() const{
        cout <<"name:\t"<<name<<"\tid:\t"<<id<<endl;
    }
    */
    void constshowStudent() const{
        cout <<"name:\t"<<name<<"\tid:\t"<<id<<endl;
        //modifyStudent(); //const函數也無法去call一般的函數會報錯
        //id = "10"; //會報錯，且不論一般Class無法調用這個const函數
        //const function也本身無法進行修改，因為const Class一開始初始化就把值固定了，後續也沒法改


    }

    void modifyStudent(){
       // name = "DannyJunior";//測試能不能修改初始化後的const值，會發現根本不能compile
       //表示const 值初始化後就被保護了不能再修改
        id = "70412";
    }
    string getName(){
        return name;
    }
private:
    const string name;//常數據成員
    string id;
};

int main()
{
    Student s1("Danny","104070036");
    s1.showStudent();
    s1.modifyStudent();//能修改id 因為不是const
    s1.showStudent();

    const Student s2("Rita","B7787");
    //s2.showStudent();//會報錯，因為S2是const class ，只能去調用裡面的const 函式，showStudent是普通的
    s2.constshowStudent();

    return 0;
}

