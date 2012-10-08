//Vasil Bozhurski XIa


#include <iostream>
#include <math.h>
using namespace std;

int x,y;

void xnt() {
    do {
        cout << "Enter X [0<X<10]: ";
        cin  >> x;
    }while((x<1) || (x>9));
}

void zad5() {
    xnt();
    float arr[10];
    float swap;
    for(int i=0; i<10; i++) {
        arr[i]=cos(i);
        cout << "Arr[" << i << "]= " << arr[i] << endl;
    }
    for(int b=0; b<10; b++) {
        for(int i=9; i>b; i--) {
            if(arr[i]>arr[i-1]) {
                swap=arr[i];
                arr[i]=arr[i-1];
                arr[i-1]=swap;
            }
        }
    }
    cout << "After sorting:" << endl;
    for(int i=0; i<10; i++) cout << "Arr[" << i << "]= " << arr[i] << endl;
    return;
}        

int main() {
    zad5();
    system("PAUSE");
}
