#include "Bibliotheque.h"
int Bibliotheque::nbBibliotheques = 0;

Bibliotheque::Bibliotheque(string n, int cap)
{
	this->nom = n;
	this->nbLivres = 0;
	if (cap > 0) {
		this->capacite = cap;
	}
	else{
		this->capacite = 0;
	}
	this->livres = new Livre* [capacite];
	for (int i = 0; i < capacite; i++) {
		this->livres[i] = nullptr;
	}
	nbBibliotheques++;
}


Bibliotheque::Bibliotheque(const Bibliotheque& B)
{
	this->nom = B.nom;
	this->nbLivres = 0;
	this->capacite = B.capacite;
	this->livres = new Livre* [capacite];
	for (int i = 0; i < B.nbLivres && i < capacite; i++)
	{
		this->livres[i] = new Livre(*B.livres[i]);
		nbLivres++;
	}
	for (int i = nbLivres; i < capacite; i++) {
		this->livres[i] = nullptr;
	}
	nbBibliotheques++;
}

Bibliotheque& Bibliotheque::operator=(const Bibliotheque& B)
{
	if (this != &B) {
		for (int i = 0; i < nbLivres; i++) {
			delete this->livres[i];
		}
		delete[] this->livres;
		this->nom = B.nom;
		this->nbLivres = 0;
		this->capacite = B.capacite;
		this->livres =new Livre* [capacite];
		for (int i = 0; i < B.nbLivres && i < capacite; i++) {
			this->livres[i] = new Livre(*B.livres[i]);
			nbLivres++;
		}
		for (int i = nbLivres; i < capacite; i++) {
			this->livres[i] = nullptr;
		}
	}
	return *this;
}

bool Bibliotheque::ajouterLivre(const Livre& L)
{
	if (nbLivres < capacite) {
		this->livres[nbLivres] = new Livre(L);
		nbLivres++;
		return true;
	}
	return false;
}

Bibliotheque& Bibliotheque::operator+=(const Livre& L)
{
	this->ajouterLivre(L);
	return *this;
}

Livre* Bibliotheque::rechercher(int id) const
{
	for (int i = 0; i < nbLivres; i++) {
		if (this->livres[i]->getId() == id) {
			return this->livres[i];
		}
	}
	return nullptr;
}

Livre* Bibliotheque::rechercher(string titre) const
{
	for(int i = 0; i < nbLivres; i++) {
		if (this->livres[i]->getTitre() == titre) {
			return this->livres[i];
		}
	}
	return nullptr;
}

void Bibliotheque::afficher() const
{
	cout << "Le nom de la bibliothèque : " << this->nom << endl;
	cout << "Avec le nombre de livres de: " << this->nbLivres << endl;
	cout << "De capacité : " << this->capacite << endl;
	if(nbLivres == 0) {
		cout << "La bibliothèque est vide." << endl;
		return;
	}
	for (int i = 0; i < nbLivres; i++) {
		cout << "Livre " << i + 1 << " : " << endl;
		this->livres[i]->afficher();
	}
}

int Bibliotheque::getNbBibliotheques()
{
	return nbBibliotheques;
}

Bibliotheque::~Bibliotheque()
{
	for (int i = 0; i < nbLivres; i++) {
		delete this->livres[i];
	}
	delete[] this->livres;
	this->livres = nullptr;
	nbBibliotheques--;
}


