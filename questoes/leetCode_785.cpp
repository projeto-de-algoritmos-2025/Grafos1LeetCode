#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& grafo) {
        int n = grafo.size();
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
