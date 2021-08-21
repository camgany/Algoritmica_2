#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int v[10000];
int parent[10000];
int cont[10000];
int rango[10000];

int n;
void init() {
    for(int i=0;  i<= n; i++) {
        parent[i] = i;
        rango[i] = 0;
        cont[i] = 1;
    }
}

int find(int x) {//nos dice quien es el padre
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        
        return parent[x];
    }
}

void unionRango(int x,int y) { 
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
        cont[yRaiz] += cont[xRaiz];

    } else {
        parent[xRaiz] = yRaiz;
        cont[xRaiz] += cont[yRaiz];
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

int main() {
    input;
    output;
    cin>>n;
    init();
    int nrounionRangoes; 
    cin>>nrounionRangoes;
    while(nrounionRangoes--) {
        int numeroHabitantes;
        int numeroDeparejas;
        cin>>numeroHabitantes,numeroDeparejas;
        while(numeroDeparejas--){
            int x,y;
        cin>>x>>y; 
        cout<<<<endl;
           }
        } 
        
    return 0;
}


