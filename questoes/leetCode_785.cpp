#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class UF {
public:
    vector<int> pai;
    vector<int> altura;

    UF(int n) {
        pai.resize(n);
        altura.resize(n, 1);
        for (int i = 0; i < n; ++i)
            pai[i] = i;
    }

    int encontrar(int no) {
        while (no != pai[no]) {
            pai[no] = pai[pai[no]];
            no = pai[no];
        }
        return no;
    }

    void unir(int a, int b) {
        int raiz_a = encontrar(a);
        int raiz_b = encontrar(b);
        if (raiz_a == raiz_b) return;
        if (altura[raiz_a] < altura[raiz_b]) {
            pai[raiz_a] = raiz_b;
        } else {
            pai[raiz_b] = raiz_a;
            if (altura[raiz_a] == altura[raiz_b])
                altura[raiz_a]++;
        }
    }

    bool conectados(int a, int b) {
        return encontrar(a) == encontrar(b);
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& grafo) {
        int n = grafo.size();
        UF uf(n);
        unordered_map<int, int> cores;

        for (int i = 0; i < n; ++i) {
            if (cores.find(i) == cores.end()) {
                cores[i] = 0;
                stack<int> pilha;
                pilha.push(i);

                while (!pilha.empty()) {
                    int no = pilha.top(); pilha.pop();
                    for (int vizinho : grafo[no]) {
                        if (cores.find(vizinho) == cores.end()) {
                            cores[vizinho] = 1 - cores[no];
                            pilha.push(vizinho);
                        } else if (cores[vizinho] == cores[no]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

