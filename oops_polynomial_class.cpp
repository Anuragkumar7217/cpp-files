#include<bits/stdc++.h>
using namespace std;

class Polynomial {
    public:
    int *degCoeff;
    int capacity;

    Polynomial(){
        degCoeff=new int[5];
        capacity=5;
        for(int i=0; i<capacity; i++){
            degCoeff[i]=0;
        }
    }
    Polynomial(Polynomial const &p){
        degCoeff=new int[p.capacity];
        for(int i=0; i<p.capacity; i++){
            degCoeff[i]=p.degCoeff[i];
        }
        capacity=p.capacity;
    }
    void operator=(Polynomial const &p){
        degCoeff=new int[p.capacity];
        for(int i=0; i<p.capacity; i++){
            degCoeff[i]=p.degCoeff[i];
        }
        capacity=p.capacity;
    }
    void setCoefficient(int d, int c){
        if(d<capacity){
            degCoeff[d]=c;
        }else{
            int size=capacity;
            while(d>=size){
                size*=2;
            }
            int *temp=new int[size];
            for(int i=0; i<size; i++){    
                if(i<capacity){
                    temp[i]=degCoeff[i];
                }else{
                    temp[i]=0;    
                }
            }
            capacity=size;
            temp[d]=c;
            delete [] degCoeff;
            degCoeff=temp;
        }
    }
    Polynomial operator+(Polynomial const &p) const{
        Polynomial newp;
        newp.capacity=(capacity>p.capacity)?capacity:p.capacity;
        newp.degCoeff=new int[newp.capacity];
        for(int i=0; i<newp.capacity; i++){
            if(i<capacity && i<p.capacity)
            	newp.setCoefficient(i,degCoeff[i] +p.degCoeff[i]);
            else if(i<capacity)
                newp.setCoefficient(i,degCoeff[i]);
            else
                newp.setCoefficient(i,p.degCoeff[i]);
        }
        return newp;
    }
    Polynomial operator-(Polynomial const &p) const{
        Polynomial newp;
        newp.capacity=max(capacity,p.capacity);
        newp.degCoeff=new int[newp.capacity];
        for(int i=0; i<newp.capacity; i++){
            if(i<capacity && i<p.capacity)
            	newp.setCoefficient(i,degCoeff[i] -p.degCoeff[i]);
            else if(i<capacity)
                newp.setCoefficient(i,degCoeff[i]);
            else
                newp.setCoefficient(i,-p.degCoeff[i]);
        }
        return newp;
    }
    Polynomial operator*(Polynomial const &p) const{
        int x,y;
        for(int i=0;i<capacity;i++)
            if(degCoeff[i]!=0) x=i;
        for(int i=0;i<p.capacity;i++)
            if(p.degCoeff[i]!=0) y=i;
        Polynomial newp;
        newp.capacity=x+y+1;
        newp.degCoeff=new int[newp.capacity];
        for(int i=0;i<newp.capacity;i++)
            newp.degCoeff[i]=0;
        for(int i=0;i<capacity;i++){
            if(degCoeff[i]!=0){
                for(int j=0;j<p.capacity;j++){
                    if(p.degCoeff[j]!=0)
                    newp.degCoeff[i+j]+=degCoeff[i]*p.degCoeff[j]; //important
                }
            }
        }
        return newp;
    }
    void print(){
        for(int i=0; i<capacity; i++){
            if(degCoeff[i]!=0) cout << degCoeff[i] << "x" << i <<' ';
        }
        cout << endl;
    }
};

int main(){
    int count1, count2;
    cin >> count1;

    int *degree1=new int[count1];
    int *coeff1=new int[count1];

    for(int i=0; i<count1; i++){
        cin >> degree1[i];
    }

    for(int i=0; i<count1; i++){
        cin >> coeff1[i];
    }
    Polynomial first;
    for(int i=0; i<count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }

    cin >> count2;

    int *degree2=new int[count2];
    int *coeff2=new int[count2];

    for(int i=0; i<count2; i++){
        cin >> degree2[i];
    }

    for(int i=0; i<count2; i++){
        cin >> coeff2[i];
    }

    Polynomial second;
    for(int i=0; i<count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    first.print();
    second.print();
    
    int choice;
    cin >> choice;
    switch(choice){
        case 1:{
            Polynomial result1= first + second;
            result1.print();
            break;
        }
        case 2:{
            Polynomial result2= first - second;
            result2.print();
            break;
        }
        case 3:{
            Polynomial result3= first * second;
            result3.print();
            break;
        }
        case 4:{
            Polynomial third(first);
            (third.degCoeff == first.degCoeff)? cout<<"false"<<endl:cout<<"true"<<endl; 
            break;
        }
        case 5:{
            Polynomial fourth;
            fourth=first;
            (fourth.degCoeff == first.degCoeff)? cout<<"false"<<endl:cout<<"true"<<endl; 
            break;
        }
    }
}