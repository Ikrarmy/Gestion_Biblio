#pragma once
#include "Date.h"
#include <iostream>
using namespace std;

class Livre
{
private:
	const int id;
	string titre;
	string auteur;
	Date parution;
	int* notes;
	int nbNotes;
	static int compteurId;
	static int nbInstances;

public:
	Livre(string, string,Date);
	Livre(const Livre&);
	Livre& operator=(const Livre&);

	int getId() const;
	string getTitre() const;
	static int getNbInstances();

	bool ajouterNote(int);
	double calculerMoyenne() const;
	void afficher() const;
	~Livre();
};

