/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1:Antonio Trenado Martin TAIS102
  * Estudiante 2:Alvaro del Campo Gragera TAIS16
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;


/*@ <answer>

    Leemos los datos y ordenamos de menor a mayor los rivales, los broncos de mayor a menor asi podemos comparar el mejor partido de los broncos con
    el peor de sus rivales y sacar la maxima diferencia de puntos. Esto lo logramos recorriendo ambos vectores y guardando la diferencia entre partidos
    solo cuado los broncos ganan.

    El coste de la funcion seria O(n) pero a esto le tenemos que sumar el coste de la ordenacion por lo que el coste total seria O(nlogn), siendo n el
    numero de elementos de los vectores.

    Este algoritmo encuntra la solucion optima en todos los casos ya que al ordenar los vectores obtenemos la maxima diferencia posible de puntos
    entre partidos.
    EJ=>    40 20 80 30  =>  20 30 40 80    Al ordenarlos obtenemos que el peor partido de los rivales que han obtenido 20 puntos se compara con el
            30 50 30 40  =>  50 40 30 30    mejor de los broncos que es 50 puntos y se obtiene una diferencia de 30 puntos que es la maxima posible.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

int resolver(vector<int> broncos, vector<int> rivales) {

    int sol = 0;
    int i = 0;

    while (i < broncos.size() && i < rivales.size()) {

        if (broncos[i] > rivales[i]) {

            sol += broncos[i] - rivales[i];

        }
        i++;
    }

    return sol;
}



bool resuelveCaso() {

    int N;
    cin >> N;  // número de partidos

    if (N == 0)
        return false;

    // leer el resto del caso y resolverlo


    vector<int> broncos, rivales;

    int puntos;

    for (int i = 0; i < N; i++) {
        cin >> puntos;
        rivales.push_back(puntos);
    }

    for (int i = 0; i < N; i++) {
        cin >> puntos;
        broncos.push_back(puntos);
    }


    sort(rivales.begin(), rivales.end());
    sort(broncos.begin(), broncos.end(), greater<int>());

    int sol = resolver(broncos, rivales);

    cout << sol << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}