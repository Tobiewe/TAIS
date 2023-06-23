
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


struct paciente {
    string nombre;
    int gravedad;
    int llegada;
};


bool operator <(paciente p1, paciente p2) {
    return p1.gravedad < p2.gravedad || p1.gravedad == p2.gravedad && p1.llegada > p2.llegada;
}


bool resuelveCaso() {

    int n; cin >> n;
    string evento;
    int orden = 1;

    if (n == 0)  // fin de la entrada
        return false;

    priority_queue<paciente> lista;

    for (int i = 0; i < n; i++) {
        paciente aux;
        cin >> evento;
        if (evento == "I") {
            cin >> aux.nombre;
            cin >> aux.gravedad;
            aux.llegada = orden;
            orden++;
            lista.push(aux);
        }
        else if (evento == "A") {
            cout << lista.top().nombre << "\n";
            lista.pop();
        }
    }

    cout << "---\n";

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
