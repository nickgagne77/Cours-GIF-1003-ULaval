/**
 * \file gestionReference.cpp
 * \brief Fichier intéractif avec l'usager pour la classe Reference
 * \author Nicolas Gagné
 * \version 0.1
 * \date 2022-10-22
 *
 * Programme intéractif minimaliste d'interaction avec l'usager pour
 * l'obtention de données nécessaires pour créer un objet Reference
 */

#include <iostream>
#include <string>
#include "Reference.h"
#include "validationFormat.h"

using namespace std;
using namespace util;
using namespace biblio;


/*
 * \brief Fonction qui demande l'auteur à l'utilisateur
 * \return un objet string qui est le nom de l'auteur
 */
string
demanderAuteur ()
{
  bool auteurValide = false;
  string entreeAuteur;

  do
    {
      cout << "Veuillez entrer l'auteur de la référence: " << endl;
      char buffer[256];
      cin.getline (buffer, 256);
      entreeAuteur = buffer;
      if (validerFormatNom (entreeAuteur))
        {
          auteurValide = true;
        }
    }
  while (!auteurValide);

  return entreeAuteur;
}


/*
 * \brief Fonction qui demande le titre à l'utilisateur
 * \return un objet string qui est le titre
 */
string
demanderTitre ()
{
  bool titreValide = false;
  string entreeTitre;

  do
    {
      cout << "Veuillez entrer le titre de la référence: " << endl;
      char buffer[256];
      cin.getline (buffer, 256);
      entreeTitre = buffer;
      if (!entreeTitre.empty ())
        {
          titreValide = true;
        }
    }
  while (!titreValide);

  return entreeTitre;
}


/*
 * \brief Fonction qui demande l'année à l'utilisateur
 * \return un objet int qui est l'année
 */
int
demanderAnnee ()
{
  bool anneeValide = false;
  int entreeAnnee;

  do
    {
      cout << "Veuillez entrez l'année d'édition de la référence: " << endl;
      cin >> entreeAnnee;
      cin.ignore (256, '\n');
      if ( entreeAnnee > 0)
        {
          anneeValide = true;
        }
    }
  while (!anneeValide);

  return (int) entreeAnnee;
}


/*
 * \brief Fonction qui demande l'identifiant à l'utilisateur
 * \return un objet string qui est l'identifiant
 */
string
demanderIdentifiant ()
{
  bool identifiantValide = false;
  string entreeIdentifiant;

  do
    {
      cout << "Veuillez entrez l'identiant de la référence: " << endl;
      char buffer[256];
      cin.getline (buffer, 256);
      entreeIdentifiant = buffer;
      if (entreeIdentifiant.substr (0, 4) == "ISBN")
        {
          if (validerCodeIsbn (entreeIdentifiant))
            {
              identifiantValide = true;
            }
        }
      else if (entreeIdentifiant.substr (0, 4) == "ISSN")
        {
          if (validerCodeIssn (entreeIdentifiant))
            {
              identifiantValide = true;
            }
        }
    }
  while (!identifiantValide);

  return entreeIdentifiant;
}


/**
 * \brief Fonction qui retourne un objet Reference en demandant les entrees
 * à l'utilisateur
 * \return un objet Reference
 */
Reference
creerReference ()
{
  string auteur = demanderAuteur ();
  string titre = demanderTitre ();
  int annee = demanderAnnee ();
  string identifiant = demanderIdentifiant ();
  Reference referenceEntree (auteur, titre, annee, identifiant);
  return referenceEntree;
}


/**
 * \brief Programme principal
 */
int
main (void)
{
  cout << "Commençons par ajouter une référence de votre choix." << endl;
  Reference reference1 = creerReference ();

  cout << endl;
  char reponse1;
  cout << "Désirez-vous afficher la référence entrée de façon formatée?(O/N)" << endl;
  cin >> reponse1;
  cin.ignore (256, '\n');
  if (toupper (reponse1) == 'O')
    {
      cout << "Voici la référence formatée: " << endl;
      cout << reference1.reqReferenceFormate () << endl;
    }

  bool continuer = true;
  do
    {
      cout << endl;
      char reponse;
      cout << "Désirez-vous modifier l'année de la référence?(O/N)" << endl;
      cin >> reponse;
      cin.ignore (256, '\n');
      if (toupper (reponse) == 'O')
        {
          int nouvelleAnnee = demanderAnnee ();
          reference1.asgAnnee (nouvelleAnnee);
          cout << "Voici la référence formatée avec la modification apportée: " << endl;
          cout << reference1.reqReferenceFormate () << endl;
        }
      else if (toupper (reponse) == 'N')
        {
          continuer = false;
        }
    }
  while (continuer);

  cout << endl;
  cout << "Voici les éléments que vous pouvez afficher: " << endl;
  cout << "A. Auteur" << endl;
  cout << "B. Titre" << endl;
  cout << "C. Année" << endl;
  cout << "D. Identifiant" << endl;


  bool arret = false;
  bool entreeValide = false;
  do
    {
      cout << endl;
      char reponse;
      cout << "Quel est votre choix?(Q pour quitter)" << endl;
      cin >> reponse;
      cin.ignore (256, '\n');

      if (toupper (reponse) == 'A')
        {
          cout << reference1.reqAuteurs () << endl;
          entreeValide = true;
        }
      else if (toupper (reponse) == 'B')
        {
          cout << reference1.reqTitre () << endl;
          entreeValide = true;
        }
      else if (toupper (reponse) == 'C')
        {
          cout << reference1.reqAnnee () << endl;
          entreeValide = true;
        }
      else if (toupper (reponse) == 'D')
        {
          cout << reference1.reqIdentifiant () << endl;
          entreeValide = true;
        }
      else if (toupper (reponse) == 'Q')
        {
          arret = true;
        }
    }
  while (!arret);

  cout << endl;
  char reponse2;
  cout << "Désirez-vous ajouter un objet référence pour faire une comparaison?(O/N)" << endl;
  cin >> reponse2;
  cin.ignore (256, '\n');
  if (toupper (reponse2) == 'O')
    {
      Reference reference2 = creerReference ();
      cout << endl;
      cout << "Voici la deuxième référence formatée: " << endl;
      cout << reference2.reqReferenceFormate () << endl;
      cout << endl;
      if (reference1 == reference2)
        {
          cout << "Les deux références entrées sont identiques!" << endl;
        }
      else
        {
          cout << "Les deux références entrées sont différentes." << endl;
        }
    }

  cout << endl;
  cout << "Fin du programme! :)";

  return 0;
}

