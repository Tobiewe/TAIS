
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

class MaximaCompConexa {
private:

    vector<bool> visit;
    int maxim;


    int dfs(Grafo const& g, int v) {
        visit[v] = true;
        int tam = 1;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                tam += dfs(g, w);
            }
        }
        return tam;
    }


public:
    MaximaCompConexa(Grafo const& g) : visit(g.V(), false), maxim(0) {
        for (int v = 0; v < g.V(); ++v) {
            if (!visit[v]) { //se recorre una nueva componente conexa
                int tam = dfs(g, v);
                maxim = max(maxim, tam);
            }
        }
    }
    //tamaño maximo de una componente conexa
    int maximo() const {
        return maxim;
    }
};

void resuelveCaso() {

    int N; cin >> N; //numero de personas
    int M; cin >> M; //numero M de pares de personas que son amigas entre si

    Grafo amigos(N);

    int v, w;
    for (int i = 0; i < M; i++) {
        cin >> v >> w;
        amigos.ponArista(v - 1, w - 1);
    }

    MaximaCompConexa mcc(amigos);
    cout << mcc.maximo() << "\n";

}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
