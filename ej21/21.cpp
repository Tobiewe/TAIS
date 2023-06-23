
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

class Necronomicon {
private:
    Digrafo g;
    vector<bool> visit;
    vector<bool> apilado;
    bool llegaAfin;
    bool ciclo;

    void leerGrafo() {
        for (int i = 0; i < g.V()-1; i++) {
            string s;
            cin >> s;
            if (s == "A") { // Instrucciones aritmeticas o de asignacion
                g.ponArista(i, i + 1);
            }
            else if (s == "J") { // Instrucciones de salto
                int N; cin >> N;
                g.ponArista(i, N-1);
            }
            else if (s == "C") { // Instrucciones de salto condicionales
                int N; cin >> N;
                g.ponArista(i, N-1);
                g.ponArista(i, i + 1);
            }
        }
    }

    void dfs(int v) {
        apilado[v] = true;
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (w == g.V()-1) {
                llegaAfin = true;
            }
            
            if (!visit[w]) {
                dfs(w);
            }
            else if (apilado[w]) {
                ciclo = true;

            }
        }
        apilado[v] = false;
    }


public:
    Necronomicon(int V) : g(V+1), apilado(V+1, false), visit(V+1, false), llegaAfin(false), ciclo(false) {
        leerGrafo();
        dfs(0);
    }

    void escribirSol() {
        if (!llegaAfin) {
            cout << "NUNCA\n";
        }
        else {
            if (ciclo) {
                cout << "A VECES\n";
            }
            else {
                cout << "SIEMPRE\n";
            }
        }
    }
};


bool resuelveCaso() {

    int L; cin >> L; //Numero de instrucciones

    if (!std::cin)  // fin de la entrada
        return false;

    Necronomicon n(L);

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
