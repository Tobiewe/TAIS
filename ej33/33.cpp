
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class hora {
private:
    int hor, min;
    friend istream& operator>>(istream& in, hora& h);

public:

    hora() {
        hor = 0;
        min = 0;
    }

    hora operator+(int const& minutos) const {
        hora aux;
        aux.min = this->min + minutos;
        if (aux.min >= 60) {
            aux.hor = this->hor + aux.min / 60;
            aux.min = aux.min % 60;
        }
        else {
            aux.hor = this->hor;
        }

        return aux;
    }
    
    bool operator<=(hora const& h) const {
        return (this->hor * 60 + this->min) <= (h.hor * 60 + h.min);
    }

    bool operator<(hora const& h) const {
        return (this->hor * 60 + this->min) < (h.hor * 60 + h.min);
    }

};

istream& operator>>(istream& in, hora& h) {
    char aux;
    in >> h.hor >> aux >> h.min;

    return in;
}


class pelicula {
public:
    hora inicio, fin;
    int duracion;

    pelicula(hora inicio, hora fin, int duracion) {
        this->inicio = inicio;
        this->fin = fin;
        this->duracion = duracion;
    }

    bool operator<=(pelicula const& p) const {
        return this->fin <= p.inicio;
    }

    bool operator<(pelicula const& p) const {
        return this->fin < p.fin;
    }
};


int solucion(vector<pelicula>& p) {
    int cont = 1;
    hora fin = p[0].fin;
    for (int i = 1; i < p.size(); i++) {
        if (p[i].inicio < fin) {
            if (p[i].fin < fin) {
                fin = p[i].fin;
            }
        }
        else if (fin <= p[i].inicio) {
            cont++;
            fin = p[i].fin;
        }
    }
    return cont;
}


bool resuelveCaso() {

    int N; cin >> N;

    if (N == 0)  // fin de la entrada
        return false;

    vector<pelicula> peliculas;

    for (int i = 0; i < N; i++) {
        hora inicio;
        int dur;
        cin >> inicio; cin >> dur;
        dur += 10;
        hora fin = inicio + dur;
        peliculas.push_back({ inicio, fin, dur });
    }
    
    sort(peliculas.begin(), peliculas.end(), less<pelicula>());
    cout << solucion(peliculas) << "\n";

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
