
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int agujeros_en_manguera(vector<int> agujeros, int longParches) {
    int cont = 1;
    int inicioParche = agujeros[0];
    for (int i = 0; i < agujeros.size()-1; i++) {
        if (inicioParche + longParches < agujeros[i + 1]) {
            cont++;
            inicioParche = agujeros[i + 1];
        }
    }
    return cont;
}

bool resuelveCaso() {

    int N; cin >> N; // Numero de agujeros
    int L; cin >> L; // Longitud de parches

    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> agujeros(N);
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        agujeros[i] = n;
    }

    cout << agujeros_en_manguera(agujeros, L) << "\n";

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
