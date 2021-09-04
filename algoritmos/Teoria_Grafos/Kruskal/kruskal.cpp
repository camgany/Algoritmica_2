#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
// Variables
#define MAX_N 10000

using namespace std; 


int v[MAX_N];
int parent[MAX_N];// nos ayuda del union find
int rango[MAX_N];// nos ayuda del union find

int N, E; 

void init() {// vuelve a cada uno su propio padre
    for(int i=0;  i<= MAX_N; i++) { 
        parent[i] = i;
        rango[i] = 0;
    }
}

int find(int x) {// nos dice si es su padre
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

bool sameComponent(int nodeA,int nodeB) {// preguntamos si esta en el mismo arbol
    return find(nodeA) == find(nodeB);// vemos si estan en el mismo arbol, en la misma componenete, si es true, significa que si forman un ciclo
}


void unionRango(int x,int y) {// une los rangos
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

struct Arista{ //esta estructura crea el inicio,final,peso 
    int origen;
    int destino; 
    double peso; 
    Arista(){}

    bool operator<(const Arista &a) const {//hacemos una sobrecarga de operador, modifica a la funcion sort
        // decimos que cuando usemos el sort, utilicemos el menos y lo ordene
        return peso < a.peso;
    }
}aristas[MAX_N]; //creamos un array de aristas,puede ser -1 ya que no vamos a tener mass de uno, por que siempre las aristas van a ser n -1

Arista MST[MAX_N]; // n-1 aristas 


double kruskal(int nroNodos, int nroAristas) {//N y M
    
    int origen, destino;
    double peso;

    double total = 0;// TOTAL del arbol de expansion minimo

    int numAristasArbol = 0;//contamos el numero de aristas

    init(); // Iniciar el union Find 
    
    sort(aristas,aristas + nroAristas);  // la arista con menor peso hasta la de mayor peso 
    // ordenamos con el sort, pero puede variar y le decimos por cual atributo ordenar, en este caso el peso
    // hubiera sido sino
    //sort[array,array+n]
    //array=[a,b,c,d,e]
    // n = 5
    //sort (array,array+5)
    //el sort utiliza el operador <, pero nosotros lo modificamos para que lo ordene por peso en la estructura arista
    for (int i = 0; i < nroAristas; i++)
    {
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if(!sameComponent(origen,destino)) {//preguntamos si forman un ciclo
            total+=peso; //al total le ponemos el peso que va a tener
            MST[numAristasArbol] = aristas[i];//guardamos el numero de aristas, en que posicion estamos tomando, ponemos que aristas estamos uniendo
            //nos ayuda a imprimir
            numAristasArbol++;
            unionRango(origen,destino);//unimos los nodos
        }
    }
    return total;//retornamos el peso total del arbol
}


double distancia(double pointX1,double pointY1, double pointX2, double pointY2) {
    // sqrt((x1-x2)^2 + (y1-y2)^2)
    double x = pointX2 - pointX1;
    double y = pointY2 - pointY1;

    return sqrt(x*x+y*y); 
}


int main(){
    input;

    int tCases; 
    cin>>tCases; 
    while(tCases--) {

        cin>>N;
        double points[2][N];
        for( int i = 0 ; i < N ; ++i ){
            cin>>points[0][i]>>points[1][i];
        }
        int nroVertice=0; 
        for( int i=0;i<N-1;i++) {
            for(int j=i+1;j<N;j++) {
            aristas[nroVertice].origen = i;
            aristas[nroVertice].destino = j;
            aristas[nroVertice].peso = distancia(points[0][i],points[1][i],points[0][j],points[1][j]); 
            nroVertice++;
            }
        }
        double total = kruskal(N,nroVertice);

        cout<<total<<endl;
    }

    return 0;
}