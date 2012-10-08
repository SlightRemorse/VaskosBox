//Vasil Bozhurski XIa


#include <iostream>
using namespace std;

int x,y;

void xnt() {
    do {
        cout << "Enter X [0<X<10]: ";
        cin  >> x;
    }while((x<1) || (x>9));
}

int fibonacci(int a) {
    int x=0;
    int y=1;
    if(a<=1) return a;
    else for(int i=0; i<a; i++) {
        int sw=y;
        y=x+y;
        x=sw;
    }
    return y;
}

void zad15() {
    xnt();
    int arr[10];
    int num, c;
    c=0;
    for(int i=0; c<10; i++) {
        num=fibonacci(i);
        if(num%10==x) {
            cout << endl << num;
            bool prime=1;
            for(int a=2; a<num; a++) if(num%a==0) prime=0;
            if(prime==1) {
                cout << " (prime)";
                arr[c]=num;
                c++;
            }
        }
    }
    return;
}   

int main() {
    zad15();
    system("PAUSE");
}
