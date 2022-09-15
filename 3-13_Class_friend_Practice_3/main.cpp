#include <iostream>
#include <string>

using namespace std;

//這是class將另一個class宣告成friend的練習
//要能互相訪問得互相都要宣告
//friend不能傳遞B是A的朋友，C是B的朋友，C沒有是A的朋友，要再宣告
class Girl;//要先宣告這個，因為下面class Boy裏頭會有宣告class Girl的東西然後compiler往上找看不懂，先創個這個應付他

class Boy{
    string name;
public:
    Boy(string nm){
        name = nm;
    }
    void IntroduceOneself(){
        cout << "I am " << name << endl;
    }
    void IntroduceFriend1(Girl &x);
    void IntroduceFriend2(Girl &x);
};
class Girl{
    string name;
    friend Boy; //這要丟哪都可以public也可，宣告友元關係
    //friend void Boy::IntroduceFriend1(Girl &x);
    //friend void Boy::IntroduceFriend2(Girl &x);用這樣也行
public:
    Girl(string nm){
        name = nm;
    }
    void IntroduceOneself(){
        cout << "I am " << name << endl;
    }
};
void Boy::IntroduceFriend1(Girl &x){
    cout << "My friend is "<< x.name << endl;
}
void Boy::IntroduceFriend2(Girl &x){
    cout << x.name <<" is my best friend " << endl;
}


int main()
{
    Boy boy("Danny");
    Girl girl("Rita");
    boy.IntroduceOneself();
    boy.IntroduceFriend1(girl);
    boy.IntroduceFriend2(girl);

    return 0;
}
