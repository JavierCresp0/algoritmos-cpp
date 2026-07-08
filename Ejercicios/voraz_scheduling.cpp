// Luis David Mesa, Javier Crespo

#include <iostream>
#include <fstream>
using namespace std;


void ordenarCreciente(int *tiempos,int *procesos,int n);
int* leerFichero(int &n);
int main() {
    int j,resultado;
    int n;
    int *solucion,*procesos;
    int *tiempos;

    cout<<"Introduce el numero de procesos:";
    cin>> n;
    tiempos = new int [n+1];
    procesos = new int [n+1];
    for(int i=1;i<=n;i++){
        procesos[i]=i;
        cout<< "Introduce el tiempo de proceso ["<<i<<"]:";
        cin>>tiempos[i];
    }

    solucion = new int[n+1];

    ordenarCreciente(tiempos,procesos,n);
    j=1;
    int i=1;
    resultado=0;
    int x;
    while(i<=n){
        if(i==1)
            solucion[i]= tiempos[i];
        else
            solucion[i]= tiempos[i]+solucion[i-1];

        x = tiempos[i];
        while(j<=i){
            resultado = resultado+solucion[j];
            j++; 
        }
           
        i++;
    }

    cout<<"ORDEN EN QUE DEBEN EJECUTARSE LOS PROCESOS: "<<endl;
    for(int i=1;i<=n;i++){    
        cout<<"["<<i<<"] PROCESO "<<procesos[i]<<endl;
    }
    cout<<"TIEMPO MINIMO TOTAL DE EJECUCION: "<<resultado<<endl;

    system("pause");
    return 0;
}


int* leerFichero(int &n){
    // Abrir el archivo en modo lectura
    ifstream archivo("entrada.txt");
    // Verificar si se pudo abrir correctamente
    if (!archivo) {
    cerr << "No se pudo abrir el archivo." << endl;
    exit(1);
    }
    // Leer el tamaño del vector desde la primera línea
    archivo >> n;
    // Crear un vector para almacenar los números enteros
    int* numeros = new int[n+1];
    // Leer los números enteros desde el archivo y almacenarlos en el vector
    for (int i = 1; i <= n; i++) {
    archivo >> numeros[i];
    }
    // Cerrar el archivo
    archivo.close();
    // Mostrar los números enteros almacenados en el vector
    /*
    cout << "Vector leido desde el archivo:" << endl;
    for (int i = 1; i <= n; i++) {
    cout << numeros[i] << " ";
    }
    */
    return numeros;
}

void ordenarCreciente(int *tiempos,int *procesos,int n){
    int i=2;
    int j,x,z;

    for(i;i<=n;i++){
        x = tiempos[i];
        z = procesos[i];
        j = i-1;
        while(j>0 && tiempos[j]>x){
            tiempos[j+1] = tiempos[j];
            procesos[j+1] = procesos[j];
            j = j-1;
        }

        tiempos[j+1] = x;
        procesos[j+1] = z;
    }
}