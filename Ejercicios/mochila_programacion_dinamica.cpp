/*
Luis David Diaz Mesa
Javier Leandro
*/
#include <iostream>
#include <fstream>
using namespace std;
float mochila(int M, int tot, int* peso, float* valor);
float maximo(float a,float b);

int main ()
{
    int m=0,n=0, i;
    float  resultado;
    int* pesos;
    float* valor;
/*	
    cout << "Peso maximo de la mochila: ";
    cin >> M;
    cout << "Total de objetos: ";
    cin >> n;
    peso=new int [n+1];
    if (peso == NULL)
    {
        cout << "Error al reservar memoria" << endl;
        return -1;
    }
    valor=new float [n+1];
    if (valor == NULL)
    {
        cout << "Error al reservar memoria" << endl;
        return -1;
    }

    for (i=1; i<=n; i++)
    {
        cout << "Peso del objeto "<< i << ": ";
        cin >> peso[i];
    }

    for (i=1; i<=n; i++)
    {
        cout << "Valor del objeto "<< i << ": ";
        cin >> valor[i];
    }
*/
	ifstream archivo("md.txt");
	if(!archivo){
	cerr << "No se pudo abrir el archivo." << endl;
	exit(1);
	}
    	
	archivo>>m;
	archivo>>n;
    pesos = new int[n+1];
	valor = new float[n+1];
	for(int i=1;i<=n;i++){
		archivo >> pesos[i];
	}
	for(int i=1;i<=n;i++){
		archivo >> valor[i];
	}

    
	
	archivo.close();

    resultado=mochila(m, n, pesos, valor);
    cout << "Valor maximo que puede llevar: " << resultado;
	
	cout<<"\n\nFin.."<<endl;
    system("pause");
    return 0;
}

float mochila(int M, int n, int* peso, float* valor)
{
    int i, j;
    float **T;

    T=new float* [n+1];

    for(int i=0; i<=n; i++)
        T[i]=new float[M+1];

    for (i = 0; i <= M; i++)
    {
        T[0][i]=0;
    }
    for (i = 0; i <= n; i++)
    {
        T[i][0]=0;
    }
    /*
    for(int i=0; i<=n; i++){
        for(int j=0; j<=M; j++){
            T[i][j]=0;
        }    
    }*/

    for (i=1; i<=n; i++)
    {
        for (j=1; j<=M; j++)
        {
            if (peso[i]>j)
                T[i][j]=T[i-1][j];
            else
                T[i][j]=maximo(T[i-1][j],valor[i]+T[i-1][j-peso[i]]);	
        }
    }
//	TRAZA MATRIZ

    cout << endl;
    for(int k = 0; k < n+1;k++)
    {
        for(int z = 0; z < M+1; z++)
            cout << T[k][z] <<" ";

    cout << endl;
    }	
    int k=M;
    int* objetos = new int[n+1];
    for(i=n;i>0;i--){

        if(T[i][k]!=T[i-1][k] ){
            objetos[i] = 1;
            k = k - peso[i];
        }else
            objetos[i]=0; 
    }
    cout<< "Se cogen los objetos: ";
    for(int i=1;i<=n;i++){
        if(objetos[i]==1)
            cout<< i << " ";
    }
    cout << endl;
    return T[n][M];//devolvemos el valor de la matriz en la posicion n m
}

float maximo(float a, float b)
{
    if (a>=b)
        return a;
    else
        return b;
}
