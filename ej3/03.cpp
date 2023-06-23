
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
