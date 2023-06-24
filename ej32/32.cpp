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