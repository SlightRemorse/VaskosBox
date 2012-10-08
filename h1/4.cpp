//Vasil Bozhurski XIa


#include <iostream>
using namespace std;

int x,y;

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
    
void zad4() {
    do {
        cout << "Enter X [X>=0]: ";
        cin >> x;
    }while(x<0);
    do {
        cout << "Enter Y [Y>X]: ";
        cin >> y;
    }while(y<x);
    cout << "Results are: ";
    for(int i=x; i<=y; i++) cout << fibonacci(i) << ";";
    cout << endl;
    return;
}

int main() {
    zad4();
    system("PAUSE");
}
