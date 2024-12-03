#include<bits/stdc++.h>
#include<climits>
#include<cstring>
#include<string>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], index=0;
    for(int i=2; i<n; i++){
        for(int j=2; j<i; j++){
            if(i%j!=0){
                a[index]=i;
                index++;
                break;
            }
        }
    }
    for(int i=0; i<index; i++){
        cout << a[i] << ' ';
    }
}

// diplay element of queue using linked list

/*
class hashTable1{
    public:
    vector<pair<int,int>> table;

    hashTable1(){
        for(int i=0; i<100; i++){
            table[i].first=0;
            table[i].second=0;
        }
    }

    int hasFuction(int key){
        return key%100;
    }

    void insert(int key, int value){
        int index=hasFuction(key);
        table[index].first=key;
        table[index].second=value;
    }

    int search(int key){
        int index=hasFuction(key);
        if (table[index].first == key) return table[index].second;
        else return -1;
    }


};

int main() {
    hashTable1 h;
    h.insert(20,200);
    h.insert(30,300);
    h.insert(40,400);
    h.insert(50,500);
    h.insert(60,600);

    cout << h.search(20) << endl;
    cout << h.search(10) << endl;
    cout << h.search(50) << endl;
}
*/


/*
// define a function to create a max heap from an array of numbers
void create_max_heap(int nums[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }

        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(nums[i], nums[largest]);
            create_max_heap(nums, n);
        }
    }
}

// define a function to perform heap sort on an array of numbers
void heap_sort(int nums[], int n) {
    create_max_heap(nums, n);

    for (int i = n-1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        create_max_heap(nums, i);
    }
}

int main() {
    // take input from user for ten numbers
    int nums[10];
    for (int i = 0; i < 10; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> nums[i];
    }

    // create a max heap from the given numbers
    create_max_heap(nums, 10);

    // print the max heap
    cout << "Max Heap:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // sort the numbers using heap sort
    heap_sort(nums, 10);

    // print the sorted numbers
    cout << "Sorted numbers using Heap Sort:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << nums[i] << " ";
    }
}
*/

    /*
    int a=5.7, b=8.2;
    cout << max(a,b) << endl;
    cout << min(a,b) << endl;
    cout << (a<b)?a:b;
    if(cout<<"naman"<<endl)

    cout << ceil(8.2) <<endl;
    cout << ceil(2.9) <<endl;
    cout << floor(8.2) <<endl;
    return 0;
    */

    /*
    string *a;
    a=new string;
    cin >>*a;
    cout <<*a <<endl;
    */

    /*
    string s;
    cin >>s;
    int first=s[0]-'0';
    char firstchar=first+'a'-1;
    cout << firstchar;
    */

    /*int n=2;
    (n==2) ? cout << "true" : cout << "false";
    */

    /*string ch="a";
    int a;
    cout << ch << endl;
    cout << a << endl;
    string arr="abcdef";
    cout << arr[1] << endl;

    string map[10]={" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int count=map[1].size();    
    cout << count << endl;
    cout << map[2].substr(1) << endl;
    */

    /*int n = 2;
    int ans = (n==2) ? 99 : 1;
    cout << ans << endl;

    double x=1.543;
    x = 1.50 +1/4;
    cout << x << endl;

    float a = 1/4;
    cout << a << endl;
    cout << (double)1/4 << endl;

    cout << 1/pow(2,2) << endl;
    cout << 1/pow(2,0) << endl;
    */


/*
int main()
{
    int a;
    double d;
    char ch;
    cin >> a >> d >> ch;
    cout << a <<' ' << d << ' ' << ch << endl;
    
    unsigned int c = -97;
    cout << c <<endl;

    bool defaultval;
    cout << defaultval;

    /*double a = 1.5;
    int b  = 6/4;
    double c = a + b;
    cout << c;
    */

    /* double a = 55.5;
    int b = 55;
    a = a % 10;
    b = b % 10;
    cout << a << " "  << b;
    */

   /* int x = 10;
    int y = 20;
    if(++x > 10 && y++ > 20 ){
    cout << "Inside if ";
    } else{
    cout << "Inside else ";
    }
    cout << x << ' ' << y;
    */

   /* int a = 10;
    if(a > 5) {
        int a = 100;
    }
    else {
        int a = 110;
    }
    cout << a << endl;
    */
//}

   /*
   int main(){
       float i=1;

    cout << sizeof(int) << endl;
    cout << sizeof(float) << endl;       
    cout << sizeof(char) << endl;
    cout << sizeof(double) << endl;
   }
   */


/*void arrange(int a[], int n){
    int i=0,j=n-1, val=1;
    while(i<j){
        a[i]=val;
        val++;
        a[j]=val;
        val++;
        i++;
        j--;
    }*/

    /*int main(){
        int a=10, b=20; 
        cout << max(a,b) << endl;

        int swap=NULL;
        cout << swap << endl;
        
        cout << INT_MIN << endl;
        cout << INT_MAX << endl;

        int n=5;
        int temp[n]={0};
        for(int i=0; i<5; i++){
            cout << temp[i] << ' ';
        }
        cout << endl;
    }*/

/*int main(){
    char str[10];
    cin >> str;
    cout << str << endl;

    char copy[10];
    int i=0;
    for(; str[i]!='\0'; i++)
    {
        copy[i]=str[i];
    }
    copy[i]='\0';
    cout << copy;
}*/

/*int main(){
    string str;
    cin >> str;
    cout << str << endl;

    int len1 = str.length();
    int len2 = str.size();
    cout << len1;
    cout << len2;
}*/