
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

class Noticias {
private:
    Grafo g;
    vector<bool> visit;
    vector<int> sol;


    void leerGrafo(int A) {
        int tam;
        for (int i = 0; i < A; i++) {
            cin >> tam;
            if (tam > 0) {
                int num1, num2; cin >> num1;
                for (int j = 0; j < tam-1; j++) {
                    cin >> num2;
                    g.ponArista(num1 - 1, num2 - 1);
                    num1 = num2;
                }
            }
        }
    }

    int dfs(int v, vector<int>& conexo) {
        visit[v] = true;
        int n = 1;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                n += dfs(w, conexo);
                conexo.push_back(w);
            }
        }
        return n;
    }

public:
    Noticias(int V, int A): g(V), visit(g.V(), false), sol(g.V()) {
        leerGrafo(A);
        calculoConexas();
    }

    void calculoConexas() {
        for (int i = 0; i < g.V(); i++) {
            vector<int> conexo;
            if (!visit[i]) {
                conexo.push_back(i);
                int n = dfs(i, conexo);
                for (int j = 0; j < conexo.size(); j++) {
                    sol[conexo[j]] = n;
                }
            }
        }
    }

    void escribirSol() {
        for (int i = 0; i < sol.size(); i++) {
            cout << sol[i] << " ";
        }
        cout << "\n";
    }
};

bool resuelveCaso() {

    int N; cin >> N; // Numero usuarios
    int M; cin >> M; // Numero Grupos

    if (!std::cin)  // fin de la entrada
        return false;

    Noticias n(N, M);

    n.escribirSol();

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
