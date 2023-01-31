#include <iostream>
using namespace std;

class complexNo{
    int real;
    int imaginary;

    public:
    complexNo(int r, int i){
        real=r;
        imaginary=i;
    }
    complexNo operator*(complexNo const &c) const{
        int temp=real;
        int rn=(real*c.real)-(imaginary*c.imaginary);
        int in=(temp*c.imaginary)+(imaginary*c.real);
        complexNo comp(rn,in);
        return comp;
    }
    void print(){
        string temp=(imaginary>=0)?" + ":" - ";
        cout <<real <<temp <<'i' <<imaginary <<endl;
    }
};

int main(){
    complexNo c1(4,5), c2(3,4);
    c1.print();
    c2.print();

    complexNo c=c1*c2;
    c.print();
}