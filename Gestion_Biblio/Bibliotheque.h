#pragma once
#include "Livre.h"
#include <iostream>
using namespace std;

class Bibliotheque
{
private:
	string nom;
	Livre** livres;
	int nbLivres;
	int capacite;
	static int nbBibliotheques;

public:
	Bibliotheque(string,int);
	Bibliotheque(const Bibliotheque&);

	Bibliotheque& operator=(const Bibliotheque&);
	bool ajouterLivre(const Livre&);
	Bibliotheque& operator+=(const Livre&);

	Livre* rechercher(int) const;
	Livre* rechercher(string) const;

	void afficher() const;
	static int getNbBibliotheques();
	~Bibliotheque();
};

