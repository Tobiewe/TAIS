/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

/*@ <answer>
 *
 * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
 * Estudiante 1: Alvaro del Campo Gragera
 * Estudiante 2: Antonio Trenado Martin
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
#include "Grafo.h"
using namespace std;


/*@ <answer>
 
 Primero leemos la cantidad de oro y la asignamos a un deque que tiene tamaño el numero de vertices.
 De esta forma cuando queramos acceder al oro de un vertice miramos su posicion en este deque.

 Despues leemos las relaciones del grafo de forma habitual. Para resolver el ejercicio lo que hacemos
 es visitar todas las componentes conexas y guardar el valor del oro menor, que acumularemos en el entero total.
 Esa es la solucion.

 El coste del problema es O(V+A) siendo V el numero de vertices y A el numero de aristas.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>

class Overcity {
private:
    Grafo g;
    vector<bool> visit;
    deque<int> oro;

    void leerOro() {
        for (int i = 0; i < g.V(); i++) {
            int n; cin >> n;
            oro[i] = n;
        }
    }

    void leerRelaciones(int A) {
        int n1, n2;
        for (int i = 0; i < A; i++) {
            cin >> n1 >> n2;
            g.ponArista(n1 - 1, n2 - 1);
        }
    }

    int dfs(int v) {
        visit[v] = true;
        int menor = oro[v];
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                menor = std::min(menor, dfs(w));
            }
        }
        return menor;
    }


public:
    Overcity(int V, int A) : g(V), visit(g.V(), false), oro(g.V()) {
        leerOro();
        leerRelaciones(A);
    }

    void escribirSol() {
        int total = 0;
        for (int i = 0; i < g.V(); i++) {
            if (!visit[i]) {
                total += dfs(i);
            }
        }

        cout << total << "\n";
    }

};



bool resuelveCaso() {
  
  // leemos la entrada
   int N, M;
   cin >> N >> M;
   
   if (!cin)
      return false;

   Overcity o(N, M);
  
   o.escribirSol();
  
  
  return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
  system("PAUSE");
#endif
  return 0;
}
