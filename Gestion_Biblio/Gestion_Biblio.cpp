// Gestion_Biblio.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h"
#include "Livre.h"
#include "Bibliotheque.h"
using namespace std;

int main()
{
    Date d1(12, 5, 2020);
    Date d2(30, 2, 2022);
    Date d3(15, 8, 2023);

    Livre L1("Le Petit Prince", "Antoine de Saint-Exupery", d1);
    Livre L2("Les Miserables", "Victor Hugo", d3);
    Livre L3("L'Etranger", "Albert Camus", d1);

    Bibliotheque B("Bibliotheque FSTM", 2);

    B.ajouterLivre(L1);
    B += L2;

    B.ajouterLivre(L3);

    Livre* p = B.rechercher("Le Petit Prince");

    if (p != nullptr)
    {
        p->ajouterNote(18);
        p->ajouterNote(16);
        p->ajouterNote(20);
    }

    p = B.rechercher("Les Miserables");

    if (p != nullptr)
    {
        p->ajouterNote(15);
        p->ajouterNote(17);
    }

    cout << "----- Recherche par titre -----" << endl;

    p = B.rechercher("Le Petit Prince");

    if (p != nullptr)
    {
        cout << "Livre trouve!" << endl;
        p->afficher();
    }
    else
    {
        cout << "Livre introuvable!" << endl;
    }

    cout << "----- Recherche par ID -----" << endl;

    p = B.rechercher("Les Miserables");

    if (p != nullptr)
    {
        int idRecherche = p->getId();

        Livre* resultat = B.rechercher(idRecherche);

        if (resultat != nullptr)
        {
            cout << "Livre trouve par ID!" << endl;
            resultat->afficher();
        }
    }

    cout << "----- Recherche d'un livre inexistant -----" << endl;

    p = B.rechercher("Harry Potter");

    if (p == nullptr)
    {
        cout << "Livre introuvable!" << endl;
    }

    B.afficher();

    cout << "----- Compteurs -----" << endl;

    cout << "Nombre total de livres crees : "
        << Livre::getNbInstances() << endl;

    cout << "Nombre de bibliotheques existantes : "
        << Bibliotheque::getNbBibliotheques() << endl;

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
