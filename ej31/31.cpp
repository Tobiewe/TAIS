
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
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

int combate(vector<int>& enemigos, vector<int>& defensa) {
    sort(enemigos.begin(), enemigos.end(), less<int>());
    sort(defensa.begin(), defensa.end(), less<int>());
    int victorias = 0;
    int i = 0, j = 0;
    while (i < enemigos.size() && j < defensa.size()) {
        if (enemigos[i] <= defensa[j]) {
            victorias++;
            i++;
        }
        j++;
    }
    return victorias;
}

void leerDatos(int N, vector<int>& enemigos, vector<int>& defensa) {
    int n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        enemigos[i] = n;
    }

    for (int i = 0; i < N; i++) {
        cin >> n;
        defensa[i] = n;
    }
}

bool resuelveCaso() {

    int N; cin >> N; // ciudades invadidas y equipos de defensa

    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> enemigos(N);
    vector<int> defensa(N);

    leerDatos(N, enemigos, defensa);

    cout << combate(enemigos, defensa) << "\n";

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
