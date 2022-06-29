#include "coda.h"
int main() {
	coda<giocatore> c;
	coda<giocatore>::create(c);
	//coda<giocatore>::print_order(c, "decrescente");
	//coda<giocatore>::print_cognome(c, "Sciortino");
	cout << "-----------------------------------------" << endl;
	c.remove_player(c, 25.8);
	cout << c;
}