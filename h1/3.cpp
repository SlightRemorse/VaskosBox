//Vasil Bozhurski XIa


#include <iostream>
using namespace std;

int x,y;

void xny() {
    cout << "Enter X: ";
    cin >> x;
    do {
        cout << "Enter Y [Y>X]: ";
        cin >> y;
    }while(y<x);
}

void zad3() {
    xny();
    cout << "Results are: ";
    for(int i=x; i<=y; i++) if(i%10==3) {
        bool prime=1;
        for(int a=2; a<i; a++) if(i%a==0) prime=0;
        if(prime==1) cout << i << ";";
    }
    cout << endl;
    return;
}

int main() {
        zad3();
        system("PAUSE");
}
