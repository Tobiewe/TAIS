
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
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

class Cole {
private:
    GrafoValorado<int> g;
    const int INF = std::numeric_limits<int>::max();
    vector<int> veces;
    vector<int> dist;
    IndexPQ<int> pq;


    void leerGrafo(int A) {
        int n1, n2, valor;
        for (int i = 0; i < A; i++) {
            cin >> n1 >> n2 >> valor;
            g.ponArista({ n1-1, n2-1, valor });
        }
    }

    void relajar(Arista<int> a, int v) {
        int w = a.otro(v);
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            veces[w] = veces[v];
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor()) {
            veces[w] += veces[v];
        }
    }


    void minimo(int origen) {
        dist[origen] = 0;
        veces[origen] = 1;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a, v);
        }
    }

public:
    Cole(int V, int A) : g(V), dist(V, INF), pq(V), veces(V) {
        leerGrafo(A);
        minimo(0);
    }

    int menorCamino() {
        return veces[g.V() - 1];
    }

};

bool resuelveCaso() {

    int V; cin >> V;
    int A; cin >> A;

    if (!std::cin)  // fin de la entrada
        return false;

    Cole c(V, A);
    int m = c.menorCamino();
    cout << m << "\n";

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
