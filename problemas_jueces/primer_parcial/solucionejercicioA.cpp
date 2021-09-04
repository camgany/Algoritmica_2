#include <iostream>
#include<bits/stdc++.h>

using namespace std;

string number; 
int dp[20][2][20]; 

bool isPrime(int n) {   
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int solveDP(int pos, int mayor, int pares) {

    if(pos > number.size()) { 
        return 0;

    }



    if(pos==number.size()) {

        if(pares>=2) { //Tiene dos pares el numero?

            return 1;

        }

        else {

            return 0;

        }

    }



    if(dp[pos][mayor][pares]==-1) { 

        int tope = 9;  

        if(mayor==1) {

            tope = number[pos] - '0'; 

        }

        dp[pos][mayor][pares] = 0; 

        for(int digito = 0; digito<=tope; digito++) { 

            if(digito==tope) {


                dp[pos][mayor][pares] += solveDP(pos+1, 1,pares + isPrime(digito)); 

            } else {

                dp[pos][mayor][pares] += solveDP(pos+1, 0,pares + isPrime(digito)); 
                

            }


        }

    }

    return dp[pos][mayor][pares];


}


int main() {

    //Hallar los numeros que tengan 2 pares en su interior

    int a =200;

    number = to_string(a-1);
    memset(dp,-1, sizeof(dp));
    int paresHastaA = solveDP(0, 1, 0);
    int b = 220;
    memset(dp,-1, sizeof(dp));
    number = to_string(b);
    int paresHastaB = solveDP(0,1,0);
    int resultado;
    resultado=paresHastaB-paresHastaA;
    cout<<resultado<<endl;

    return 0;
}