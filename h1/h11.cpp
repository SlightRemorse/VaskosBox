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

void zad11() {
    xnt();
    float arr[10];
    float sum;
    for(int i=0; i<10; i++) {
        sum=0;
        for(int z=i*x; z<=(i+1)*x; z++) {
            sum+=cos(z);
        }
        arr[i]=sum;
        cout << "Arr[" << i << "]= " << arr[i] << endl;
    }
    return;
}

int main() {
    zad11();
    system("PAUSE");
}
