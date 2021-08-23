#include <bits/stdc++.h> 

using namespace std; 
bool es_valido(int tablero[] [],int fila, int columna){//le damos un tablero y le ponemos en una fila y columna para poner una reina
//comprobamos que no existan reinas en la misma fila
for(int col =0; col<4;col++){//ninguna columna de la fila que estoy poniendo haya alguna reina
if(tablero[fila][col]==1){
return false;
}

}
//comprobamos diagonales izquierda superior
int row = fila, col = columna;
while(row>0 && col > 0){
if(tablero[row][col]==1);
row--;
col--;
}
//comprobamos diagonales izquierda inferior
int row = fila, col = columna;
while(row < 4 && col > 0){
if(tablero[row][col]==1);
row++;
col--;
}
}
void solve_queen(int columna, int tablero [][]){//pseudocodigo le mandamos la columna, el tablero, 
if (columna >= 4 ){//verificamos si ya pusieron todas las reinas //CASO BASE
print_solucion(tablero);//imprimira le tablero
}
for(int row = 0; row < 4; row++){//empezamos desde la fila cero
  if(es_valido(tablero, row, columna)){//verificamos si podemos poner ahi una reina //PODA
      tablero[row][columna]=1;//ponemos la reina
      solve_queen(columna+1,tablero);//llamamos con recursividad para poner mas reinas
      tablero[row][columna] = 0;//creamos un nuevo tablero y copiamos exactamente como esta
      //borramos la reina que no funciona
  }  
}
//SI COLOCAMOS ++ O -- PUEDE ENTRAR EN UN BUCLE INFINITO
}
void print_solucion(int tablero[][]){
    for(int fila = 0; fila < 4; fila++){
        for(int col = 0; col < 4; col++){
            printf("[%d]",tablero[fila][col]);
        }
        printf("\n");
    }
}
int main(){

}