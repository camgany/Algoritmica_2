#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
#include <stdio.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
#define F(ss) find(ss)
#define TWIN(ff) ((ff%2)?(ff+1):(ff-1))
#define T(ff) TWIN(ff)
#define ENEMIES(a, b) (F(b) == F(T(a)) || F(a) == F(T(b)))
#define FRIENDS(a, b) (F(a) == F(b) || F(T(a)) == F(T(b)))

vector<int> parent;
//int parent[10000];
//int cont[10000];
///int rango[10000];

void init(int n) {
    parent = vector<int> (n + 1);
    for(int i=1;  i<= n+1; i++) {
        parent[i] = i;
        //rango[i] = 0;
        //cont[i] = 1;
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
    parent[find(x)]=find(y);
}

int main() {
    input;
    output;
    int N;
    int C, f1, f2;
 
   while (scanf("%d", &N) == 1) {
        init(2 * N);
        while ((scanf("%d %d %d\n", &C, &f1, &f2) == 3)) {
            if (C == 0 && f1 == 0 && f2 == 0) break;
            f1 = 2*f1 +1, f2=2*f2+1;
            if (C == 1) {
                if (ENEMIES(f1, f2)) printf("-1\n");
                else  unionRango(f1, f2), unionRango(TWIN(f1), TWIN(f2));
            }
            if (C == 2) {
                if (FRIENDS(f1, f2)) printf("-1\n");
                else  unionRango(f1, TWIN(f2)), unionRango(f2, TWIN(f1));
            }
            if (C == 3) {
                if (FRIENDS(f1, f2)) printf("1\n");
                else printf("0\n");
            }
            if (C == 4) {
                if (ENEMIES(f1, f2)) printf("1\n");
                else printf("0\n");
            }
        }
    }
 
    return 0;
}