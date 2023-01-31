#include <iostream>
using namespace std;

class student{
    int rollNumber;
    string name;
    int age;
    
    public:
    student(int r, string n, int a){
        rollNumber=r;
        name=n;
        age=a;
    }

    //Copy Constructor
    student(student const &s){
        this->rollNumber=s.rollNumber;
        this->name=s.name;
        this->age=s.age;
    }

    void dispaly(){
        cout << "Roll Number is : " << rollNumber << endl;
        cout << "Name is : " << name << endl;
        cout << "Age is : " << age << endl;
    }
};

int main(){
    student s1(4,"Anurag",19);
    s1.dispaly();

    cout << "Copied details of a student are :" << endl;
    student s2(s1);
    s2.dispaly();
}