
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
