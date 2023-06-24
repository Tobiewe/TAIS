/*
 * MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificaci�n fuera de esas etiquetas no ser� corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes hab�is hecho esta soluci�n:
  * Estudiante 1:
  * Estudiante 2:
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

#include "DigrafoValorado.h"
#include "IndexPQ.h"


/*@ <answer>

 Leemos el grafo como de costumbre pero con una diferencia: invertimos el orden de las relaciones.
 Esto es para optimizar el tiempo y llamar una sola vez al algoritmo Dijkstra. As� pues, llamamos a 
 Dijkstra desde el vertice destino y calculamos el tiempo minimo que tarda en llegar a cada vertice.
 Al final vamos comparando cada tiempo con el tiempo maximo permitido y almacenamos el numero de 
 vertices a los que llega con esta restriccion.

 El coste es de O(A log V) siendo A el numero de aristas y V el numero de vertices del grafo.
 @ </answer> */

 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
 //@ <answer>

class Laberinto {
private:
    DigrafoValorado<int> g;
    const int INF = numeric_limits<int>::max();
    vector<int> dist;
    IndexPQ<int> pq;

    void leerGrafo(int A) {
        int n1, n2, valor;
        for (int i = 0; i < A; i++) {
            cin >> n1 >> n2 >> valor;
            g.ponArista({ n2-1, n1-1, valor });
        }
    }

    void dijkstra(int v) {
        dist[v] = 0;
        pq.push(v, 0);
        while (!pq.empty()) {
            int w = pq.top().elem; pq.pop();
            for (auto a : g.ady(w))
                relajar(a);
        }
    }

    void relajar(AristaDirigida<int> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]);
        }
    }

public:
    Laberinto(int V, int A) : g(V), dist(V, INF), pq(V) {
        leerGrafo(A);
    }

    int resolver(int T, int meta) {
        int cont = 0;
        dijkstra(meta - 1);
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] <= T && i != meta-1) {
                cont++;
            }
        }
        return cont;
    }

};



bool resuelveCaso() {

    // leemos la entrada
    int N, S, T, P;
    cin >> N >> S >> T >> P;

    if (!cin)
        return false;

    // leer el resto del caso y resolverlo

    Laberinto l(N, P);

    cout << l.resolver(T, S) << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta l�nea ya no forma parte de la soluci�n.

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
