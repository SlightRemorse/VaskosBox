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

void zad13() {
    xnt();
    int arr[10];
    int sum;
    for(int i=0; i<10; i++) {
        sum=0;
        for(int b=0; b<=1000; b++) if(b%(x*(i+1))==0) sum+=b;
        arr[i]=sum;
        cout << "Arr[" << i << "]= " << arr[i] << endl;
    }
    return;
}

int main() {
    zad13();
    system("PAUSE");
}
