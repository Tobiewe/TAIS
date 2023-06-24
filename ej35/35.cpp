
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

struct edificio {
    int izq;
    int der;
};

bool operator<(edificio e1, edificio e2) {
    return e1.izq < e2.izq;
}

int resolver(vector<edificio> lista) {
    int cont = 1;
    edificio anterior = lista[0];
    for (int i = 1; i < lista.size(); i++) {
        if (anterior.der > lista[i].izq) {
            if (lista[i].der < anterior.der) {
                anterior = lista[i];
            }
        }
        else {
            cont++;
            anterior = lista[i];
        }
    }
    return cont;
}

bool resuelveCaso() {

    int N; cin >> N;

    if (N == 0)  // fin de la entrada
        return false;

    vector<edificio> lista;
    int iz, dr;
    for (int i = 0; i < N; i++) {
        cin >> iz >> dr;
        lista.push_back({ iz, dr });
    }

    sort(lista.begin(), lista.end(), less<edificio>());

    cout << resolver(lista) << "\n";

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
