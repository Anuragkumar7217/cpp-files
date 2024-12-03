#include <iostream>
using namespace std;

class Box{
    int l,b,h;
    
    public:
    Box(){
        l=0;
        b=0;
        h=0;
    }

    Box(int length, int breadth, int height){
        l=length;
        b=breadth;
        h=height;
    }

    //Copy Constructor
    Box(Box &s){
        this->l=s.l;
        this->b=s.b;
        this->h=s.h;
    }

    int getLength(){
        return l;
    }

    int getBreadth(){
        return b;
    }

    int getHeight(){
        return h;
    }

    long long CalculateVolume(){
        return (long long)(l*b*h);
    }

    bool operator <(Box B){
        if((l<B.l)||((b<B.b)&&(l==B.l))||((h<B.h)&&(l==B.l)&&(b=B.b)))
            return true;
        else
            return false;
    }

    friend ostream& operator<<(ostream& out, Box& B);
};

ostream& operator<<(ostream& out, Box& B) {
    out << B.l<<" "<< B.b<<" "<< B.h;
    return out;
}

int main(){
    Box s1(4,10,19);

    cout << "Copied details of a student are :" << endl;
    Box s2(s1);

    cout << s1;
}