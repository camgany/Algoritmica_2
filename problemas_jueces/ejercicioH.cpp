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
    int casos;
    cin>>casos;
    while(casos>0){
        int people;
        int pairs;
        int maximo=0;
        cin>> people,pairs;
        for(int x = 1; x<=people; x++) {
                  parent[x] = x;
                 }
        while(pairs--){
            int a,b;
            cin>>a,b;
              unionRango(a,b);
        }
        for(int x = 1; x<=people; x++) {
                  cout<<"["<<parent[x]<<"]"<<endl;
                 }
        int ans = 0;
         for(int x =1;x<=people;x++){
        if(parent[x]==x){
         // for(int y = 1; y<=people;y++){
            //  if(parent[y]==x){
                  ans++;
                  cout<<ans<<endl;
              }
          //}
        
    }

    
    
    if(ans>maximo){
        maximo=ans;     
    }   

    cout<<ans<<endl;
       casos--; 
    }
    
    //int ans=0;
    //cin>>n;
    return 0;
}
