//Vasil Bozhurski XIa


#include <iostream>
using namespace std;

double xd;

void xno() {
    do {
        cout << "Enter X [0<X<1]: ";
        cin  >> xd;
    }while((xd<=0) || (xd>=1));
}

void zad17() {
    xno();
    float sum=5.0;
    int a;
    bool prime;
    for(int i=1; sum>xd; i++) {
        prime=1;
        for(int a=2; a<i; a++) if(i%a==0) prime=0;
        if(prime==1) {
            for(int a=2; a<i+2; a++) if((i+2)%a==0) prime=0;
            if(prime==1) {
                sum=1.0/i+1.0/(i+2);
                cout << "Sum for [" << i << ";" << i+2 << "]=" << sum << endl;
            }
        }
    } 
    return;
}            

int main() {
    zad17();
    system("PAUSE");
}
