#include <iostream>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#include<bits/stdc++.h>

using namespace std;

int v[10000],n,k;
int parent[10000];
int rango[10000];


void init() {
    for(int i=0;  i<= n; i++) {
        parent[i] = i;
        rango[i] = 0;
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

void unionRango(int x,int y) {
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



int main() {
    input;
    output;
    int maximo=-1000;
    //int ans=0;
    //cin>>n;
    for(int x = 1; x<=3; x++) {
        parent[x] = x;
    }
    unionRango(1,2);
    unionRango(3,1);
    unionRango(3,4);
    unionRango(5,4);
    unionRango(3,5);
    unionRango(4,6);
    unionRango(5,2);
    unionRango(2,1);
    unionRango(7,1);
    unionRango(1,2);
    unionRango(9,10);
    unionRango(8,9);
for(int x = 1; x<=3; x++) {
    int ans = 0;
    for(int i = 1; i<=3;i++){
          if(parent[i]==x){
                    ans++;
                    //cout<<ans<<endl; 
                } 
    }
    if(ans>maximo){
        maximo=ans;
    }
               
                    
            }   


    cout<<maximo<<endl;
    return 0;
}
