/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

/*@ <answer>
 *
 * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
 * Estudiante 1: Alvaro del Campo Gragera, TAIS16
 * Estudiante 2: Antonio Trenado Martín, TAIS102
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;


/*@ <answer>
 
 Tenemos un struct con los musicos de un instrumento y las partituras que tienen disponibles.
 Introducimos en la cola cada instrumento con sus partituras (inicialmente todas tendrán una partitura).
 Hacemos un bucle para las partituras que sobran (es decir, P-N), y les vamos dando partituras
 a los grupos de instrumentos que al añadir una partitura se pueda dividir de forma optima 
 (aqui entra en juego la funcion atril).
 Finalmente, la solucion es el numero mayor de personas que tienen que comparir partitura.

 El coste total sería O(Nlog (P-N)).
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>


struct musico {
    int musicos;
    int parituras;
};

int atril(musico musico) {
    if (musico.musicos % musico.parituras == 0) { //las partituras se dividen a partes iguales
        return musico.musicos / musico.parituras;
    }
    else {
        return musico.musicos / musico.parituras + 1;
    }
}

bool operator < (musico a, musico b) {
    return atril(a) < atril(b);
}


bool resuelveCaso() {
  
  // leemos la entrada
   int P, N; //numero partituras que podemos comprar, numero de instrumentos distintos
   cin >> P >> N;
   
   if (!cin)
      return false;
  
   priority_queue<musico> orquesta;
   int n;

   for (int i = 0; i < N; i++) {
       cin >> n;
       orquesta.push({n, 1});
   }


   for (int i = 0; i < P-N; i++) {
        auto aux = orquesta.top();
        orquesta.pop();
        aux.parituras++;
        orquesta.push(aux);
   }
  
   cout << atril(orquesta.top()) << "\n";
  
  
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
