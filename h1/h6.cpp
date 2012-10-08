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

void zad6() {
    xnt();
    int helper;
    int arr[100];
    cout << "Unsorted:" << endl;
    for(int i=0; i<100; i++) {
        arr[i]=rand()%101;
        cout << arr[i] << ";";
    }
    cout << endl << "Sorted:" << endl;
    for(int i=0; i<100; i++) if(arr[i]%10==x) for(int a=0; a<i; a++) if(arr[a]%10!=x) {
        helper=arr[a];
        arr[a]=arr[i];
        arr[i]=helper;
    }
    for(int i=0; i<100; i++) cout << arr[i] << ";";
    cout << endl;    
    return;
}

int main() {
        srand(time(NULL));
        zad6();
        system("PAUSE");
}
