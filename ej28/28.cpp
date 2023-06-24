
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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

const int INF = std::numeric_limits<int>::max();

class CallesBFS {
private:
    vector<bool> visit;
    vector<int> dist;


    int bfs(GrafoValorado<int> g, int origen, int destino) {
        int cont = INF;
        queue<int> q;
        dist[origen] = 0; visit[origen] = true;
        q.push(origen);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto w : g.ady(v)) {
                int z = w.otro(v);
                if (!visit[z]) {
                    dist[z] = dist[v] + 1;
                    visit[z] = true;
                    q.push(z);
                    if (z == destino && dist[z] < cont) {
                        cont = dist[z];
                    }
                }
            }
        }
        return cont;
    }

public:
    CallesBFS(GrafoValorado<int> g) : visit(g.V(), false), dist(g.V()) {

    }

    int resuelveCaso(GrafoValorado<int> g, int origen, int destino) {
        return bfs(g, origen, destino);
    }

};



class CallesDijkstra {
private:
    vector<int> dist;
    vector<int> aristas;
    IndexPQ<int> pq;
    


    pair<int, int> dijkstra(GrafoValorado<int> g, int origen, int destino) {
        pair<int, int> aux;
        dist[origen] = 0;
        aristas[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int w = pq.top().elem; pq.pop();
            for (auto a : g.ady(w))
                relajar(a, w);
        }
        aux.first = dist[destino];
        aux.second = aristas[destino];
        return aux;
    }

    void relajar(Arista<int> a, int z) {
        int v = z, w = a.otro(z);
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            aristas[w] = aristas[v] + 1;
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor() && aristas[w] > aristas[v] + 1) {
            aristas[w] = aristas[v] + 1;
            pq.update(w, dist[w]);
        }
    }


public:
    CallesDijkstra(GrafoValorado<int> g) : dist(g.V(), INF), pq(g.V()), aristas(g.V()) {
        
    }

    pair<int, int> resuelveCaso(GrafoValorado<int> g, int origen, int destino) {
        return dijkstra(g, origen, destino);
    }
    
};





bool resuelveCaso() {

    int N; cin >> N;
    int C; cin >> C;

    if (!std::cin)  // fin de la entrada
        return false;

    GrafoValorado<int> g(N);
    int n1, n2, valor;
    for (int i = 0; i < C; i++) {
        cin >> n1 >> n2 >> valor;
        g.ponArista({ n1 - 1, n2 - 1, valor });
    }

    int k, origen, destino;; cin >> k;
    for (int i = 0; i < k; i++) {
        CallesBFS cb(g);
        CallesDijkstra cd(g);

        cin >> origen >> destino;
        int cam = cb.resuelveCaso(g, origen - 1, destino - 1);
        pair <int, int> sol = cd.resuelveCaso(g, origen - 1, destino - 1);

        if (cam != INF) {
            cout << sol.first << " ";
            if (cam == sol.second) {
                cout << "SI\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "SIN CAMINO\n";
        }
    }

    cout << "---\n";


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
