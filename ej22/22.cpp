
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
const vector<pair<int, int>> direcciones = { {0,1},{0,-1}, {1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} }; 


bool resuelveCaso() {

    int F; cin >> F;
    int C; cin >> C;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<vector<bool>> fondo(F, vector<bool>(C));
    ConjuntosDisjuntos cjto(F * C);
    cin.ignore();
    bool hayMax = false;
    int maximo = 0;
    for (int i = 0; i < F; ++i) {
        string linea;
        getline(cin, linea, '\n');

        for (int j = 0; j < C; j++) {
            if (linea.at(j) == '#') {
                hayMax = true;
                fondo[i][j] = true;
                int posUnaDim = (i * C + j);
                for (auto dir : direcciones) {
                    int iDir = i + dir.first, jDir = j + dir.second;
                    int posUnaDimDir = ((iDir)*C + (jDir));
                    if (iDir >= 0 && jDir >= 0 && iDir < F && jDir < C && fondo[iDir][jDir] && !cjto.unidos(posUnaDim, posUnaDimDir)) {
                        cjto.unir(posUnaDim, posUnaDimDir);
                        maximo = max(maximo, cjto.cardinal(posUnaDim));
                    }
                }
            }
        }

    }
    if (hayMax && maximo == 0) {
        maximo = 1;
    }
    cout << maximo << " ";

    int casos; cin >> casos;
    if (maximo == 0 && casos > 0) {
        maximo = 1;
    }

    while (casos--) {
        int fila; cin >> fila;
        int columna; cin >> columna;
        fila--; columna--;
        fondo[fila][columna] = true;
        int posUnaDim = (fila * C + columna);
        for (auto dir : direcciones) {
            int iDir = fila + dir.first, jDir = columna + dir.second;
            int posUnaDimDir = ((iDir)*C + (jDir));
            if (iDir >= 0 && jDir >= 0 && iDir < F && jDir < C && fondo[iDir][jDir] && !cjto.unidos(posUnaDim, posUnaDimDir)) {
                cjto.unir(posUnaDim, posUnaDimDir);
                maximo = max(maximo, cjto.cardinal(posUnaDim));
            }
        }
        cout << maximo << " ";
    }
    cout << '\n';

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
