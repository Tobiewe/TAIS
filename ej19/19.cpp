
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

class Sumidero {
private:
    Digrafo g;
    vector<int> recibe;
    vector<bool> salida;
    bool sum;
    int vertice;


    void leerGrafo(int A) {
        int n1, n2;
        for (int i = 0; i < A; i++) {
            cin >> n1 >> n2;
            g.ponArista(n1, n2);
        }
    }

    void sumidero(int v) {
        for (int w : g.ady(v)) {
            salida[v] = true;
            recibe[w]++;
            if (recibe[w] == g.V() - 1) {
                sum = true;
                vertice = w;
            }
        }
    }


public:
    Sumidero(int V, int A) : g(V), recibe(V), salida(V, false), sum(false), vertice(-1) {
        leerGrafo(A);
        if (V == 1) {
            sum = true;
            vertice = 0;
        }
        else {
            for (int i = 0; i < V; i++) {
                sumidero(i);
            }
        }
        
    }


    void escribirSol() {
        if (sum && !salida[vertice]) {
            cout << "SI " << vertice << "\n";
        }
        else {
            cout << "NO\n";
        }
    }

};


bool resuelveCaso() {

    int V; cin >> V;
    int A; cin >> A;

    if (!std::cin)  // fin de la entrada
        return false;

    Sumidero s(V, A);

    s.escribirSol();

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
