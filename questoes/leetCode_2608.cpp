#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
  int findShortestCycle(int numVertices, vector<vector<int>>& arestas) {
    vector<vector<int>> grafo(numVertices);
    for (const auto& aresta : arestas) {
      int u = aresta[0], v = aresta[1];
      grafo[u].push_back(v);
      grafo[v].push_back(u);
    }

    const int INF = 1 << 30;
    int menorCiclo = INF;

    for (int inicio = 0; inicio < numVertices; ++inicio) {
      vector<int> distancia(numVertices, -1);
      queue<pair<int, int>> fila;
      distancia[inicio] = 0;
      fila.emplace(inicio, -1);

      while (!fila.empty()) {
        auto [atual, pai] = fila.front();
        fila.pop();

        for (int vizinho : grafo[atual]) {
          if (distancia[vizinho] == -1) {
            distancia[vizinho] = distancia[atual] + 1;
            fila.emplace(vizinho, atual);
          } else if (vizinho != pai) {
            menorCiclo = min(menorCiclo, distancia[atual] + distancia[vizinho] + 1);
          }
        }
      }
    }

    return menorCiclo == INF ? -1 : menorCiclo;
  }
};
