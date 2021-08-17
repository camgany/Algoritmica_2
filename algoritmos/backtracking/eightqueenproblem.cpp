#include <bits/stdc++.h> 

using namespace std; 

bool isValid(int tablero [8][8], int row, int column){
   for (int i=0;i<8;i++){//verificamos si no hay otra reyna a lo horizontal
       if(tablero[i][column]==1){
           return false;
       }else{
           return true;
       }
   }
   for (int i=0;i<8;i++){
       if(tablero[row][i]==1){//verificamos si no hay otra reyna a lo vertical
           return false;
       }else{
           return true;
       }
   }
   for (int i=0;i<8-column;i++){//verificamos de forma diagonal
       if(tablero[row-i][column]==1||tablero[row+i][column]==1||tablero[row][column-i]==1||tablero[row][column+i]==1){
           return false;
       }else{
           return true;
       }
   }
   
}
int solve8queen(int total, int tablero[8][8],int fila, int columna){
    if(!isValid(tablero,fila,columna)){
        return ;
    }
    if(total==8){
        for(int col = 0; col<8;col++){
            for(int row = 0; row<8;row++){
            cout<<"[" << tablero[col][row]<< "]";
        }
        cout<<endl;
        }       
    }
    for(int row=0;row<8;row++){
        for(int col=0;col<8;col++){
            if(tablero[row][col]==0){
                tablero[row][col]=1;
                if(isValid(tablero,fila,columna)){
                    solve8queen(total+1,tablero,fila,columna);
                }else{
                    tablero[row][col]=0;
                }
            }
        }
    }
}