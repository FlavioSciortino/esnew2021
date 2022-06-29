#include<iostream>
#include<fstream>
using namespace std;
#ifndef GIOCATORE_H
#define GIOCATORE_H
#include<fstream>
class giocatore {
	string cognome, nome, circolo;
	int anno;
	double punteggio;
public:
	giocatore(string nome, string cognome, string circolo, int anno, double punteggio) : nome(nome), cognome(cognome), anno(anno), punteggio(punteggio)  {}
	friend ostream &operator<<(ostream &os, giocatore & g) {
		os << "nome = " << g.nome << endl;
		os << "cognome = " << g.cognome << endl;
		os << "circolo = " << g.circolo << endl;
		os << "anno = " << g.anno << endl;
		os << "punteggio = " << g.punteggio << endl;
		return os;
	}

	friend istream &operator>>(istream &is, giocatore & g) {
		string punteggio_str;
			string anno_str;
			
			std::getline(is, g.cognome, ';');
			std::getline(is, g.nome, ';');
			std::getline(is, g.circolo, ';');
			std::getline(is, punteggio_str, ';');
			std::getline(is, anno_str, '\n');
			g.punteggio = std::atof(punteggio_str.c_str());
			g.anno = std::atoi(anno_str.c_str());
			
			return is;
	}

	bool operator>=(giocatore &g) {return this->punteggio >= g.punteggio; }
	bool operator<=(giocatore &g) {return this->punteggio <= g.punteggio;}
	bool operator==(giocatore & g) {return this->punteggio = g.punteggio; }
	bool operator!=(giocatore & g) {return this->punteggio != g.punteggio; }
	double getPunteggio() {return this->punteggio; }
	string getCognome() {return this->cognome; }
	void setCognome(string cognome) {this->cognome = cognome; }
	
	
};
#endif