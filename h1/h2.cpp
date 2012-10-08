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

int zad2() {
    int res=0;
    xny();
    for(int i=x; i<=y; i++) if(i%17==0) res+=i;
    return res;
}

int main() {
    cout << zad2() << endl;
    system("PAUSE");
}
