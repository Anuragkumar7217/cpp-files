#include <iostream>
using namespace std;

int main(){
    char val;
    cout << "Krlo bkloli start : ";
    val = cin.get();

    int count_of_characters=0;
    int count_of_digits=0;
    int count_of_whitespaces=0;
    while(val != '$'){
        if(val == 'a' || val == 'b' || val == 'c' || val == 'd' || val == 'e' || val == 'f' || val == 'g' || val == 'h' || val == 'i' || val == 'j' || val == 'k' || val == 'l' || val == 'm' || val == 'n' || val == 'o' || val == 'p' || val == 'q' || val == 'r' || val == 's' || val == 't' || val == 'u' || val == 'v' || val == 'w' || val == 'x' || val == 'y' || val == 'z' ){
            count_of_characters++;
        }else if(val == '0' || val == '1' || val == '2' || val == '3' || val == '4' || val == '5' || val == '6' || val == '7' || val == '8' || val == '9'){
            count_of_digits++;
        }else if(val == ' ' || val == '\n' || val =='\t'){
            count_of_whitespaces++;   
        }
        
        val = cin.get();
    }
    cout << count_of_characters <<' ' << count_of_digits << ' ' << count_of_whitespaces;
}