#include<iostream>
using namespace std;
int main(){
    int x=10;
    int *p=&x;

    cout << sizeof(x) << endl;
    cout << sizeof(p) << endl;

    cout << &x << endl;
    cout << p << endl;
    cout << &p << endl;

    int *q=p;
    cout << p << endl;
    cout << *q << endl;

    int a[10];
    cout << a << endl;
    cout << &a[0] << endl;

    a[0]=15;
    cout << a[0] << endl;
    cout << *a << endl;

    int arr[6] = {1, 2, 3};
    int *b = arr;
    cout << *(b+1) << endl;

    char ch[]="abcd";
    char *c = &ch[0];
    cout << ch << endl;
    cout << c << endl;
}