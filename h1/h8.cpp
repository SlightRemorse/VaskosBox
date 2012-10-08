//Vasil Bozhurski XIa


#include <iostream>
#include <time.h>
#include <math.h>
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

void zad8() {
    xnt();
    int arr[10];
    long int b=0;
    int i=0;
    while(i<10) {
        arr[i]=fibonacci(b);
        b++;
        if(arr[i]%x==0) {
            i++;
            cout << arr[i-1] << ";";
        }
    }
    cout << endl;
return;
}         

int main() {
    zad8();
    system("PAUSE");
}
