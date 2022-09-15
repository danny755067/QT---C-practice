#include <iostream>
#include <string>

using namespace std;
class Person{
private:
    string name;
    int age;
public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
        cout<<"Person's constructor func"<<endl;
    }
    void showPerson(){
         cout<<"name:"<<name<<endl;
         cout<<"age:"<<age<<endl;
    }
};

class Student:public Person{
public:
    Student(string name, int age, char gender):Person(name, age){
        this->gender = gender;
        cout<<"Student's constructor func"<<endl;
    }
    void showStudent(){
        showPerson();
        cout<<"gender:"<<gender<<endl;
    }

    ~Student(){

    }

private:
    char gender;
};

class Employee:public Person{
public:
    Employee(string name, int age, string job):Person(name, age){
        this->job = job;
        cout<<"Employee's constructor func"<<endl;
    }
    void showEmployee(){
        showPerson();
        cout<<"job:"<<job<<endl;
    }
private:
    string name;
protected:
    string job;

};

class StudentHasJob:public Student,public Employee{
public:
    StudentHasJob(string name, int age, char gender, string job);/*:Student(name, age, gender),Employee(name, age, job){
        cout<<"StudentHasJob's constructor func"<<endl;
    }*/
    void showStudentHasJob(){
        showStudent();
        cout<<"Job:"<<job<<endl;

    }
};

//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
//自己試出來的，初始化可以只在Class裡寫一行構造函式的宣告(;結尾而非{})
//拉出來到外面初始化，跟QT平常的方式一樣，比較好懂
StudentHasJob::StudentHasJob(string name, int age, char gender, string job):Student(name, age, gender),Employee(name, age, job){
    cout<<"StudentHasJob's constructor func"<<endl;
}

int main()
{
    StudentHasJob s("Danny", 26, 'm', "RD");
    s.showStudentHasJob();
    //會看到Person的構造函數調用了兩次
    //創了s之後，compiler發現他是派生Class，會去調用base Class構造函數，先看到Class Student
    //調用Student發現他是派生Class，又會往上去調用base Class構造函數，發現是Person
    //所以先base Person構造->派生Student構造->派生StudentHasJob(還有base Class Employee)->Employee是派生(調用Person)->Employee->StudentHasJob

    //構造函數調用順序:Person->Student->Person->Employee->StudentHasJob
    return 0;
}
