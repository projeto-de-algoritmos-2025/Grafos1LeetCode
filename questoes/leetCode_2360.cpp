#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

class Solution {
public:
    int dfs(vector<int>& grafo, int noAtual, int passo, vector<int>& visitadoEm, vector<int>& tamanhoDoCiclo) {
        if (noAtual == -1) return -1;
        if (tamanhoDoCiclo[noAtual]) return tamanhoDoCiclo[noAtual];
        if (visitadoEm[noAtual]) {
            tamanhoDoCiclo[noAtual] = passo - visitadoEm[noAtual] + 1;
            return tamanhoDoCiclo[noAtual];
        }
        passo++;
        visitadoEm[noAtual] = passo;
        int cicloEncontrado = dfs(grafo, grafo[noAtual], passo, visitadoEm, tamanhoDoCiclo);
        tamanhoDoCiclo[noAtual] = cicloEncontrado;
        return cicloEncontrado;
    }

    int longestCycle(vector<int>& grafo) {
        int totalNos = grafo.size();
        vector<int> tamanhoDoCiclo(totalNos, 0);
        vector<int> visitadoEm(totalNos, 0);
        int maior = -1;
        for (int inicio = 0; inicio < totalNos; inicio++) {
            maior = max(maior, dfs(grafo, inicio, 0, visitadoEm, tamanhoDoCiclo));
        }
        return maior;
    }
};
