//Luis David Diaz Mesa, Javier 

#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
double funcionRecursiva(double x, int n);
double funcionIterativa(double x, int n);
double potencia2(double a, int b);
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
    cout << funcionIterativa(x,n) << endl;
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

double funcionIterativa(double x, int n){

    stack <int> pilaN; 
    double r;
    int n1=n;
    while (n1!=0)
    {
        pilaN.push(n1);
        if(n1%2==0){
            n1=n1/2;  
        }else {   
            n1=n1-1;       
        }
    }    
    r=1;
    while (!pilaN.empty() && n1!=n)
    {

        n1=pilaN.top();
        pilaN.pop();
        cout<< prompt2 <<".- potencia(" << x << "," << n1 << ")"<<endl;
        prompt2++;
        if(n1%2==0){    
            r= r*r;
        }else{
           r=x*r;
        }
    }  
    
    return r;
}


////////////////////////////////

/*int traza1;

int main2(){
  

  double a;
  int b;
  traza1=1;

  cout<< "introduce es valor de la a"<< endl;
  cin >> a;

  cout<< "introduce es valor de la b"<< endl;
  cin >> b;
  
  cout << potencia2(a,b);

    system("pause");
    return 0;
}

double potencia2(double a, int b){
    cout<< traza1 << ".- potencia("<<a<<","<<b<<") " << endl;
    traza1++;
    double s;
    if (b==0)
    {
        return 1;
    }else{
        s = potencia2(a,b/2);

        if ( b%2==0)
        {
            return s = s * s;        
        }else{
            return s = a * s *s;
        }
        //return s;
    }

}*/

