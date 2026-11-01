#include "Livre.h"
int Livre::compteurId = 0;
int Livre::nbInstances = 0;

Livre::Livre(string t, string a, Date d) :id(++compteurId), parution(d)
{
	this->nbNotes = 0;
	this->titre = t;
	this->auteur = a;
	this->notes= nullptr;
	nbInstances++;
}

Livre::Livre(const Livre& L): id(++compteurId),parution(L.parution)
{
	this->titre = L.titre;
	this->auteur = L.auteur;
	this->nbNotes = L.nbNotes;
	if (nbNotes > 0) {
		this->notes = new int[nbNotes];
		for (int i = 0; i < nbNotes; i++) {
			this->notes[i] = L.notes[i];
		}
	}
	else {
		this->notes = nullptr;
	}
	nbInstances++;
}

Livre& Livre::operator=(const Livre& L)
{
	if (this != &L) {
		this->titre = L.titre;
		this->auteur = L.auteur;
		this->parution = L.parution;
		delete[] this->notes;
		nbNotes = L.nbNotes;
		if (nbNotes > 0) {
			this->notes = new int[nbNotes];
			for (int i = 0; i < nbNotes; i++) {
				this->notes[i] = L.notes[i];
			}
		}
		else {
			this->notes = nullptr;
		}
	}
	return *this;
}

int Livre::getId() const
{
	return this->id;
}

string Livre::getTitre() const
{
	return this->titre;
}

int Livre::getNbInstances()
{
	return nbInstances;
}

bool Livre::ajouterNote(int n)
{
	if (n >= 0 && n <= 20) {
		int* nouv = new int[nbNotes + 1];
		for (int i = 0; i < nbNotes; i++) {
			nouv[i] = notes[i];
		}
		nouv[nbNotes] = n;
		delete[] notes;
		notes = nouv;
		nbNotes++;
		return true;
	}
	else {
		cout << "La note est invalide!" << endl;
		return false;
	}
}

double Livre::calculerMoyenne() const
{
	if (nbNotes == 0) {
		return 0.0;
	}
	double somme = 0.0;
	for (int i = 0; i < nbNotes; i++) {
		somme += notes[i];
	}
	return somme / nbNotes;
}

void Livre::afficher() const
{
	cout << "L'ID est: " << id << endl;
	cout << "Le titre est: " << titre << endl;
	cout << "L'auteur est: " << auteur << endl;
	cout << "La date de parution est: ";
	parution.Consulter();
	cout << endl;
	if (nbNotes == 0) {
		cout << "Avec aucune note" << endl;
	}
	else {
		cout << "Avec les notes: ";
		for (int i = 0; i < nbNotes; i++) {
			cout << notes[i] << " ";
		}
		cout << endl;
	}
	cout << "La moyenne est: " << calculerMoyenne() << endl;
}

Livre::~Livre()
{
	delete[] notes;
}

