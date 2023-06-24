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

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

const int INF = 100000000;

struct cordel {
    int longitud;
    int coste;
};


bool sePuede(vector<cordel>& cordeles, Matriz<bool>& posible, int N, int L) {
    posible[0][0] = true;
    for (int i = 1; i <= N; i++) {
        posible[i][0] = true;
    }
    for (int j = 1; j <= L; j++) {
        posible[0][j] = false;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= L; j++) {
            if (cordeles[i].longitud <= j) {
                posible[i][j] = posible[i - 1][j - cordeles[i].longitud] || posible[i - 1][j];
            }
            else {
                posible[i][j] = posible[i - 1][j];
            }
        }
    }
    return posible[N][L];
}


long long int numManeras(vector<cordel>& cordeles, Matriz<long long int>& maneras, int N, int L) {
    maneras[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        maneras[i][0] = 1;
    }
    for (int j = 1; j <= L; j++) {
        maneras[0][j] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= L; j++) {
            if (cordeles[i].longitud <= j) {
                maneras[i][j] = maneras[i - 1][j - cordeles[i].longitud] + maneras[i - 1][j];
            }
            else {
                maneras[i][j] = maneras[i - 1][j];
            }
        }
    }
    return maneras[N][L];
}


int minCuerdas(vector<cordel>& cordeles, Matriz<int>& cuerdas, int N, int L) {
    for (int i = 0; i <= N; i++) {
        cuerdas[i][0] = 0;
    }
    for (int j = 0; j <= L; j++) {
        cuerdas[0][j] = INF;
    }
    cuerdas[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= L; j++) {
            if (cordeles[i].longitud <= j) {
                cuerdas[i][j] = min(cuerdas[i - 1][j - cordeles[i].longitud] + 1, cuerdas[i - 1][j]);
            }
            else {
                cuerdas[i][j] = cuerdas[i - 1][j];
            }
        }
    }
    return cuerdas[N][L];
}


int minCoste(vector<cordel>& cordeles, Matriz<int>& coste, int N, int L) {
    for (int i = 0; i <= N; i++) {
        coste[i][0] = 0;
    }
    for (int j = 1; j <= L; j++) {
        coste[0][j] = INF;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= L; j++) {
            if (cordeles[i].longitud <= j) {
                coste[i][j] = min(coste[i - 1][j - cordeles[i].longitud] + cordeles[i].coste, coste[i - 1][j]);
            }
            else {
                coste[i][j] = coste[i - 1][j];
            }
        }
    }
    return coste[N][L];
}



bool resuelveCaso() {

    int N; cin >> N; // numero de cuerdas
    int L; cin >> L; // longitud deseada

    if (!std::cin)  // fin de la entrada
        return false;

    vector<cordel> cordeles(N + 1);
    Matriz<bool> posible(N + 1, L + 1, false);

    for (int i = 1; i <= N; i++) {
        cin >> cordeles[i].longitud >> cordeles[i].coste;
    }

    if (sePuede(cordeles, posible, N, L)) {
        cout << "SI ";
        Matriz<long long int> maneras(N + 1, L + 1, -1);
        cout << numManeras(cordeles, maneras, N, L) << " ";
        Matriz<int> cuerdas(N + 1, L + 1, -1);
        cout << minCuerdas(cordeles, cuerdas, N, L) << " ";
        Matriz<int> coste(N + 1, L + 1, -1);
        cout << minCoste(cordeles, coste, N, L) << "\n";
    }
    else {
        cout << "NO\n";
    }

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