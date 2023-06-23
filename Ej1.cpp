/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;



struct sol {
	bool avl;
	int altura, menor, mayor;
};

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

sol es_avl_rec(BinTree<int> const& arbol) {
	if (arbol.empty()) {
		return { true, 0, 0, 0 };
	}
	else {
		auto [avl_iz, alt_iz, menor_iz, mayor_iz] = es_avl_rec(arbol.left());
		auto [avl_dr, alt_dr, menor_dr, mayor_dr] = es_avl_rec(arbol.right());

		int altura = std::max(alt_iz, alt_dr) + 1;
		int menor = arbol.left().empty() ? arbol.root() : menor_iz;
		int mayor = arbol.right().empty() ? arbol.root() : mayor_dr;
		bool ordenado = (arbol.left().empty() || mayor_iz < arbol.root()) &&
			(arbol.right().empty() || arbol.root() < menor_dr);

		return { ordenado && avl_iz && avl_dr && abs(alt_iz - alt_dr) < 2, altura, menor, mayor };
	}
}

void resuelveCaso() {

	// leer los datos de la entrada
	BinTree<int> t = read_tree<int>(cin);

	// resolver el caso posiblemente llamando a otras funciones
	sol solucion = es_avl_rec(t);
	
	// escribir la solución
	cout << (solucion.avl ? "SI" : "NO") << "\n";
	//cout << solucion.altura << " " << solucion.mayor << " " << solucion.menor << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Texto.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}