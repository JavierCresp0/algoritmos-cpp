/**
 * MPAirlines — Cálculo de rutas mínimas entre ciudades
 *
 * Algoritmo:   Dijkstra sobre grafo dirigido ponderado
 * Entrada:     vuelos.txt — matriz de adyacencia N×N con precios (0 = sin vuelo directo)
 * Salida:      ruta más barata entre dos ciudades + coste total
 *
 * Aplica gestión dinámica de memoria con matrices float** y arrays auxiliares
 * para distancias (C), predecesores (P) y conjunto de visitados (S).
 *
 * Autores:     Luis David Díaz Mesa & Javier Crespo Berland
 * Asignatura:  Metodología y Programación Avanzada (MPA) — 1º curso
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <stdexcept>
#include <limits>

using namespace std;
//Se podrian implementar en un fichero const.h
//Constantes
const float INF = 9999;
const string INTRODUCE_FICHERO = "Introduce el nombre del fichero de vuelos: ";
const string FICHERO_CARGADO = " - Fichero cargado correctamente";
const string NO_EXISTE_FICHERO = " No existe el fichero: ";
const string NO_FICHERO_CARGADO = "# No se ha cargado ningun fichero";
const string LECTURA_N_INCORRECTA = "# Error al leer el valor de n";
const string LECTURA_MATRIZ_INCORRECTA = "# Error al leer los valores de la matriz";
const string MENU1_OPC1 = "1. Introducir fichero de vuelos";
const string MENU1_OPC2 = "2. Ver precios";
const string MENU1_OPC3 = "3. Ver precios y rutas";
const string MENU1_OPC4 = "4. Salir";
const string INTRODUCE_OPCION = "Introduce una opcion: ";
const string CIUDADES_DISPONIBLES = "Ciudades disponibles: ";
const string INTRODUCE_CIUDAD_ORIGEN = "Introduce la ciudad de origen: ";
const string CAMPO_DESTINO = "Destino";
const string CAMPO_PRECIO = "Precio";
const string CAMPO_RUTA = "Ruta";
const string LINEA = "-------";
const string ORIGEN = "Origen";

//Funciones
void leerFichero(string nombreFichero, int &n, float** &A, string* &ciudades,bool &ficheroCargado);
void initCyP(int* &C,int* &P,int nciudades);
int elegirvertice_costemin(int* C,float* S,int n);
void Dijkstra(int* &C,int* &P, float** A, float* &S,int n,int origen);
void printMatrix(float** matrix, int rows, int cols);
int menu();
int menuOpc2y3(string* ciudades,int n,bool &nuevoOrigen,int &origenAux,int origen);
void verPrecios(int origen,string* ciudades,float *S,int n);
void verPreciosyRuta(int origen,string* ciudades,float *S,int n,int* P);
void deleteAll( float** &A, string* &ciudades, float* &S, int* &C, int* &P);


int main(){

    int nciudades,origen=0;
    int origenAux;
    string* ciudades = nullptr;
    string nombreFichero;
    bool ficheroCargado = false;
    bool dijkstraHecho = false;
    bool nuevoOrigen = false;
    float** A = nullptr;
    float* S = nullptr;
    int* C = nullptr;
    int* P = nullptr;
    int opcion = 0;

    while(opcion != 4){
        opcion = menu();//manejar entrada de datos del menu
        switch(opcion){
            case 1://Introducir fichero de vuelos        
                cout << INTRODUCE_FICHERO;
                cin >> nombreFichero;
                cout << endl;
                leerFichero(nombreFichero, nciudades, A, ciudades,ficheroCargado);
                //printMatrix(A, nciudades, nciudades);
                cout << endl;
                //initCyP(C,P,nciudades);
                if(ficheroCargado)
                    S = new float[nciudades+1];           
                //ficheroCargado = true;
                break;
            case 2://Ver precios 
                if(ficheroCargado){
                    origen = menuOpc2y3(ciudades,nciudades,nuevoOrigen,origenAux,origen);
                    if(dijkstraHecho==false || nuevoOrigen==true)
                    {
                        initCyP(C,P,nciudades);
                        Dijkstra(C,P,A,S,nciudades,origen);
                    } 
                    dijkstraHecho=true;
                    verPrecios(origen,ciudades,S,nciudades);
                    break;
                }else{
                    cout << endl << NO_FICHERO_CARGADO << endl << endl; 
                }
                break;
            case 3://Ver precios y rutas
                if(ficheroCargado){
                    origen = menuOpc2y3(ciudades,nciudades,nuevoOrigen,origenAux,origen);
                    if(dijkstraHecho==false || nuevoOrigen==true)
                    {
                        initCyP(C,P,nciudades);
                        Dijkstra(C,P,A,S,nciudades,origen);
                    } 
                    dijkstraHecho=true;
                    verPreciosyRuta(origen,ciudades,S,nciudades,P);
                    break;
                }else{
                    cout << endl << NO_FICHERO_CARGADO << endl << endl;
                }
                break;
            case 4://LIMPIAR MEMORIA Y SALIR
                deleteAll(A,ciudades,S,C,P);
                break;
                
        }  
    }

    system("pause");
    return 0;
}

int menu(){
    int opcion;
    bool opc=false;
    while(!opc){
        cout << MENU1_OPC1<< endl;
        cout << MENU1_OPC2 << endl;
        cout << MENU1_OPC3 << endl;
        cout << MENU1_OPC4<< endl;
        cout << INTRODUCE_OPCION;
        cin >> opcion;
        if(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4){
            cout << endl << "#ERROR. Por favor elige una opcion valida [1...4]"<< endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Descarta la entrada inválida
       
        }else{
            opc=true;
        }
        cout << endl;
    }
    return opcion;
}

int menuOpc2y3(string* ciudades,int n,bool &nuevoOrigen, int &origenAux,int origen){
    //int opcion;
    string ciudad;
    bool opc=false;
    while(!opc){
        cout << CIUDADES_DISPONIBLES<< endl;
        for(int i=1;i<=n;i++){
            if(i != n){
                cout << ciudades[i] << " - ";
            }else{  
                cout << ciudades[i] << endl;
            }
        }
        cout << endl << INTRODUCE_CIUDAD_ORIGEN;        
        cin>>ciudad;
        for(int i=1;i<=n;i++){
            if (strcmp(ciudad.c_str(),ciudades[i].c_str())==0)
            {
                opc=true;
            }
        }
        if(opc==false)
            cout << "#ERROR. Por favor elige una opcion valida" << endl;
    }


    for (int i=1; i <= n; i++)
    {
        if(strcmp(ciudades[i].c_str(),ciudad.c_str())==0){
            origenAux = i;
            if(origen != 0){
                if(origenAux != origen){
                    nuevoOrigen = true;
                }
            }
            return i;
        }
    }
    
}

//inicializa los vectores C y P, cada vez que se llama para hacer Dijkstra
void initCyP(int* &C,int* &P,int nciudades){
    C = new int[nciudades+1];
    P = new int[nciudades+1];

    for(int i=1;i<=nciudades;i++){
        C[i] = i;
        P[i] = 0;
    }
}

void verPrecios(int origen,string* ciudades,float *S,int n){

    cout << left << setw(15) << CAMPO_DESTINO;
    cout << left << setw(15) << CAMPO_PRECIO<<endl;
    for(int i=1;i<=n;i++){
        if(i != origen){
            cout << left << setw(15) << ciudades[i];
            cout << left << setw(15) << S[i] << endl;
        }
    }
    cout<<endl;
}

void verPreciosyRuta(int origen,string* ciudades,float *S,int n,int* P){
    int tamCampoDestino,tamCampoOrigen =ciudades[origen].length()+1;
    cout << left << setw(15) << CAMPO_DESTINO;
    cout << left << setw(15) << CAMPO_PRECIO;
    cout << left << setw(15) << CAMPO_RUTA<< endl;
    cout << setw(15) << LINEA;
    cout << setw(15) << LINEA;
    cout << setw(15) << LINEA<< endl;

    for (int i = 1; i <= n; i++)
    {
        if ( i != origen){
            tamCampoDestino = ciudades[i].length()+1;
            cout << left << setw(15) << ciudades[i];
            cout << left << setw(15) << S[i];
            cout << left << setw(tamCampoOrigen) << ciudades[origen];
            int j = i;
            if(P[j] == origen){
                cout << " -> ";
                cout << left << setw(tamCampoDestino) << ciudades[i] << endl;
            }else{
                while(P[j] != origen)
                {   
                    int tamCampoAux = ciudades[P[j]].length()+1;
                    cout << " -> ";
                    cout << left << setw(tamCampoAux) << ciudades[P[j]];
                    j = P[j];
                }
                    cout << " -> ";
                    cout << left << setw(tamCampoDestino) << ciudades[i] << endl;
            }
            
        }
    }
    cout << endl;
}

int elegirvertice_costemin(int* C,float* S,int n){
    int costemin = INF;
    int vertice_costemin = 0;
    for(int i=1;i<=n;i++){
        if(C[i] != 0 && S[i] < costemin){
            costemin = S[i];
            vertice_costemin = i;
        }

    }
    return vertice_costemin;
}
// Dijkstra//vertices predecesores  matriz    costes  
void Dijkstra(int* &C,int* &P, float** A, float* &S,int n,int origen){
    int i,j,x;
    i=j=x=0;
    int costeMinimo = INF;
    // origen
    for (i = 1; i <= n; i++) {
        if (i == origen)
        {
            S[i] = 0;
        }else{  

            S[i] = A[origen][i]; // Copia los valores de la fila del origen en S
        }
    }
    for(i=1;i<=n-1;i++){
        x = elegirvertice_costemin(C,S,n);
        C[x] = 0; //Visitado = 0
        for(j=1;j<=n;j++)
        {
            if(C[j] != 0){
                //float temp = S[j];
                if (S[x] + A[x][j] < S[j]) {
                    S[j] = S[x] + A[x][j];
                    P[j] = x;
                }
            }
        }    
   }   
   //Cambiamos los valores de P[i] = 0 por P[i] = origen
    for (int i = 1; i <= n; i++)
    {
         if(P[i] == 0){
              P[i] = origen;
         }
    }
}

void deleteAll( float** &A, string* &ciudades, float* &S, int* &C, int* &P){
    if(A != nullptr){
        for (int i = 0; i <= sizeof(A); i++) {
            delete[] A[i];
        }
        delete[] A;
    }
    if(ciudades != nullptr){
        delete[] ciudades;
    }
    if(S != nullptr){
        delete[] S;
    }
    if(C != nullptr){
        delete[] C;
    }
    if(P != nullptr){
        delete[] P;
    }

}

void leerFichero(string nombreFichero, int &n, float** &A, string* &ciudades,bool &ficheroCargado) {
    ifstream fichero;

    try {
        fichero.open(nombreFichero);
        if (!fichero.is_open()) {
            throw runtime_error(NO_EXISTE_FICHERO+ nombreFichero);
        }

        fichero >> n;
        if (n <= 0) {
            throw runtime_error(LECTURA_N_INCORRECTA);
        }

        A = new float*[n + 1];
        ciudades = new string[n + 1];

        for (int i = 0; i <= n; i++) {
            A[i] = new float[n + 1];
        }

        // Inicializar las posiciones [0][j] y [i][0] a 0
        for (int j = 0; j <= n; j++) {
            A[0][j] = 0;
        }
        for (int i = 0; i <= n; i++) {
            A[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            fichero >> ciudades[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                fichero >> A[i][j];
                if(i!=j && A[i][j]==0){
                    A[i][j] = INF;
                }
                if (fichero.fail()) {
                    throw runtime_error(LECTURA_MATRIZ_INCORRECTA);
                }
            }
        }

        fichero.close();
        cout << endl << nombreFichero << FICHERO_CARGADO << endl << endl;
        ficheroCargado = true;
    } catch (const std::runtime_error& e) {
        cerr << "#Error." << e.what() << endl;
    }
}


/* void printMatrix(float** matrix, int rows, int cols) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            cout << setw(10) << fixed << setprecision(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }
} */