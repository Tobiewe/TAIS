
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

struct registro {
    int momento;
    int id;
    int periodo;
};

bool operator <(registro const& a, registro const& b) {
    return b.momento < a.momento || (a.momento == b.momento && b.id < a.id);
}


bool resuelveCaso() {

    int n; cin >> n;
    int id, periodo;
    int envios;

    if (n == 0)  // fin de la entrada
        return false;

    priority_queue<registro> cola;

    for (int i = 0; i < n; i++) {
        cin >> id >> periodo;
        cola.push({ periodo, id, periodo });
    }

    cin >> envios;

    for (int i = 0; i < envios; i++) {
        auto e = cola.top();
        cola.pop();
        cout << e.id << "\n";
        e.momento += e.periodo;
        cola.push(e);
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
