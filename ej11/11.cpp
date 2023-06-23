
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
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

class Problema {
private:

    Grafo g;
    vector<bool> visit;
    vector<int> ant;
    int s;
    int vertices = 1;

    

    void leerGrafo(int v, int a) {
        int a1, a2;
        for (int i = 0; i < a; i++) {
            cin >> a1 >> a2;
            g.ponArista(a1, a2);
        }
    }

    void dfs(Grafo const& g, int v) {
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                ant[w] = v;
                dfs(g, w);
                vertices++;
            }
        }
    }

    bool hayCamino(int v) const {
        return visit[v];
    }

    bool conexo() {
        return vertices == g.V();
    }

    bool aciclico() {
        return conexo() && g.A() == g.V() - 1;
    }
    

public:

    Problema(int v, int a) : g(v), s(0), visit(g.V(), false), ant(g.V()) {
        leerGrafo(v, a);
        dfs(g, s);
    }

    bool arbolLibre() {
        return aciclico();
    }
};

bool resuelveCaso() {

    int V; cin >> V; //numero de vertices
    int A; cin >> A; //numero de aristas

    if (!std::cin)  // fin de la entrada
        return false;

    Problema prob(V, A);

    if (prob.arbolLibre()) cout << "SI\n";
    else cout << "NO\n";

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
