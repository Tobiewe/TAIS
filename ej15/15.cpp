
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Redes {
private:
    Grafo g;
    vector<bool> visit;
    vector<int> ant;
    vector<int> dist;
    int s;

    void leerGrafo(int A) {
        int num1, num2;
        for (int i = 0; i < A; i++) {
            cin >> num1; cin >> num2;
            g.ponArista(num1 - 1, num2 - 1);
        }
    }

    void bfs(int origen, int TTL, int& n) {
        std::queue<int> q;
        dist[origen] = 0; visit[origen] = true;
        q.push(origen);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w] && dist[v] < TTL) {
                    ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
                    n--;
                    q.push(w);
                }
            }
        }
    }

    

public:
    Redes(int V, int A) : g(V), visit(g.V(), false), ant(g.V()), dist(g.V()), s(0) {
        leerGrafo(A);
    }

    void consultas() {
        int K; cin >> K;
        int origen, TTL;
        for (int i = 0; i < K; i++) {
            cin >> origen >> TTL;
            int n = g.V() - 1;
            bfs(origen - 1, TTL, n);
            cout << n << "\n";
            vector<bool> aux(g.V(), false);
            visit = aux;
        }
    }
};


bool resuelveCaso() {

    int N; cin >> N; // Numero de nodos
    int C; cin >> C; // Numero de conexiones

    if (!std::cin)  // fin de la entrada
        return false;

    Redes r(N, C);

    r.consultas();

    cout << "---\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
