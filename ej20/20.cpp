
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


class Juego {
private:
    Digrafo g;
    int k;


    void leerGrafo(int S, int E) {
        int n1, n2;
        for (int i = 0; i < S; i++) {
            cin >> n1 >> n2;
            g.ponArista(n1-1, n2-1);
        }

        for (int i = 0; i < E; i++) {
            cin >> n1 >> n2;
            g.ponArista(n1 - 1, n2 - 1);
        }
    }

    int bfs(int origen, int destino, int n) {
        if (origen == destino) {
            return 0;
        }
        vector<bool> visit(n);
        visit[origen] = true;
        vector<int> distancia(destino);
        distancia[origen] = 0;
        queue<int> cola;
        cola.push(origen);
        while (!cola.empty()) {
            int v = cola.front();
            cola.pop();
            for (int i = 1; i <= k; ++i) {
                int w = v + i;
                if (w >= destino) {
                    w = destino - 1;
                }
                if (!g.ady(w).empty()) {
                    w = g.ady(w)[0];
                }
                if (!visit[w]) {
                    visit[w] = true;
                    distancia[w] = distancia[v] + 1;
                    if (w == destino - 1) {
                        return distancia[w];
                    }
                    else {
                        cola.push(w);
                    }
                }
            }
        }
    }


public:

    Juego(int V, int K, int S, int E) : g(V* V), k(0) {
        leerGrafo(S, E);
        k = K;
    }

    void escribirSol() {
        cout << bfs(0, g.V(), g.V()) << "\n";
    }

};



bool resuelveCaso() {

    int N; cin >> N; // Dimension del tablero
    int K; cin >> K; // Numero caras del dado
    int S; cin >> S; // Numero de serpientes
    int E; cin >> E; // Numero de escaleras

    if (N == 0 && K == 0 && S == 0 && E == 0)  // fin de la entrada
        return false;

    Juego j(N, K, S, E);
    j.escribirSol();

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
