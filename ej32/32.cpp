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

bool resuelveCaso() {

    int N, M;
    cin >> N >> M;
    vector<int> tallas;
    vector<int> jugadores;

    if (!std::cin)  // fin de la entrada
        return false;

    int numero;

    for (int i = 0; i < N; i++) {
        cin >> numero;
        jugadores.push_back(numero);
    }

    for (int i = 0; i < M; i++) {
        cin >> numero;
        tallas.push_back(numero);
    }

    sort(jugadores.begin(), jugadores.end());
    sort(tallas.begin(), tallas.end());

    int cont = 0, i = 0, j = 0;
    while (i < jugadores.size() && j < tallas.size()) {

        if (jugadores[i] == tallas[j] || jugadores[i] == tallas[j] - 1) {
            cont++;
            i++;
            j++;
        }
        else if (tallas[j] > jugadores[i]) {
            i++;
        }
        else if (tallas[j] < jugadores[i]) {
            j++;
        }
    }

    cout << N - cont << "\n";

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