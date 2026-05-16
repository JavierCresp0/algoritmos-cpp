/*
Javier Leandro
Luis David Diaz Mesa
*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int INF = 99999;
using namespace std;
void ordenarDirectamente(int *V,int n);
void combinar(int *V, int *V2, int *V3,int nInf,int nSup);
void mergesort (int *V,int n);
int inf(double n);
int sup(double n);
int main(){

	//srand(time(0));
    int i=1, izq, der;
	int n;
    cout << "Introduce num.total elementos del vector:" << endl;
    cin >> n;
    int *V;
    V=new int [n+1];
	if (V == NULL)
	{
		cout << "Error al reservar memoria" << endl;
		return -1;
	}

	
	while (i<=n)
	{
		cout << "Introduce elemento " << i << ":" << endl;
		cin >> V[i];
		i++;
	}
	
/*
	for(i=1;i<=n;i++){
		V[i] = rand() % 100;
	}
*/
    cout << "\nVector original:";
	for (i=1; i<=n; i++)
	{
		cout  << " " << V[i];
	}
    cout << endl << endl;
   

    mergesort(V,n);
	
	cout << "\nVector ordenado:";
	for (i=1; i<=n; i++)
	{
		cout  << " " << V[i];
	}
    cout << endl;
	system("pause");
    return 0;
}



void mergesort(int *V,int n){
	//Primer fallo, no separabamos el caso base del general	
	if (n<3 ){
		ordenarDirectamente(V,n);
	}else{
		int nInf,nSup;
		double n2 = (double) n /2;//2
		//comprobar n2
		nInf= inf(n2);//2
		nSup = sup(n2);//2
		//RESERVAMOS MEMORIA
		int* V1 = new int[nInf+2];	
	    if (V1 == nullptr)
		{
			cout << "Error al reservar memoria" << endl;
			return;
		}
		int* V2=new int[nSup+2];
		if (V2 == nullptr)
		{
			cout << "Error al reservar memoria" << endl;
			return;
		}

		//Rellenamos subvector elemento a elemento
		for(int i=1;i<=nInf;i++){
			V1[i] = V[i];

		}
		for(int i=1;i<=nSup;i++){
			V2[i] = V[nInf+i];
		}
		//segundo fallo, pasabamos el tamaño del vector original en vez el tamaño del subvector
		mergesort(V1,nInf);
		mergesort(V2,nSup);	
		combinar(V,V1,V2,nInf,nSup);
	}
	
}

void combinar(int *V,int *V1, int *V2,int nInf,int nSup)
{
	int i,i1,i2,n=nInf+nSup;
	i1=1;
	i2=1;
	V1[nInf+1] = INF;
	V2[nSup+1] = INF;
/* 	cout << endl <<"Traza subvectores:"<<endl<<"V1:"<<endl;
	
	for (i=1; i<=nInf; i++)
	{
		cout  << " " << V1[i];
	}
	cout << endl <<"Traza subvectores:"<<endl<<"V2:"<<endl;
	for (i=1; i<=nSup; i++)
	{
		cout  << " " << V2[i];
	}
	cout<<endl; */
	for(i=1;i<=n;i++){
		if(V1[i1]<V2[i2]){
			V[i] = V1[i1];
			i1++;
		}
		else{
			V[i]=V2[i2];
			i2++;	
		}
	}
}
void ordenarDirectamente(int *V,int n){
	int aux;
	
	//Ultimo fallo, no teniamos en cuenta cuando habia un solo elemento, ya que al llegar aqui aun no le hemos dado valor al tamaño del vector+1 para INF
	if(n>1 && V[1]>V[2]){
		aux=V[1];
		V[1]=V[2];
		V[2]=aux;
	}
}

int inf(double n){
	
	if(n==1)
		return n;	
	else
		return floor(n);
}

int sup(double n){
	if(n==1)
		return n;
	else
		return ceil(n);
}
