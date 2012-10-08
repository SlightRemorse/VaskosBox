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

double zad9() {
    xno();
    double res=0;
    bool minus=0;
    float i;
    for(i=1.0; 4.0/i>=xd; i=i+2.0) {
         if(minus==0) {
                res+=4.0/i;
                minus=1;
            }
         else {
                res+=-4.0/i;
                minus=0;
            }
        }
        if(minus==0) res+=4.0/i;
        else res+=-4.0/i;
    return res;
} 

int main() {
    cout << zad9() << endl;
    system("PAUSE");
}
