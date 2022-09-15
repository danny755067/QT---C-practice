#include <iostream>
#include <string>
using namespace std;

//派生Class的構造函數執行順序
//1.基Class的對象Class成員 2.基Class的構造函數 3.派生Class的對象成員(objectmember)的構造函數 4.派生Class的構造函數

//解構(析構)函數的執行順序(與構造顛倒)
//1.派生Class的解構函數 2.派生Class的對象成員的解構函數 3.基Class的解構函數 4.基Class的對象Class成員
class workDate{
    int year, month, day;
public:
    workDate(){
        cout<<"Person object's constructor func"<<endl;
    }

    workDate(int y, int m, int d){
        cout<<"Person object's constructor func with var"<<endl;
        year = y;
        month = m;
        day = d;
        cout<<"workDate:"<<year<<"-"<<month<<"-"<<day<<endl;
    }
    void showworkDate(){
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }
    ~workDate(){
        cout<<"Person object's destructor func"<<endl;
    }
};

class Person{                           //定義人類
public:
    //若沒構造函數compiler會自動預設一個不帶參數的
    /*
    Person(){
        cout <<"Class Person's constructor func"<<endl;
    }
    */
    //若派生的是不帶參數的，要調用基Class的構造，發現沒有不帶參數的構造函數會報錯
    //所以如果要讓compiler看懂並調用基Class帶參數的構造函數，要用到初始化表
    //wd1沒用初始化列表，所以會調用沒參數的構造函數，wd2有初始化2022/8/15，會調用有參數的構造函數
    Person(string n, int a):wd2(2022, 8, 15){
        cout<<"Class Person's constructor func with var"<<endl;
    }

    void setPerson(string n,int a){        //定義人類的姓名和年齡
        name = n;
        age = a;
    }
    void showPerson(){                  //顯示人類的姓名和年齡
        cout<<"Name = "<<name<<endl;
        cout<<"Age = "<<age<<endl;
    }
    //若沒解構函數compiler會自動預設一個不帶參數的
    ~Person(){
        cout<<"Class Person's destructor func"<<endl;
    }

private:
    workDate wd1;
    workDate wd2;
    string name;                        //private參數"姓名"
    int age;                            //private參數"年齡"
};



class Date{
    int year, month, day;
public:


    Date(int y, int m, int d){
        cout<<"Student object's constructor func with var"<<endl;
        year = y;
        month = m;
        day = d;
        cout<<"Date:"<<year<<"-"<<month<<"-"<<day<<endl;
    }
    void showWorkDate(){
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }
    ~Date(){
        cout<<"Student object's destructor func"<<endl;
    }
};

class Student:public Person{
private:
    //子Class只有帶參數的構造函數所以要記得用初始化表
    Date birthDay;
    Date entryDay;
    int grade;
public:
    //不帶參數派生Class要調用基Class帶參數要用初始化表
    /*
    Student():Person("Danny", 26){
        cout<<"Class Student's construct func"<<endl;
    }
    */
    //但上面這種方法很蠢，盡量還是統一比較好調用
    //若基Class只有帶參數的構造函數，要記得初始化，子Class也是一樣
    Student(string n, int a, int g):Person(n, a),birthDay(1996,2,15),entryDay(2016,9,1){
        cout<<"Class Student's construct func with var"<<endl;
    }

    void setStudent(string n, int a, int g){
        setPerson(n, a);
        grade = g;
    }
    void showStudent(){
        showPerson();
        cout<<"Grade = "<<grade<<endl;
    }
    ~Student(){
        cout<<"Class Student's destructor func"<<endl;
    }
};

int main()
{
    //開太多Class記憶體不夠Student s ("Danny", 26, 6)會被擋
    Student *s = new Student("Danny", 26, 6);
    //s.setPerson("Danny", 26); //繼承後public的func直接用也行
    //s.setStudent("Danny", 26, 6);
    //s.showPerson(); //同上註解
    //s.showStudent();
    delete s;
    return 0;
}

