#include <iostream>
using namespace std;

class Student {
    int rollNumber;
    public:
    char name[10];
    int age;
};

int main() {
    Student s;
    Student *sd=new Student;
    //s.rollNumber=52;
    s.age=18;
    cin >>s.name;
    cin >>(*sd).name;
    cout <<s.name <<endl;
    cout <<s.age <<endl;
    cout <<(*sd).name <<endl;
}