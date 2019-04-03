#include<iostream>
#include<cmath>

using namespace std;

// funzione per risolvere l'equazione di primo grado a*x + b = 0
// tipo void perché non deve restituire alcun risultato, ma solo stamparlo
void primo_grado(float a, float b) {
    if (a==0) {
        if (b==0)
            cout<<"Sempre vera"<<endl;
        else
            cout<<"Impossibile"<<endl;
    }
    else {
        float x=-b/a;
        cout<<"La soluzione vale: "<<x<<endl;
    }
}

// funzione per risolvere l'equazione di secondo grado a*x^2 + b*x + c = 0
// tipo void perché non deve restituire alcun risultato, ma solo stamparlo
void secondo_grado(float a, float b, float c) {

    if (a==0)
        primo_grado(b,c); // se a è zero, l'equazione è b*x + c = 0, quindi di primo grado
    else {
        float delta = pow(b,2)-4*a*c;
        
        if (delta > pow(10,-8)) {
            float x1=(-b+sqrt(delta))/(2*a);
            float x2=(-b-sqrt(delta))/(2*a);
            cout<<"Le soluzioni sono: "<<x1<<", "<<x2<<endl;
        }
        else if (fabs(delta) < pow(10,-8)) {
            float x1=-b/(2*a);
            cout<<"La soluzione vale: "<<x1<<endl;
        }
        else {
            float x=-b/(2*a); // parte reale
            float y=sqrt(-delta)/(2*a); // parte immaginaria
            cout<<"Le soluzioni sono: "<<x<<"+i"<<y;
            cout<<", "<<x<<"-i"<<y<<endl;
        }
    }
}

int main(){
    float a, b, c;

    // esempio due soluzioni reali distinte
    a=1;
    b=-5;
    c=6;
    secondo_grado(a,b,c);
    
    // esempio una soluzione reale doppia
    a=1;
    b=2;
    c=1;
    secondo_grado(a,b,c);
    
    // esempio soluzioni complesse coniugate
    a=0.1;
    b=0.1;
    c=0.1;
    secondo_grado(a,b,c);
    
    // esempio una soluzione reale doppia 
    a=0.1;
    b=0.2;
    c=0.1;
    secondo_grado(a,b,c);
    
}
