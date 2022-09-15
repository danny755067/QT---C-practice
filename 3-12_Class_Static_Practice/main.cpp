#include <iostream>

using namespace std;

class Student{
    public:
        //1)int count;//做了一些測試 沒Static可以在main裡改他的值
        //int total;
        static int count;
        static double total;
        Student(double score){   //本身不能取跟member一樣的參數，但用this指針就行，做個練習
            this->score = score ;
            count++;
            total += score;//用this後compiler就分的清是哪個score了,這個是讀進來的score而非member
            //this->score = 50;測試出來不會顯示50
            //cout << score << endl;
        }
        //宣告static 就可透過類名來訪問
        static double getAverage(){
            return total/count ;
        }

    private:
        double score;
};
//---------------------------------------------------------------
//1)Student a;
//可以在Globla宣告然後在main可以用，但不知道會怎樣
//之前例子想調用Class都是在main裡宣告
//a.count = 10; //非法宣告不會過
//---------------------------------------------------------------
//2)Student a;//static + global Student測試 會報錯
//---------------------------------------------------------------
int Student::count = 0;//static成員初始化的正確方式
double Student::total = 0;//static成員初始化的正確方式


int main()
{
//---------------------------------------------------------------
    //a.count = 10; //1)宣告在Global非法QQ
    //cout << a.count << endl;
//---------------------------------------------------------------

    //a.count = 10;//2)globla宣告Student a ,public成員設static會報錯
    //cout << a.count << endl;
//---------------------------------------------------------------
    //Student a; //3)第三次測試測main裡宣告 非常正常 本來宣告class就合法
    //a.count = 10;//還是報錯
    //結論是static的成員要賦值要去global特殊宣告
    /*
    cout << "static member count's initial value : " ;
    cout << Student::count << endl;
    cout <<"static member total's initial value : ";
    cout << Student::total << endl;
    */
//---------------------------------------------------------------
    //Student s1(70);

    /*
    cout << Student::count << endl;
    cout << Student::total << endl;
    cout << s1.count << endl;
    cout <<s1.total << endl;
    */
//---------------------------------------------------------------
    //Student s2(80);

    /*
    cout << Student::count << endl;
    cout << Student::total << endl;
    cout << s2.count << endl;
    cout <<s2.total << endl;
    */

    //Static的參數會類似int global那樣，全部更改都會套用

//---------------------------------------------------------------
    Student s[3] = {Student(70), Student(80), Student(90)};

    cout << "Average score is : ";
    cout << Student::getAverage() << endl;//沒定義static就不能這樣用
    //cout << s1.getAverage() << endl;沒定義static就只能這樣透過某個對象取得average
    cout << Student::total << endl;
    cout <<Student::count << endl;
    cout << s[1].count << endl;

    //結論是你想用類名訪問 Student:: XXXXX這種格式要先宣告static,並且static的參數是全局參數(global)所有類的對象共享
    return 0;
}

