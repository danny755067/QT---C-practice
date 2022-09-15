#include <iostream>
#include <string>
using namespace std;
//學習公有(public)繼承、保護(protected)繼承、私有(private)繼承的差異
//權限:public>protected>private>不可直接訪問
//權限不夠的會被下拉到繼承的權限，protected繼承，基class public的東西會變成protected
//private繼承，基class public的東西會變成private,protected的東西也變成private


//☆☆☆☆☆☆☆☆繼承表☆☆☆☆☆☆☆☆☆
//private member:不管怎麼繼承，直接降階成"不能直接訪問"
//protected member:public繼承=>protected
                 //protected繼承=>protected
                 //private繼承=>降階成private
//public member:public繼承=>public
              //protected繼承=>降階成protected
              //private繼承=>降階成private
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆

class Person{
private:
    string name;
protected:
    int age;
public:
    void setPerson(string n , int a){
        name = n;
        age = a;
    }
    void showPerson(){
        cout<<"name: "<<name<<endl;
        cout <<"age: "<<age<<endl;
    }
};

//public繼承---------------------------------------
class Student1:public Person{
    int grade;
public:
    void setStudent(string n, int a, int g){
        setPerson(n, a);
        //cout << name;//報錯，name被從private降階成"不能直接訪問
        //cout << age<<endl;//protected,可以訪問
        //name = n;//private成員被降階成"不能直接訪問"，不能在Student裡寫name = XX這種修改private成員的code，這類屬於直接訪問
        //age = a;//age是protected成員，public繼承後還是protected，可以訪問
        //age = 18;//age可以改
        grade = g;
    }
    void showStudent(){
        showPerson();
        cout<<"grade: "<<grade<<endl;
    }
};
//--------------------------------------------------

//protected繼承---------------------------------------
class Student2:protected Person{
    int grade;
public:
    void setStudent(string n, int a, int g){
        setPerson(n, a);//這變成protected function,派生可以調用
        cout << age<< endl;//派生class可以訪問protected,name降階成"不能直接訪問"不行
        grade = g;
    }
    void showStudent(){
        showPerson();//這變成protected
        cout<<"grade: "<<grade<<endl;
    }
};
//--------------------------------------------------

//private繼承---------------------------------------
class Student3:private Person{
    int grade;
public:
    void setStudent(string n, int a, int g){
        setPerson(n, a);//這變成private function,派生可以調用
        cout << age<< endl;//age從protected降階成private，派生class可以訪問private,name降階成"不能直接訪問"
        grade = g;
    }
    void showStudent(){
        showPerson();//這變成private function,派生可以調用
        cout<<"grade: "<<grade<<endl;
    }
};
//--------------------------------------------------
int main()
{
    Student1 s1;
    cout << "-------public practice-------"<<endl;
    s1.setStudent("Danny", 26, 6);
    s1.showStudent();
    s1.setPerson("Rita", 31);//setPerson是public可以訪問
    //cout<<s1.name<<endl;//不行直接訪問，會報錯
    //cout<<s1.age<<endl;//也不行直接訪問


//--------------以上public繼承練習-------------
    Student2 s2;
    cout << "-------protected practice-------"<<endl;
    s2.setStudent("Danny", 26, 6);
    s2.showStudent();
    //s2.setPerson("Rita", 31);//這變成protected不能訪問了，main裡只能訪問public
//--------------以上protected繼承練習-------------
    Student3 s3;
    cout << "-------private practice-------"<<endl;
    s3.setStudent("Danny", 26, 6);
    s3.showStudent();
    //s3.setPerson("Rita", 31);//這變成private不能訪問了，main裡只能訪問public
//--------------以上private繼承練習-------------

    return 0;
}

