#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
	int jour;
	int mois;
	int annee;

public:
    Date(int j = 1, int m = 1, int a = 2000);

    static bool estBissextile(int);
    static bool estValide(int, int, int);

    void Consulter() const;

    bool operator==(const Date&) const;
    bool operator<(const Date&) const;
};

