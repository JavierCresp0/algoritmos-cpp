//Luis David Diaz Mesa, Javier

#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
double funcionRecursiva(double x, int n);
double funcionIterativa(double x, int n);
double funcionIter2(double x, int n);
int prompt1,prompt2;
int main(){
    prompt1=prompt2=1;
    double x;int n;
    cout<<"Introduce la base de la potencia: ";
    cin>>x;
    cout<<endl;
    cout<<"Introduce el exponente: ";
    cin>>n;
    cout<<endl;
    cout<<"Traza recursiva:"<<endl;
    cout << funcionRecursiva(x,n) << endl;
    cout<<"Traza iterativa"<<endl;
    cout << funcionIter2(x,n) << endl;
    system("pause");
    return 0;
}

double funcionRecursiva(double x, int n){
    double r;
    cout<< prompt1 <<".- potencia(" << x << "," << n << ")"<<endl;
    prompt1++;
    if(n==0){
        r=1;
    }else {
        if (n%2==1){
            r= x*funcionRecursiva(x,n-1);
        }else
        {
            r = funcionRecursiva(x,n/2);
            r=r*r;
        }
        
    }
    return r;
}

double funcionIter2(double x, int n){
    stack <int> pila;
    int n1;
    n1 = n;
    double r;
    while (!(n1==0))
    {
        pila.push(n1);
        if (n%2==1){
            n1=n1-1;
        
        }else
        {
            n1=n1/2;                        
        }
    }
    r=1;
    while (!(n1==n) && !pila.empty())
    {
        n1 = pila.top();
        pila.pop();
        cout<< prompt2 <<".- potencia(" << x << "," << n1 << ")"<<endl;
        prompt2++;
        if (n%2==1){
            r=x*r;
        }else
        {
            r=r*r;            
        }
    }
    return r;
    
}

double funcionIterativa(double x, int n){

    stack <int> pilaN; 
    double r;
    int n1=n;
    while (n1!=0)
    {
        pilaN.push(n1);
        if(n1%2==1){
            n1=n1-1;  
        }else {   
            n1=n1/2;       
        }
    }    
    r=1;
    while (!pilaN.empty() && n1!=n)
    {

        n1=pilaN.top();
        pilaN.pop();
        cout<< prompt2 <<".- potencia(" << x << "," << n1 << ")"<<endl;
        prompt2++;
        if(n1%2==1){    
            r= x*r;
        }else{
           r=r*r;
        }
    }  
    
    return r;
}