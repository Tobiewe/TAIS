
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>


struct tarea {
    int ini;
    int fin;
    int periodo;
};


bool operator<(tarea a, tarea b) {
    return (a.ini > b.ini) || (a.ini == b.ini && a.fin > b.fin);
}


bool conflicto(priority_queue<tarea> lista, int T) {
    bool c = false;
    
    while (lista.top().ini < T && !c && lista.size() > 1) {
        tarea aux = lista.top();
        lista.pop();
        if (aux.fin > lista.top().ini && lista.top().ini < T) {
            c = true;
        }
        if (aux.periodo != 0) {
            aux.ini += aux.periodo;
            aux.fin += aux.periodo;
            lista.push(aux);
        }
    }

    return c;
}


bool resuelveCaso() {

    int N; cin >> N; //# tareas unicas
    int M; cin >> M; //# tareas periodicas
    int T; cin >> T; //# minutos en los q quiero averiguar si hay o no conflictos

    if (!std::cin)  // fin de la entrada
        return false;

    priority_queue<tarea> lista;

    for (int i = 0; i < N; i++) {
        tarea aux;
        cin >> aux.ini;
        cin >> aux.fin;
        aux.periodo = 0;
        lista.push(aux);
    }

    for (int i = 0; i < M; i++) {
        tarea aux;
        cin >> aux.ini;
        cin >> aux.fin;
        cin >> aux.periodo;
        lista.push(aux);
    }

    if (conflicto(lista, T)) {
        cout << "SI\n";
    }
        
    else {
        cout << "NO\n";
    }
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
