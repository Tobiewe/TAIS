/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Alvaro del Campo Gragera, TAIS16
  * Estudiante 2: Antonio Trenado Martin, TAIS102
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
//#include "PriorityQueue.h"


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

class Aeropuerto {
private:
    GrafoValorado<int> g;
    int coste_min;
    int comp_conexas;

    void leerGrafo(int A) {
        int n1, n2, valor;
        for (int i = 0; i < A; i++) {
            cin >> n1 >> n2 >> valor;
            g.ponArista({ n1-1, n2-1, valor });
        }
    }

    void kruskal(int coste) {
        int visitados = 0;
        vector<Arista<int>> v = g.aristas();
        priority_queue<Arista<int>, vector<Arista<int>>, greater<Arista<int>>> cola(v.begin(), v.end());
        ConjuntosDisjuntos cjtos(g.V());
        while (!cola.empty()) {
            auto a = cola.top(); cola.pop();
            int v = a.uno(), w = a.otro(v);
            if (coste <= a.valor()) {
                break;
            }
            else if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                visitados++;
                coste_min += a.valor();
                if (visitados == g.V() - 1) break;
            }
        }
        comp_conexas = cjtos.num_cjtos();
        coste_min += cjtos.num_cjtos() * coste;
    }


public:
    Aeropuerto(int V, int A, int coste) : g(V), coste_min(0), comp_conexas(1) {
        leerGrafo(A);
        kruskal(coste);
    }

    pair<int, int> coste_minimo() {
        return { coste_min, comp_conexas };
    }

};



bool resuelveCaso() {

    // leemos la entrada
    int V, A, coste;
    cin >> V >> A >> coste;
    if (!cin)
        return false;

    // leer el resto del caso y resolverlo

    Aeropuerto a(V, A, coste);

    cout << a.coste_minimo().first << " " << a.coste_minimo().second << "\n";


    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}
