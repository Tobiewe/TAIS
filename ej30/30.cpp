
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
