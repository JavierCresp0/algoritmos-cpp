//Luis David Diaz Mesa, Javier

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void insercion(int* vDes, int n);
int main(){

    clock_t tinicio,tfin;
    double tiempo;

    srand(time(0));
    int n;
    cout << "Tamanyo del vector: ";
    cin >> n;
    cout << endl;

    int* vectorC = new int[n+1];
    int *vpeor=new int[n+1];
    int *vmejor=new int[n+1];

    //vpeor
    for(int i=1; i<=n;i++){
        vpeor[i] = n-i;
    }
    //vmejor
    for(int i=1;i<=n;i++){
        vmejor[i] = i;
    }

    //inicalizamos el vectorCualquiera con numeros aleatorios
    for(int i=1;i<=n;i++){
        vectorC[i] = rand()%101;//num aleatorio del 0 al 100
    }

    
    
    //mostramos el vector generado
    cout << "- Vector VCUALQUIERA a ordenar(muestra solo las 10 primeras posiciones):"<< endl;
    int i=1;
   
    while(i<=10){
        if(n>=10 || i<=n){
            cout << vectorC[i];
            if(i==10)
                cout << "..." << endl;
            else
                cout << " , ";
            i++;
        }else
            break;
    }

    //init timer vcualquira
    tinicio = (double)clock();
   
    //ordenamiento del vector
    insercion(vectorC,n);

    //finish timer ¿AQUI O AL IMPRIMIR EL VECTOR ORDENADO?
    tfin = clock();

    //mostrar tiempo de ejecucion de la funcion
    tiempo=(double) (tfin-tinicio)/CLOCKS_PER_SEC*1000;
    cout << endl << "El tiempo de ejecucion pera VCUALQUIERA en ms ha sido: " << tiempo << endl <<  endl;

    //mostrar posiciones 1:10 del vector ordenado
    cout << "- Vector VCUALQUIERA ordenado(muestra solo las 10 primeras posiciones):"<< endl;
    i=1;
    while(i<=10){
        if(n>=10 || i<=n){
            cout << vectorC[i];
            if(i==10)
                cout << "..." << endl;
            else
                cout << " , ";
            i++;
        }else
            break;
    }
   
   cout << "******************************************"<<endl;
   //VPEOR
   //mostramos el vector generado vpeor
    cout << endl << "- Vector VPEOR a ordenar(muestra solo las 10 primeras posiciones):"<< endl;
    i=1;
    while(i<=10){
        if(n>=10 || i<=n){
            cout << vpeor[i];
            if(i==10)
                cout << "..." << endl;
            else
                cout << " , ";
            i++;
        }else
            break;
    }
   //init timer peor
    tinicio = (double)clock();

    //ordenamiento del vector
    insercion(vpeor,n);

    //finish timer ¿AQUI O AL IMPRIMIR EL VECTOR ORDENADO?
    tfin = clock();

    //mostrar tiempo de ejecucion de la funcion
    tiempo=(double) (tfin-tinicio)/CLOCKS_PER_SEC*1000;
    cout << endl << "El tiempo de ejecucion pera VPEOR en ms ha sido: " << tiempo << endl <<  endl;

    //mostrar posiciones 1:10 del vector ordenado
    cout << "- Vector VPEOR ordenado(muestra solo las 10 primeras posiciones):"<< endl;
    i=1;
    while(i<=10){
        if(n>=10 || i<=n){
            cout << vpeor[i];
            if(i==10)
                cout << "..." << endl;
            else
                cout << " , ";
            i++;
        }else
            break;
    }

    cout << "******************************************"<<endl;
    //VMEJOR
    //mostramos el vector generado vmejor
    cout << endl << "- Vector VMEJOR a ordenar(muestra solo las 10 primeras posiciones):"<< endl;
    i=1;
    while(i<=10){
        if(n>=10 || i<=n){
            cout << vmejor[i];
            if(i==10)
                cout << "..." << endl;
            else
                cout << " , ";
            i++;
        }else
            break;
    }


   //init timer mejor
    tinicio = (double)clock();

    //ordenamiento del vector
    insercion(vmejor,n);

    //finish timer ¿AQUI O AL IMPRIMIR EL VECTOR ORDENADO?
    tfin = clock();

    //mostrar tiempo de ejecucion de la funcion
    tiempo=(double) (tfin-tinicio)/CLOCKS_PER_SEC*1000;
    cout << endl << "El tiempo de ejecucion pera VMEJOR en ms ha sido: " << tiempo << endl <<  endl;

    //mostrar posiciones 1:10 del vector ordenado
    cout << "- Vector VMEJOR ordenado(muestra solo las 10 primeras posiciones):"<< endl;
    i=1;
    while(i<=10){
        if(n>=10 || i<=n){
            cout << vmejor[i];
            if(i==10)
                cout << "..." << endl;
            else
                cout << " , ";
            i++;
        }else
            break;
    }   
    system("pause");

     return 0;
}

void insercion(int* vC,int n){
    int i=2;
    int j,x;

    for(i;i<=n;i++){
        x = vC[i];
        j = i-1;
        while(j>0 && vC[j]>x){
            vC[j+1] = vC[j];
            j = j-1;
        }
        vC[j+1] = x;
    }
}



    



