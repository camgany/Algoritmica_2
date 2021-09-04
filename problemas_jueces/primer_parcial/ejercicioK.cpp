#include <bits/stdc++.h> 
//#define input freopen("in.txt", "r", stdin)
//#define output freopen("out.txt", "w", stdout)
using namespace std;

//int v[10000];
int parent[110];
//int cont[10000];
int rango[110];

void init(int n) {
    for(int i=0;  i<= n; i++) {
        parent[i] = i;
        rango[i] = 0;
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
    int xRaiz = find(x);
    int yRaiz = find(y);
    if (xRaiz == yRaiz) return;
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
        //cont[yRaiz] += cont[xRaiz];

    } else {
        parent[xRaiz] = yRaiz;
        //cont[xRaiz] += cont[yRaiz];
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}
float euclidian(pair<float, float> a, pair<float, float> b) {
    float x = a.first - b.first;
    float y = a.second - b.second;
    return sqrt(x * x + y * y);
}

bool compare(pair<float, pair<int, int> > a, pair<float, pair<int, int> > b) {
    return a.first < b.first;
}
 

int main() {
   // input;
   // output;
 int casos, numberOfFreckers;
    float x, y;
    scanf("%d", &casos);
    while (casos--) {
        scanf("%d", &numberOfFreckers);
 
        vector<pair<float, float> > points;
        float matrix[numberOfFreckers][numberOfFreckers];
        float visited[numberOfFreckers], cost[numberOfFreckers], prev[numberOfFreckers];
 
        for (int i = 0; i < numberOfFreckers; i++) {
            scanf("%f %f", &x, &y);
            points.push_back(make_pair(x, y));
        }
 
        init(numberOfFreckers);
 
        vector<pair<float, pair<int, int> > > E;
        E.clear();
        vector<pair<float, pair<int, int> > > X;
        X.clear();
        for (int i = 0; i < numberOfFreckers; i++) {
            for (int j = i + 1; j < numberOfFreckers; j++) {
                E.push_back(make_pair(euclidian(points[i], points[j]), make_pair(i, j)));
            }
        }
        sort(E.begin(), E.end(), compare);
 
        for (int i = 0; i < E.size(); i++) {
            if (find(E[i].second.first) != find(E[i].second.second)) {
                X.push_back(E[i]);
                unionRango(E[i].second.first, E[i].second.second);
            }
        }
 
        float total = 0;
        for (int i = 0; i < X.size(); i++) total += X[i].first;
        printf("%.2f\n", total);
 
        if(casos > 0) printf("\n");
    }
}

