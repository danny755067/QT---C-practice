#include <iostream>
#include <string>

using namespace std;

class Student{
public:
    Student(string name, string id, char gender){
        this->name = name;
        this->id = id;
        this->gender = gender;
        name2 = "Kuo";
    }
    void showStudent(){
        cout<<"name:"<<name<<endl;
        cout<<"id:"<<id<<endl;
        cout<<"gender:"<<gender<<endl;
    }

    ~Student(){

    }
protected:
    string name2;//多設了一個protected的name
private:
    string name;
    string id;
    char gender;
};

class Employee{
public:
    Employee(string name, string job){
        this->name = name;
        this->job = job;
        name2 = "DannyKuo";
    }
    void showEmployee(){
        cout<<"name:"<<name<<endl;
        cout<<"job:"<<job<<endl;
    }
protected:
    string name2;
    string job;
private:
    string name;

};

class StudentHasJob:public Student,public Employee{
public:
    //基Class只有帶參數構造函數，得提供基Class初始化
    StudentHasJob(string name, string id, char gender, string job):Student(name, id, gender),Employee(name, job){

    }
    void showStudentHasJob(){
        //cout<<name<<endl;//會有兩個問題1.基class的private不能直接訪問(降階)2.繼承的兩個Class都有name這個private member會有岐義
        //cout<<name2<<endl;//會有岐義問題，可以採用成員名限定的方法
        showStudent();
        showEmployee();


        cout<<Student::name2<<endl;
        cout<<Employee::name2<<endl;
        //但沒有成員沒有經過static global化而且也不是public，所以要注意外部main裡不能用這種方式call東西
    }
};

int main()
{
    StudentHasJob s("Danny", "104070036", 'm', "RD");
    s.showStudentHasJob();
    return 0;
}

