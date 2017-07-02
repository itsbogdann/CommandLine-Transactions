#ifndef CLASE
#define CLASE
#include <iostream>
#include <string.h>

using namespace std;

class produs {

public:

	int id;
	int categ;
	double price;
	char name[100];

public:

	 produs() {
	 	this->id = 0;
		this->categ = 0;
		this->price = 0;
		strcpy(this->name, "");
	 }

	produs(int id, char name[], int categ, double price) {
		
		this->id = id;
		this->categ = categ;
		this->price = price;
		strcpy(this->name, name);
	}
	 
	~produs() {
	}

	produs(const produs &second_product) {
		
		this->id = second_product.id;
		this->categ = second_product.categ;
		this->price = second_product.price;
		strcpy(this->name, second_product.name);
	}

	void operator= (const produs &second_product) {
		
		this->id = second_product.id;
		this->categ = second_product.categ;
		this->price = second_product.price;
		strcpy(this->name, second_product.name);
	}
};

class bon {

public:

	long long int id;
	int id_produs;

public:

	bon() {
        this->id = 0;
		this->id_produs = 0;
	}

	bon(const bon &second_bon) {

		this->id = second_bon.id;
		this->id_produs = second_bon.id_produs;
	}

	~bon() {

	}

	void operator= (const bon &second_bon) {

		this->id = second_bon.id;
		this->id_produs = second_bon.id_produs;
	}

	bon(long long int id, int id_produs) {

		this->id = id;
		this->id_produs = id_produs;
	}

};

class categorie {

public:
	
	int id;
	char name[100];

public:

	categorie() {

		this->id = 0;
		strcpy(this->name,"");
	}

	categorie(int id, char name[]) {

		this->id = id;
		strcpy(this->name,name);
	}

	~categorie() {
	
	}

	categorie(const categorie &second_categ) {

		this->id = second_categ.id;
		strcpy(this->name,second_categ.name);
	}

	void operator= (const categorie &second_categ) {

		this->id = second_categ.id;
		strcpy(this->name,second_categ.name);
	}
};

class magazin {

public:

	int id;
	char locatie[20];

public:

	magazin() {

		this->id = 0;
		strcpy(this->locatie,"");
	}

	magazin(int id, char locatie[]) {

		this->id = id;		
		strcpy(this->locatie,locatie);
	}

	~magazin() {

	}

	magazin(const magazin &second_magazin) {

		this->id = second_magazin.id;
		strcpy(this->locatie,second_magazin.locatie);	
	}

	void operator= (const magazin &second_magazin) {

		this->id = second_magazin.id;
		strcpy(this->locatie,second_magazin.locatie);
	}
};

class palet {

public:

	char id[100];
	int prod_type;
	int n_intems;
	int slot;

public:

	palet() {

		strcpy(this->id, "");
		this->prod_type = 0;
		this->n_intems = 0;
		this->slot = 0;
	}

	palet(char id[], int prod_type, int n_intems, int slot) {

		strcpy(this->id,id);
		this->prod_type = prod_type;
		this->n_intems = n_intems;
		this->slot = slot;
	}

	~palet() {

	}

	palet(const palet &second_palet) {

		strcpy(this->id, second_palet.id);
		this->prod_type = second_palet.prod_type;
		this->n_intems = second_palet.n_intems;
		this->slot = second_palet.slot;		
	}

	void operator= (const palet &second_palet) {

		strcpy(this->id,second_palet.id);
		this->prod_type = second_palet.prod_type;
		this->n_intems = second_palet.n_intems;
		this->slot = second_palet.slot;		
	}
};

class tranzactie {

public:

    int id;
	char timestamp[100];
	long long int id_bon;
	int id_mag;

public:

	tranzactie() {
		this->id = 0;
		this->id_bon = 0;
		this->id_mag = 0;
		strcpy(this->timestamp, "");
	}

	tranzactie(int id, char timestamp[], long long int id_bon, int id_mag) {
		this->id = id;
		this->id_bon = id_bon;
		this->id_mag = id_mag;
		strcpy(this->timestamp, timestamp);
	}

	~tranzactie() {

	}

	tranzactie(const tranzactie &second_tranz) {
		this->id = second_tranz.id;
		this->id_bon = second_tranz.id_bon;
		this->id_mag = second_tranz.id_mag;
		strcpy(this->timestamp, second_tranz.timestamp);
	}

	void operator= (const tranzactie &second_tranz) {
		this->id = second_tranz.id;
		this->id_bon = second_tranz.id_bon;
		this->id_mag = second_tranz.id_mag;
		strcpy(this->timestamp, second_tranz.timestamp);
	}
};

#endif