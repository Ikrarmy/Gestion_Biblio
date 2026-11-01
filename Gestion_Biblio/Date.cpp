#include "Date.h"

Date::Date(int j, int m, int a)
{
	if (!estValide(j, m, a)) {
		cout << "La date est invalide!" << endl;
		this->jour = 1;
		this->mois = 1;
		this->annee = 2000;
		return;
	}
	this->jour = j;
	this->mois = m;
	this->annee = a;
}

bool Date::estBissextile(int a)
{
	if (a % 400 == 0 || a % 4 == 0 && a % 100 != 0) {
		return true;
	}
	return false;
}

bool Date::estValide(int j, int m, int a)
{
	if (j < 1 || j>31 || m < 1 || m>12 || a < 1 || a>2026) {
		return false;
	}
	int Mois[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (estBissextile(a)) {
		Mois[1] = 29;
	}
	return j <= Mois[m - 1];
}

void Date::Consulter() const
{
	cout << "La date est:" << this->jour << "/" << this->mois << "/" << this->annee << endl;
}

bool Date::operator==(const Date& d) const
{
	if (this->annee == d.annee && this->mois == d.mois && this->jour == d.jour) {
		return true;
	}
	return false;
}

bool Date::operator<(const Date& d) const
{
	if (this->annee != d.annee) {
		return this->annee < d.annee;
	}
	if (this->mois != d.mois) {
		return this->mois < d.mois;
	}
	return this->jour < d.jour;
}
