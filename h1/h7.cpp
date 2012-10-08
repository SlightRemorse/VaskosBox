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

void zad7() {
    xnt();
    double arr[10];
    double temp;
    int i=0;
    int a=0;
    int b;
    while(i<10) {
        arr[i]=cos(a);
        if(arr[i]<0) temp=arr[i]*(-1);
        else temp=arr[i];
        for(b=0; b<temp*1000-1; b++);
        if(b%10==x) {
            cout <<"arr[" << i << "]: ";
            if(arr[i]>0) cout << " ";
            cout << arr[i] << endl;
            i++;
        }
        a++;
    }
    return;
}

int main() {
   zad7();
    system("PAUSE");
}
