
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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


bool resuelveCaso() {

    int N; cin >> N; //Numero de drones
    int A; cin >> A; //Numero de pilas 9V
    int B; cin >> B; //Numero de pilas 1.5V

    if (!std::cin)  // fin de la entrada
        return false;

    priority_queue<int> dronesA;
    priority_queue<int> dronesB;

    for (int i = 0; i < A; i++) {
        int n; cin >> n;
        dronesA.push(n);
    }

    for (int i = 0; i < B; i++) {
        int n; cin >> n;
        dronesB.push(n);
    }

    int horas = 0, noDron = 0;
    priority_queue<int>pendienteA, pendienteB;

    while (dronesA.size() > 0 && dronesB.size() > 0) {
        if (dronesA.top() < dronesB.top()) {
            int aux = dronesB.top();
            dronesB.pop();
            aux -= dronesA.top();
            horas += dronesA.top();
            dronesA.pop();
            pendienteB.push(aux);
        }
        else {
            int aux = dronesA.top();
            dronesA.pop();
            aux -= dronesB.top();
            horas += dronesB.top();
            dronesB.pop();
            if (aux != 0) {
                pendienteA.push(aux);
            }
        }
        noDron++;
        if (noDron == N || (dronesA.size() == 0 || dronesB.size() == 0)) {
            cout << horas << " ";
            horas = 0;
            noDron = 0;
            while (pendienteA.size() > 0) {
                dronesA.push(pendienteA.top());
                pendienteA.pop();
            }
            while (pendienteB.size() > 0) {
                dronesB.push(pendienteB.top());
                pendienteB.pop();
            }
        }
    }

    if (horas != 0) {
        cout << horas << " ";
    }

    cout << "\n";

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
