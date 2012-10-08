//Vasil Bozhurski XIa


#include <iostream>
using namespace std;

int x,y;

int xnn() {
    int p;
    do {
        cout << "Enter a positive int: ";
        cin >> p;
    }while(p<=0);
    return p;
}

void zad16() {
    x=xnn();
    int arr[10];
    int counter=0;
    for(int i=1; i<x; i=i+2) 
    {
        if(x%i==0) {
        arr[counter]=i;
        cout << "Arr[" << counter << "]=" << arr[counter] << endl;
        counter++;
        }
    }
    cout << "Prime deviders:" << endl;
    for(int i=0; i<counter; i++) {
        bool prime=1;
        for(int a=2; a<arr[i]; a++) if(arr[i]%a==0) prime=0;
        if(prime==1) cout << "Arr[" << i << "]=" << arr[i] << endl;
    }
    return;
}  

int main() {
    zad16();
    system("PAUSE");
}
