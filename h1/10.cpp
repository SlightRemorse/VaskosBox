//Vasil Bozhurski XIa


#include <iostream>
using namespace std;

int x,y;
double xd;

int xnn() {
    int p;
    do {
        cout << "Enter a positive int: ";
        cin >> p;
    }while(p<=0);
    return p;
}

void cut(int a, int b, int c, int d) {
    int cuts, cutx, cuty;
    int spotx[10],spoty[10];
    cuts=0;
    cutx=0;
    cuty=0;
    for(int i=0; i<=a; i+=c) {
        if(i==0) continue;
        if((cutx<10) && (i<a)) {
            cout << "X=" << i << endl;
            spotx[cutx]=i;
        }
        cutx++;
    }
    for(int i=0; i<=b; i+=d) {
        if(i==0) continue;
        if((cuty<10) && (i<b)) {
            cout << "Y=" << i << endl;
            spoty[cuty]=i;
        }
        cuty++;
    }
    cuts=cuty*cutx;
    cout << "Number of smaller boards: " << cuts << endl;
    return;
}

void zad10() {
    int w,h;
    cout << "Defining x. ";
    x=xnn();
    cout << "Defining y. ";
    y=xnn();
    cout << "Defining w. ";
    w=xnn();
    cout << "Defining h. ";
    h=xnn();
    cut(x,y,w,h);
    cout <<"If the board is flipped:" << endl;
    cut(y,x,w,h);
    return;
}   

int main() {
    zad10();
    system("PAUSE");
}
