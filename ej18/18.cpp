
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

class tareas {
private:
    Digrafo d;
    vector<bool> visit;
    vector<bool> apilado;
    deque<int> topo;
    bool ciclo;

    void leerGrafo(int A) {
        int n1, n2;
        for (int i = 0; i < A; i++) {
            cin >> n1 >> n2;
            d.ponArista(n1 - 1, n2 - 1);
        }
    }

    void dfs(int v) {
        apilado[v] = true;
        visit[v] = true;
        for (int w : d.ady(v)) {
            if (ciclo) {
                return;
            }
            if (!visit[w]) {
                dfs(w);
            }
            else if (apilado[w]) {
                ciclo = true;

            }
        }
        apilado[v] = false;
        topo.push_front(v);
    }

    bool hayCiclo() {
        return ciclo;
    }

public:
    tareas(int V, int A) : d(V), visit(d.V(), false), apilado(d.V(), false), topo(0), ciclo(false) {
        leerGrafo(A);
        for (int i = 0; i < V; i++) {
            if (!visit[i]) {
                dfs(i);
            }
        }
    }

    void escribirSol() {
        if (hayCiclo()) {
            cout << "Imposible\n";
        }
        else {
            for (int i : topo) {
                cout << i+1 << " ";
            }
            cout << "\n";
        }
    }

};


bool resuelveCaso() {

    int N; cin >> N; //tareas a realizar
    int M; cin >> M; //relaciones directas

    if (!std::cin)  // fin de la entrada
        return false;

    tareas t(N, M);

    t.escribirSol();

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
