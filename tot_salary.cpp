 #include<iostream>
 using namespace std;

 int main(){

  int basic;
    cout << "Enter the basic sallery :";
    cin >> basic;

    cout << "Tot. sallery = basic + hra + da + allow -pf" <<endl;

    char allow;
    cout << "Enter the grade:";
    cin >> allow;

    double ts=0,hra=0,da=0,pf=0;
    hra=0.2*basic;
    da=0.5*basic;
    pf=0.11*basic;
    ts= basic +hra +da -pf;

    if(allow == 'A'){
      ts = ts +1700 ;
    }else if(allow == 'B'){
      ts = ts +1500 ;
    }else{
      ts = ts +1300 ;
    }
    if ((ts+0.5)>=((int)ts+1))
        cout<<int(ts)+1;
        else 
        cout<<int(ts);
 
 }