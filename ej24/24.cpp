
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "ConjuntosDisjuntos.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Islas {
private:
    GrafoValorado<int> g;
    int coste;

    void leerGrafo(int A) {
        int n1, n2, coste;
        for (int i = 0; i < A; i++) {
            cin >> n1 >> n2 >> coste;
            g.ponArista({ n1-1,n2-1,coste });
        }
    }

    int kruskal() {
        int visitados = 0;
        vector<Arista<int>> v = g.aristas();
        priority_queue<Arista<int>, vector<Arista<int>>, greater<Arista<int>>> cola(v.begin(), v.end());
        ConjuntosDisjuntos cjtos(g.V());
        while (!cola.empty()) {
            auto a = cola.top(); cola.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                visitados++;
                coste += a.valor();
                if (visitados == g.V() - 1) return coste;
            }
        }
        return -1;
    }


public:
    Islas(int V, int A) : g(V), coste(0) {
        leerGrafo(A);
    }

    int costeMin() {
        if (g.V() == 1) {
            return 0;
        }
        else {
            return kruskal();
        }
    }

};


bool resuelveCaso() {

    int V; cin >> V; // Numero de islas
    int A; cin >> A; // Numero de puentes

    if (!std::cin)  // fin de la entrada
        return false;

    Islas i(V, A);

    int c = i.costeMin();

    if (c == -1) {
        cout << "No hay puentes suficientes\n";
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
    std::ifstream in("Text.txt");
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
