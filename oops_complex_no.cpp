#include<bits/stdc++.h>
using namespace std;

class ComplexNumbers{
    private:
    int rn;
    int in;
    public:
    ComplexNumbers(int r, int i){
        rn=r;
        in=i;
    }
    void plus(ComplexNumbers const &c){
        rn=rn+c.rn;
        in=in+c.in;
    }
    void multiply(ComplexNumbers const &c){
        int temp=rn;
        rn=(rn*c.rn)-(in*c.in);
        in=(temp*c.in)+(in*c.rn);
    }
    void print(){
        string temp=(in>=0)?" + ":" - ";
        cout <<rn <<temp <<'i' <<in <<endl;
    }
};

int main(){
    int r1, i1, r2, i2;
    cin >>r1 >>i1;
    cin >>r2 >>i2;

    ComplexNumbers c1(r1,i1);
    ComplexNumbers c2(r2,i2);

    int choice;
    cin >>choice;

    if(choice==1){
        c1.plus(c2);
        c1.print();
        c2.print();
    }else if(choice==2){
        c1.multiply(c2);
        c1.print();
        c2.print();
    }else{
        return 0;
    }
}