
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>


void reequilibra(priority_queue<int>&menores, priority_queue<int, vector<int>, greater<int>>&mayores) {
    if (menores.size() < mayores.size()) {
        menores.push(mayores.top());
        mayores.pop();
    }
    else if (menores.size() > mayores.size() + 1) {
        mayores.push(menores.top());
        menores.pop();
    }
}

void insertar(priority_queue<int>& menores, priority_queue<int, vector<int>, greater<int>>& mayores, int x) {
    if (menores.empty()) {
        menores.push(x);
    }
    else {
        int med = menores.top();
        if (x < med) {
            menores.push(x);
        }
        else {
            mayores.push(x);
        }
        reequilibra(menores, mayores);
    }
}

bool resuelveCaso() {

    int n; cin >> n;
    int m; cin >> m;

    if (n == 0 && m == 0)  // fin de la entrada
        return false;

    priority_queue<int>menores;
    priority_queue<int, vector<int>, greater<int>>mayores;

    insertar(menores, mayores, n);
    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        insertar(menores, mayores, n1); insertar(menores, mayores, n2);
        cout << menores.top() << " ";
    }

    cout << "\n";

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
