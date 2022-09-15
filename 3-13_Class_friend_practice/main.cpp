#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

class Point{
    int x, y;
public:
    Point(int a = 0, int b = 0){
        x = a;
        y = b;
    }
    void Show(){
        cout << "x = " << x <<"y = "<<y<<endl;
    }

    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    friend double Distance( Point &a1 ,  Point &a2);//申明友元丟private public protected隨便
    /*  //注意const要寫在後面
    int getX() const{
        return x;
    }
    int getY() const{
        return y;
    }
    */
    //若引用的參數要設const那只能去調用const函式 getx gety就要加const
};


//---------------------------------------------------------------------
//用傳對象的方式給參數
/*
double Distance(Point a1 , Point a2){
    return sqrt(pow((a1.getX()-a2.getX()), 2)+ pow((a1.getY()-a2.getY()), 2));
}
*/
//---------------------------------------------------------------------
//用引用的方式做個練習,Class裡的函示有沒有const好像都能調用沒報錯
/*
double Distance( Point &a1 ,  Point &a2){
    return sqrt(pow((a1.getX()-a2.getX()), 2)+ pow((a1.getY()-a2.getY()), 2));
}
*/
//---------------------------------------------------------------------
/*
double Distance(const Point &a1 ,const  Point &a2){
    return sqrt(pow((a1.getX()-a2.getX()), 2)+ pow((a1.getY()-a2.getY()), 2));
}
  //這邊加const會報錯，得在Class裡額外給他int getX() const才抓的到
*/
//---------------------------------------------------------------------



//friend的使用

//上面的方法一直call函式太花時間，換一個方法設friend直接訪問private member x,y
double Distance( Point &a1 ,  Point &a2){
    return sqrt(pow((a1.x-a2.x), 2)+ pow((a1.y-a2.y), 2));
}

int main()
{
    Point p1, p2(1,1);
    cout <<Distance(p1, p2);
    return 0;
}

