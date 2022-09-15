#include <iostream>
#include <string>

using namespace std;


//用日程表做練習
//把Class直接當成主Class的private member
//有個主要Class會初始化其他小Class

class Date{
public:
    Date(int y, int m, int d){
        cout << "Constructing Date ... "<<endl;
        year = y;
        month = m;
        day = d;
    }
    void Show(){
        cout <<"Year = "<<year<<" Month = "<< month<<" Day = "<<day<<endl;
    }
private:
    int year, month, day;
};

class Time{
public:
    Time(int h, int m, int s){
        cout <<"Constructing Time ... "<<endl;
        hour = h;
        minute = m;
        second = s;
        //cout <<year<<endl;//報錯，主Class的private class不可以訪問其他private member
    }
    void Show(){

        cout<<"Hour = "<<hour<<" Minute = "<< minute<<" Second = "<<second<<endl;
    }
private:
    int hour, minute, second;
};

class Schedule{
public:
    //初始化寫法
    Schedule(string w, int n, int a, int b, int c, int d, int e, int f):time(d, e, f),date(a, b, c)/*date(a,b,c),time(d,e,f)*//*這裡順序沒差*/{
        number = n;
        work = w;

    }
    void Show(){
        cout <<number<<endl;
        date.Show();
        time.Show();
        cout << work;
    }

private:
    int number;
    Date date;//創一個Date date然後去管理他，這裡創造的順序會影響構造函數產生順序(這個會先cout constucting)
    Time time;//創一個Time time然後去管理他，析構的時候會倒過來，這個會比date先析構
    string work;
};

int main()
{
    Schedule s("meeting", 1,2016, 7, 27, 15, 11, 11);
    s.Show();
    return 0;
}

