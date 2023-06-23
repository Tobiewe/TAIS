/*
 * MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificaci�n fuera de esas etiquetas no ser� corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes hab�is hecho esta soluci�n:
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
que toque, y se vuelve a anyadir a la cola ordenada por tiempo. La soluci�n es el numero de caja del primero de la cola.

El coste es O(Nlog N), siendo N el numero de clientes.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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