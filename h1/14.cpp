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

void zad14() {
    xnt();
    int c=0;
    int arr[10];
    for(int i=0; c<10; i++) {
        bool prime=1;
        for(int b=2; b<i; b++) if(i%b==0) prime=0;
        if((prime==1) && (i%10==x)) {
            arr[c]=i;
            cout << "Arr[" << c << "]= " << arr[c] << endl;
            c++;
        }
    }
    return;
}

int main() {
    zad14();
    system("PAUSE");
}
