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

void zad12() {
    xnt();
    int arr[10];
    int sum, prev;
    prev=-1;
    for(int b=0; b<10; b++) {
        for(int i=0; i>-1; i++) {
            if((i%x==0) && (i>prev)) {
                prev=i;
                break;
            }
        }
        sum=0;
        for(int a=0; a<=prev; a++) sum+=a;
        arr[b]=sum;
        cout << "arr[" << b << "]=" << arr[b] << endl;
    }
    return;
}

int main() {
    zad12();
    system("PAUSE");
}
