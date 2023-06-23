
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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

long long int costeSuma(priority_queue<long long int, vector<long long int>, greater<long long int>> cola_min) {
    long long int suma = 0, sumaFinal = 0, primero = 0;

    while (cola_min.size() > 1) {
        primero = cola_min.top();
        cola_min.pop();
        suma = primero + cola_min.top();
        cola_min.pop();
        sumaFinal += suma;
        cola_min.push(suma);
    }

    return sumaFinal;
}

bool resuelveCaso() {

    int n; cin >> n;
    long long int valor;

    if (n == 0)  // fin de la entrada
        return false;

    priority_queue<long long int, vector<long long int>, greater<long long int>> cola_min;

    for (int i = 0; i < n; i++) {
        cin >> valor;
        cola_min.push(valor);
    }

    cout << (cola_min.size() == 1 ? 0 : costeSuma(cola_min)) << "\n";

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
