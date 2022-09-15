#include <iostream>
#include <string>
using namespace std;

class Person{
    string name;
    int age;
public:
    void setPerson(string n, int a){
        name = n;
        age = a;
    }
    void showPerson(){
        cout <<"name: "<<name<<endl;
        cout <<"age: "<<age<<endl;
    }
};
//派生的class可以直接把基Class的成員函式都拿來用，還可以在這之上新增新的成員和函式
//但要記得private的成員就算是public繼承會降階變成"不能直接訪問"比private位階更低，需要透過間接方式取得
//比如說不能 在Student裡寫name = XX這種修改private成員的code，這類屬於直接訪問
//也不可在main裡寫s.name = XX
class Student:public Person{
    int grade;
public:
    void setStudent(string n, int a, int g){
        setPerson(n, a);
        grade = g;
    }
    void showStudent(){
        showPerson();
        cout << "grade: "<<grade<<endl;
    }

};

int main()
{
    Student s;
    s.setStudent("Danny", 26, 6);
    //s.showPerson(); //showPerson有被繼承，可以直接call來用
    s.showStudent();
    return 0;
}

