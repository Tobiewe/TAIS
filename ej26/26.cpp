
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Teclado {
private:
    DigrafoValorado<int> g;
    vector<int> coste;
    const int INF = numeric_limits<int>::max();
    vector<int> dist;
    IndexPQ<int> pq;

    void leerGrafo() {
        int n1, n2, valor;
        for (int i = 0; i < g.V(); i++) {
            cin >> n1;
            coste[i] = n1;
        }

        int M; cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> n1 >> n2 >> valor;
            g.ponArista({ n1-1, n2-1, valor });
        }
    }

    void dijkstra(int v) {
        dist[v] = 0 + coste[v];
        pq.push(v, 0);
        while (!pq.empty()) {
            int w = pq.top().elem; pq.pop();
            for (auto a : g.ady(w))
                relajar(a);
        }
    }
    
    void relajar(AristaDirigida<int> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() + coste[w]) {
            dist[w] = dist[v] + a.valor() + coste[w]; 
            pq.update(w, dist[w]);
        }
    }


public:
    Teclado(int N) : g(N), coste(N), dist(N, INF), pq(N) {
        leerGrafo();
        dijkstra(0);
    }

    int menorCoste() {
        if (dist[g.V() - 1] == INF) return -1;
        return dist[g.V() - 1];
    }

};



bool resuelveCaso() {

    int N; cin >> N;

    if (N == 0)  // fin de la entrada
        return false;

    Teclado t(N);

    int c = t.menorCoste();
    if (c == -1) {
        cout << "IMPOSIBLE\n";
    }
    else {
        cout << c << "\n";
    }

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
