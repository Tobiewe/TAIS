/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Alvaro del Campo Gragera, TAIS16
  * Estudiante 2: Antonio Trenado Martin, TAIS102
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;


/*@ <answer>

Creamos una cola de prioridad con el struct caja que nos hemos creado (contiene el numero de caja y los segundos).
Vamos introduciendo en la cola el numero de caja del cliente y su tiempo. Esta cola se ordena por el menor tiempo, y en caso
de ser igual por el numero de caja menor. Si el numero de clientes es menor que el numero de cajas, la solucion es el numero de clientes mas uno.
Por otra parte, si el numero de clientes es mayor que el de cajas, se retira de la cola temporalmente el primero, se le suman los segundos del cliente
que toque, y se vuelve a anyadir a la cola ordenada por tiempo. La solución es el numero de caja del primero de la cola.

El coste es O(Nlog N), siendo N el numero de clientes.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>


struct caja {
    int numeroCaja;
    int segundos;
};


bool operator<(const caja& a, const caja& b) {
    return (a.segundos > b.segundos) || (a.segundos == b.segundos && a.numeroCaja > b.numeroCaja);
}


bool resuelveCaso() {

    // leemos la entrada
    int N, C;
    cin >> N >> C;
    if (N == 0)
        return false;

    priority_queue<caja> cola;
    int numero = 1;
    int segundos;

    for (int i = 0; i < C; i++) {
        caja aux;
        if (numero <= N) {
            aux.numeroCaja = numero;
            cin >> aux.segundos;
            cola.push(aux);
            numero++;
        }
        else {
            aux = cola.top();
            cola.pop();
            int s; cin >> s;
            aux.segundos += s;
            cola.push(aux);
        }

    }

    if (cola.size() < N) {
        cout << C + 1 << "\n";
    }
    else {
        cout << cola.top().numeroCaja << "\n";
    }

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}