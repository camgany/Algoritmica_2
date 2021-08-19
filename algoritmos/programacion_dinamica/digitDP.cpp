#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
 
string number = "10";
int dp [20][2][20];//esta contando la cantidad, no el numero


bool isPrime(int n){
    if(n == 1 || n == 0) {
        return false;
    }
    if(n == 2) {
        return true;
    } 
    // i*i es mas lento que sqrt(n); 
    for(int i = 3; i*i<=n; i+=2) {
        if( n%i == 0) {
            return false;
        }
    }
    return true;
}



int solve_dp(int posicion, int mayor, int primos){//nos pide 3 parametros
     if(posicion == number.size()){//cuando la posicion exceda al numero dado
         return 0;
     }
     //modificar
     /*if (posicion==number.size()){
         if(pares == 2){
             return 1;
         }else{
             return 0;
         }*/

     //}


     if(dp[posicion][mayor][primos]== -1){//pregunto si lo he calculado
//preguntamos si estoy en el tope
int tope = 9;//cuando el mayor es falso el tope sera 9
if(mayor == true){//el numero que voy a crear puede llegar a ser mayor
 tope= number[posicion]-'0';//solo podemos usar los numeros de 0 a tope --- '3'-'0'
// en codigo ascii es 51 - 48 = 3
}
for (int digito=0; digito<=tope;digito++){
    if (digito == tope){
        //modificar
        dp[posicion][mayor][primos] += solve_dp(posicion+1,true, isPrime(primos));
    }else{// 0 1 o 2
dp[posicion][mayor][primos]+=solve_dp(posicion+1,false,isPrime(primos));
    }
}
     }
}


 int main(){
     memset(dp,-1,sizeof(dp));
     int ans = solve_dp(0, false, 0);
     cout<<ans<<endl;
     return 0;
 }