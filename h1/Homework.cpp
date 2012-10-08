//Vasil Bozhurski XIa


#include <iostream>
#include <time.h>
#include <math.h>
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

void xny() {
    cout << "Enter X: ";
    cin >> x;
    do {
        cout << "Enter Y [Y>X]: ";
        cin >> y;
    }while(y<x);
}

void xnt() {
    do {
        cout << "Enter X [0<X<10]: ";
        cin  >> x;
    }while((x<1) || (x>9));
}

void xno() {
    do {
        cout << "Enter X [0<X<1]: ";
        cin  >> xd;
    }while((xd<=0) || (xd>=1));
}

int zad1() {
    int res=0;
    xny();
    for(int i=x; i<=y; i++) if((i%2==1) || (i%2==-1)) res+=i;
    return res;
}

int zad2() {
    int res=0;
    xny();
    for(int i=x; i<=y; i++) if(i%17==0) res+=i;
    return res;
}

void zad3() {
    xny();
    cout << "Results are: ";
    for(int i=x; i<=y; i++) if(i%10==3) {
        bool prime=1;
        for(int a=2; a<i; a++) if(i%a==0) prime=0;
        if(prime==1) cout << i << ";";
    }
    cout << endl;
    return;
}

int fibonacci2(int a) {
    int res;
    if(a<=1) return a;
    else res=fibonacci2(a-1)+fibonacci2(a-2);
    return res;
}

int fibonacci(int a) {
    int x=0;
    int y=1;
    if(a<=1) return a;
    else for(int i=0; i<a; i++) {
        int sw=y;
        y=x+y;
        x=sw;
    }
    return y;
}
    

void zad4() {
    do {
        cout << "Enter X [X>=0]: ";
        cin >> x;
    }while(x<0);
    do {
        cout << "Enter Y [Y>X]: ";
        cin >> y;
    }while(y<x);
    cout << "Results are: ";
    for(int i=x; i<=y; i++) cout << fibonacci(i) << ";";
    cout << endl;
    return;
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

void zad8() {
    xnt();
    int arr[10];
    long int b=0;
    int i=0;
    while(i<10) {
        arr[i]=fibonacci(b);
        b++;
        if(arr[i]%x==0) {
            i++;
            cout << arr[i-1] << ";";
        }
    }
    cout << endl;
return;
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

void zad15() {
    xnt();
    int arr[10];
    int num, c;
    c=0;
    for(int i=0; c<10; i++) {
        num=fibonacci(i);
        if(num%10==x) {
            cout << endl << num;
            bool prime=1;
            for(int a=2; a<num; a++) if(num%a==0) prime=0;
            if(prime==1) {
                cout << " (prime)";
                arr[c]=num;
                c++;
            }
        }
    }
    return;
}

void zad16() {
    x=xnn();
    int arr[10];
    int counter=0;
    for(int i=1; i<x; i=i+2) 
    {
        if(x%i==0) {
        arr[counter]=i;
        cout << "Arr[" << counter << "]=" << arr[counter] << endl;
        counter++;
        }
    }
    cout << "Prime deviders:" << endl;
    for(int i=0; i<counter; i++) {
        bool prime=1;
        for(int a=2; a<arr[i]; a++) if(arr[i]%a==0) prime=0;
        if(prime==1) cout << "Arr[" << i << "]=" << arr[i] << endl;
    }
    return;
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
    srand(time(NULL));
    while(1) {
        short int select=1337;
        while((select>17) || (select<1)) {
            cout << "Enter problem number [1-17]: ";
            cin >> select;
            if((select>17) || (select<1)) cout << "Invalid number." << endl;
            if(select==0) return 0;
        }
        switch(select) {
            case 1:
                cout << "Result is: " << zad1() << endl;
                break;
            case 2:
                cout << "Result is: " << zad2() << endl;
                break;
            case 3:
                zad3();
                break;
            case 4:
                zad4();
                break;
            case 5:
                zad5();
                break;
            case 6:
                zad6();
                break; 
            case 7:
                zad7();
                break;
            case 8:
                zad8();
                break;               
            case 9:
                cout << "Result is: " << zad9() << endl;
                break;
            case 10:
                zad10();
                break;
            case 11:
                zad11();
                break;
            case 12:
                zad12();
                break;
            case 13:
                zad13();
                break;
            case 14:
                zad14();
                break;
            case 15:
                zad15();
                break;
            case 16:
                zad16();
                break;
            case 17:
                zad17();
                break;        
            }
        system("PAUSE");
    }
}
