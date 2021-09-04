#include <bits/stdc++.h> 
// #define input freopen("in.txt", "r", stdin)
// #define output freopen("out.txt", "w", stdout)
using namespace std;

int parent[10000];
int cont[10000];
int rango[10000];
int elements[10000];
int maximo;
void init(int n) {
    for(int i=0;  i< n; ++i) {
        parent[i] = i;
        rango[i] = 0;
        //cont[i] = 1;
        elements[i]=1;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        
        return parent[x];
    }
}

bool sameParent(int x, int y){
     return find(x) == find(y);
}

void unionRango(int x,int y) { 
    //int xRaiz = find(x);
    //int yRaiz = find(y);
    if(!sameParent(x,y)){
    if(rango[x] > rango[y]) {
        parent[y] = x;
        elements[x] += elements[y];
            maximo = ( maximo < elements[x] ) ? elements[x] : maximo;
        //cont[yRaiz] += cont[xRaiz];
        //cout<<"["<<cont[yRaiz]<<"]"<<endl;

    } else {
        parent[x] = y;
        elements[y] += elements[x];
            maximo = ( maximo < elements[y] ) ? elements[y] : maximo;
        //cont[xRaiz] += cont[yRaiz];
        //cout<<"["<<cont[yRaiz]<<"]"<<endl;
        if(rango[x] == rango[y]) {
            rango[y]++;
            
        }
    }
    }
}
 void unir(int x, int y){
     unionRango(find(x),find(y));
 }
int main() {
   // input;
   // output;
    int casos;
    cin>>casos;
    while(casos--){
    int n,m;
    cin>>n>>m;
    init(n);
    maximo = 1;
    while(m--) {
        int x,y;
        cin>>x>>y;
        --x,--y;
        unir(x,y);
    }
    /*int sol = -1;
    for(int i=1;i<=n;i++){
        cout<<parent[i]<<endl;
        cout<<"{"<<rango[i]<<"}"<<endl;
        if(i == parent[i]) {
            sol = max(sol,cont[i]);
        }
    }*/
    cout<<maximo<<endl;
    }
    return 0;
}





