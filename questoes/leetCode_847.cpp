#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& grafo) {
        int n = grafo.size();
        int mascFim = (1 << n) - 1;
        queue<tuple<int, int, int>> fila;
        vector<vector<bool>> visitado (n, vector<bool> (1 << n , false)); 

        for (int i = 0 ; i < n ; i++){
            fila.push({i, 1 << i , 0}); 
            visitado[i][1 << i] = true;
        }
        
        while (!fila.empty()){
            auto[no, masc, passos] = fila.front();
            fila.pop();
            if (masc == mascFim) return passos; 
            for (int viz : grafo[no]){
                int novaMasc = masc | (1 << viz);  
                if (!visitado[viz][novaMasc]){
                    visitado[viz][novaMasc] = true;
                    fila.push({viz, novaMasc, passos + 1});
                }
            }
        }
        return -1;
    }
};