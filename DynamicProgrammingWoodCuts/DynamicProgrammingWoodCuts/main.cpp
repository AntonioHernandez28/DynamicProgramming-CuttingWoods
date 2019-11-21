//
//  main.cpp
//  DynamicProgrammingWoodCuts
//
//  Created by Antonio Hernández Ruiz on 10/8/19.
//  Copyright © 2019 Antonio Hernández Ruiz. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    
    int Largo;
    cin >> Largo;
    
    while(Largo){
        if(Largo == 0) break;
        int Cortes[51]; // Uno mas que el maximo de cortes para tener de sobra una columna
        int DP[51][51];
        int Cuts;
        cin >> Cuts;
        for(int i = 1; i <= Cuts; i++) cin >> Cortes[i]; //Llenamos la matriz de cortes con los cortes que tendremos que hacer desde 1 porque la primer columna es 0
        Cortes[0] = 0;
        Cortes[++Cuts] = Largo;
        for(int j = 1; j <= Cuts; j++) {
            for(int i = j - 1; i >= 0; i--) {
                if(i + 1 == j) DP[i][j] = 0;
                else {
                    DP[i][j] = INT_MAX;
                    for(int k = i + 1; k < j; k++) {
                        if(DP[i][k] + DP[k][j] < DP[i][j])
                            DP[i][j] = DP[i][k] + DP[k][j];
                    }
                    DP[i][j] += Cortes[j] - Cortes[i];
                }
            }
        }

        cout << "The minimum cutting is " << DP[0][Cuts] << "." << endl;
        cin >> Largo;
    }
    return 0;
}


