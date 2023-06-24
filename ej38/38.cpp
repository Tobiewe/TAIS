
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

int resolver(vector<int> pesos, vector<bool> visitado, int max) {
    int cont = 0;
    int i = 0, j;
    while (i < pesos.size()) {
        j = i + 1;
        if (!visitado[i]) {
            if (pesos[i] == max) {
                cont++;
                i++;
            }
            else {
                while (j < pesos.size()) {
                    if (!visitado[j]) {
                        if (pesos[i] + pesos[j] <= max) {
                            visitado[j] = true;
                            break;
                        }
                    }
                    j++;
                }
                cont++; visitado[i] = true; i++;
            }
        }
        else {
            i++;
        }
    }

    return cont;
}

bool resuelveCaso() {

    int max, N;
    cin >> max >> N;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> pesos;
    int valor;
    for (int i = 0; i < N; i++) {
        cin >> valor;
        pesos.push_back(valor);
    }
    sort(pesos.begin(), pesos.end(), greater<int>());

    vector<bool> visitados(N, false);

    cout << resolver(pesos, visitados, max) << "\n";

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
