
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct intervalo {
    int comienzo; 
    int fin;
};

bool operator<(intervalo i1, intervalo i2) {
    return i1.comienzo < i2.comienzo;
}

pair<bool, int> solucion(vector<intervalo> lista, intervalo planeta) {
    pair<bool, int> sol; sol.first = false; sol.second = 0;
    int cubiertoHasta = planeta.comienzo;
    int siguiente = 0;

    while (!sol.first && cubiertoHasta < planeta.fin) {
        int max = -1;
        while (siguiente < lista.size() && lista[siguiente].comienzo <= cubiertoHasta) {
            if (lista[siguiente].fin > max) {
                max = lista[siguiente].fin;
            }
            siguiente++;
        }
        if (max != -1) {
            sol.second++;
            cubiertoHasta = max;
        }
        else {
            sol.first = true;
        }
    }

    return sol;
}

bool resuelveCaso() {

    int C, F, N; cin >> C >> F >> N;

    if (C == 0 && F == 0 && N == 0)  // fin de la entrada
        return false;

    intervalo planeta{ C, F };
    vector<intervalo> lista;

    for (int i = 0; i < N; i++) {
        int c, f; cin >> c >> f;
        lista.push_back({ c, f });
    }

    sort(lista.begin(), lista.end(), less<intervalo>());
    pair<bool, int> sol = solucion(lista, planeta);

    if (!sol.first) {
        cout << sol.second << "\n";
    }
    else {
        cout << "Imposible\n";
    }

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
