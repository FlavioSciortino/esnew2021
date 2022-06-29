#include"giocatore.h"
#ifndef CODA_H
#define CODA_H
template<typename T>
class nodo {
	nodo<T> * next;
	//nodo<T> * prev;
	T val;
	template<typename U>
	friend class coda;
public:
	nodo(T val) : val(val) {next = nullptr; }
	nodo<T> * getNext() {return this->next; }
	//nodo<T> * getPrev() {return this->prev; }
	friend ostream & operator<<(ostream &os, nodo & n) {
		return os << n.val << endl;
		return os;
	}
};

template<typename T>
class coda {
	nodo<T> * head;
	int size = 0;
public:
	coda() { head = nullptr; }
	bool isEmpty() {return head == nullptr; }
	void enqueue(T val) {
		if(isEmpty()) {
			head = new nodo<T>(val);
			return;
		}
		nodo<T> * ptr = head;
		while(ptr->next) {
			ptr = ptr->next;
		}
		nodo<T> * toInsert = new nodo<T> (val);
		ptr->next = toInsert;
		return;
	}

	nodo<T> *  dequeue() {
		if(isEmpty()) 
			return nullptr;
		nodo<T> * tmp = head;
		head = head->next;
		
		return tmp;

	}

	void remove_element(giocatore val) {
		if(isEmpty()) {
			cout << "empty " << endl;
			return ;
		}
		nodo<T> * cur = head;
		nodo<T> * p = nullptr;
		while(cur->next && cur->val != val) {
			p = cur;
			cur = cur->next;
		}

		p->next = cur->next;
		delete cur;
		return;
	}
	static coda create(coda & c) {
		ifstream fin("Punteggi.txt");
		while(fin.good()) {
			giocatore g("", ""," ", 0.0, 0);
			fin>>g;
			c.enqueue(g);
		}
		fin.close();
		return c;
	}

	void swap(nodo<T> * n1, nodo<T> * n2) {
		giocatore tmp = n1->val;
			n1->val = n2->val;
			n2->val = tmp;
	}

	void order(string choise) {
		if(choise == "crescente") {
			nodo<T> * cur = head;
			nodo<T> * succ = cur->next;
			for(cur = head; cur->next; cur = cur->next) {
				for(succ = cur->next; succ; succ = succ->next) {
					if(cur->val >= succ->val)
						swap(cur, succ);
				}
			}
		}

		if(choise == "decrescente") {
			nodo<T> * cur = head;
			nodo<T> * succ = cur->next;
			for(cur = head; cur->next; cur = cur->next) {
				for(succ = cur->next; succ->next; succ = succ->next) {
					if(cur->val <= succ->val)
						swap(cur, succ);
				}
			}
		}
	}

	static void print_order(coda &c, string choise) {
		if(choise == "crescente")
			c.order("crescente");
		else
			c.order("decrescente");
	}

	static void print_cognome(coda &c, string cognome) {
		if(c.isEmpty()) 
			return;
		nodo<T> * cur = c.head;
		nodo<T> * el = c.head;
		nodo<T> * p = c.head;
		while(cur) {
			if(cognome == cur->val.getCognome()) {
				cout << "info giocatore con cognome : " << cur->val.getCognome()<< " " << cur->val << endl;
			}
			cur = cur->next;

		}

		while(el) {
			if(cognome == el->val.getCognome()) {
				while(p) {
					if(el->val.getPunteggio() == p->val.getPunteggio()) {
						cout << "stesso punteggio = " << p->val << endl;
					}
					p = p->next;
				}
				
			}
			el = el->next;
		}
	}


	void remove_player(coda &c, double key){

			if(isEmpty())
			{
				cerr << "\nVoid list, impossible find element with key " << key << " !" << endl;
				return;
			}

			nodo<T>* cur = head;
			bool found = true;
			nodo<T>* g = head;

			while(cur->next)
			{
				if(cur->val.getPunteggio() == key) 
					remove_element(cur->val);
					
					//cout << "cur->val" << cur->val << endl;
					
				

				cur = cur->next;
			}

			if(cur->val.getPunteggio() != key) 
				cerr << "\nElement with key " << key << " not found!" << endl;

			return;	
		}
			

	friend ostream &operator<<(ostream &os, coda<T> & c) {
		if(c.isEmpty()) {
			cout << "empty " << endl;
			return os;
		}
		nodo<T> * ptr = c.head;
		while(ptr) {
			os << *ptr << endl;
			ptr = ptr->getNext();
		}
		return os;

	}
};
#endif