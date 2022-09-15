#include <iostream>
#include <string>

using namespace std;

//這是class跟class之間要訪問private member的friend宣告練習

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
    void IntroduceFriend(Girl &x);
};
class Girl{
    string name;
public:
    Girl(string nm){
        name = nm;
    }
    void IntroduceOneself(){
        cout << "I am " << name << endl;
    }
    friend void Boy::IntroduceFriend(Girl &x);
};
void Boy::IntroduceFriend(Girl &x){
    cout << "She is "<< x.name << endl;
}



int main()
{
    Boy boy("Danny");
    Girl girl("Rita");
    boy.IntroduceOneself();
    boy.IntroduceFriend(girl);

    return 0;
}

