
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
