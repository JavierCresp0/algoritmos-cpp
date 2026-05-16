/**
 * Mochila 0/1 — Resolución por backtracking
 *
 * Dado un conjunto de N objetos con peso (P) y valor (V), y una mochila de
 * capacidad M, encuentra la combinación que maximiza el valor sin exceder
 * la capacidad. Explora el árbol de soluciones con poda (variable global
 * 'traza' para imprimir el recorrido si se activa).
 *
 * Técnica:    Backtracking con poda
 * Entrada:    parámetros por consola (N, M, P[], V[])
 * Salida:     vector óptimo X[] y valor máximo Voptimo
 *
 * Autores:    Luis David Díaz Mesa & Javier Crespo Berland
 * Asignatura: Metodología y Programación Avanzada (MPA) — 1º curso
 */
#include <iostream>

using namespace std;

void Mochila (float* P, float* V, int* &X, int k, int* &Xoptimo, float &Voptimo, int n,int m);
float CalcularSuma (int* &X, float* V, int k);
bool traza;
int main ()
{
    int n=0,m=0, i=0, k=1, *X, *Xoptimo;
	int traza_aux=0;
	traza=false;
    float Voptimo=-99999, *P, *V, j=0;
	cout <<"Introduce peso maximo de la mochila (m): ";
	cin >> m;
    cout << "Introduce el total de objetos (n): ";
    cin >> n;
    cout << endl;
    cout << "PESOS: " << endl;

    //Inicializar vectores
{

    P=new float [n+1];
    if (P == NULL)
    {
        cout << "Error al reservar memoria" << endl;
        return -1;
    }
    V=new float [n+1];
    if (V == NULL)
    {
        cout << "Error al reservar memoria" << endl;
        return -1;
    }
    X=new int [n+1];
    if (X == NULL)
    {
        cout << "Error al reservar memoria" << endl;
        return -1;
    }
    Xoptimo=new int [n+1];
    if (Xoptimo == NULL)
    {
        cout << "Error al reservar memoria" << endl;
        return -1;
    }

    for (i=1;i<=n;i++){
        X[i]=0;
        Xoptimo[i]=0;
        V[i]=0;
        P[i]=0;
    }        

        
}
    for (i=1; i<=n; i++)
    {
        cout << "Objeto "<< i << ": ";
        cin >> P[i];
        cout << endl;
    }
    cout << "VALORES:" << endl;

    for (i=1; i<=n; i++)
    {
        cout << "Objeto "<< i << ": ";
        cin >> V[i];
        cout << endl;
    }

	//Solicitamos traza T/F
	cout<<"Permitir ver Traza [1] Si. [0] No : ";
	cin >> traza_aux;
	
	if(traza_aux !=0 && traza_aux!=1){
		cout<<"ERROR. PARAMETRO INCORRECTO"<<endl;
		return -1;
	}
	if(traza_aux==1)
		traza=true;
	
    Mochila(P,V,X,k,Xoptimo,Voptimo,n,m);

    cout << "OBJETOS SE LLEVAN EN LA MOCHILA." << endl;
    //recorremos el array de objetos y comprobamos que su valor sea 1 para saber los Objetos que nos llevamos,su peso y su valor
    for (i=1;i<=n;i++)
    {
        if (Xoptimo[i]==1)
        {
            cout <<"O."<< i <<": " << P[i] << "kg - Valor: " << V[i] << endl;
        }
    }

    //Calcumos el peso total de la mochila a partir de los Objetos que se llevan
    for (i=1;i<=n;i++)
    {
        if (Xoptimo[i]==1)
        {
            j=j+P[i];
        }
    }

	cout <<"VALORES DE LA MOCHILA"<<endl;
    cout << "Peso Total: " << j << endl;
    cout << "Valor Total: " << Voptimo << endl;
    /*
    cout << "OBJETOS QUE SE LLEVAN:";
    for (i=1;i<=n;i++)
    {
        if (Xoptimo[i]==1)
            cout << " O." << i;
    }
    */
    cout << endl;
    system("pause");
    return 0;
}

//              Peso     Valor      ?      Nivel   Arr de objetos Arr  de valor  num obj  tam mochila
void Mochila (float* P, float* V, int* &X, int k, int* &Xoptimo, float &Voptimo, int n,int m)
{
    int i, f;
    float peso, valor;

    if (k<=n)
    {
        for(i=0; i<=1; i++)
        {
            X[k]=i;
            //Peso del objeto
            peso=CalcularSuma(X,P,k);
			
			
			if(traza){
				cout<<"Mochila(k="<<k<<")"<<endl;;
				cout<<"(";
					for(int j=1;j<=k;j++){
						
						cout<<X[j];
						if(j<k)
						cout<<",";
					}
					
						
				cout<<")"<<endl;
			}
			if(peso>m){
				cout<<"Peso= "<<peso<<" > "<<"M"<<endl;
				cout<<"No es factible"<<endl<<endl;;		
			}
			
		
            if (peso<=m)//m=peso maximo
            {
				
			/*	if(traza){
				cout<<"Mochila(k="<<k<<")"<<endl;;
				cout<<"(";
					for(int j=1;j<=k;j++){
						
						cout<<X[j];
						if(j<k)
						cout<<",";
					}
					
						
				cout<<")"<<endl;
				}*/
				
                if (k==n)//k=nivel n=nº objetos
                {
                    //valor del objeto
                    valor=CalcularSuma(X,V,k);

                    if (valor>Voptimo)
                    {
                        //actualizamos arrays
                        Voptimo=valor;
                        for (f=1; f<=n;f++)
                             Xoptimo[f]=X[f];
                            //1er iter: Xoptimo= [0,0,1] - X=[0,0,1]



                    }

                    //se imprime traza
					if(traza){
					cout <<"-Valor= " <<valor<<" -Xoptimo= ";
						for(int j=1;j<=n;j++){
							cout<<Xoptimo[j];
							if(j<n)
							cout<<",";
						}
					cout<<" -Voptimo= "<<Voptimo<< endl;
					cout<<endl;
					}
                }
                else						
                    Mochila(P,V,X,k+1,Xoptimo,Voptimo,n,m);
				
            }
        }
    }
    
}
                    //        pesos     nivel-> inic:1
float CalcularSuma (int* &X, float* V, int k)
{
    int i;
    float suma=0;

    for (i=1; i<=k; i++)
    {
        if (X[i]==1)
            suma=suma+V[i];
    }
    return suma;
}
