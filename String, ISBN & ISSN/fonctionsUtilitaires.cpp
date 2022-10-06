/*
 * fonctionsUtilitaires.cpp
 *
 *  Created on: 2021-08-18
 *      Author: th. eude
 * CCorrections apportées par Nicolas Gagné pour TP1
 */
#include <math.h>
#include <iostream>
#include "fonctionsUtilitaires.h"

using namespace std;


void
saisieNotes (array<array<int, MAX_EXAMENS>, MAX_ETUDIANTS>& p_tabNotes, int* p_nbEleves)
{
  for (int i = 0; i < *p_nbEleves; i++)
    {
      for (int j = 0; j < MAX_EXAMENS; j++)
        {
          cout << "Saisissez la note de l'examen " << j + 1 << endl;
          cin >> p_tabNotes[i][j];
        }
    }
}


int
minimum (array<array<int, MAX_EXAMENS>, MAX_ETUDIANTS >& p_tabNotes, int* p_nbEleves)
{
  int noteFaible = 100;
  for (int i = 0; i < *p_nbEleves; i++)
    {
      for (int j = 0; j < MAX_EXAMENS; j++)
        {
          if (p_tabNotes[i][j] < noteFaible)
            {
              noteFaible = p_tabNotes[i][j];
            }
        }
    }
  return noteFaible;
}


int
maximum (array<array<int, MAX_EXAMENS>, MAX_ETUDIANTS >& p_tabNotes, int* p_nbEleves)
{
  int noteelevee = 0;
  for (int i = 0; i < *p_nbEleves; i++)
    {
      for (int j = 0; j < MAX_EXAMENS; j++)
        {
          if (p_tabNotes[i][j] > noteelevee)
            {
              noteelevee = p_tabNotes[i][j];
            }
        }
    }
  return noteelevee;

}


double
ecartType (array<array<int, MAX_EXAMENS>, MAX_ETUDIANTS >& p_tabNotes, int* p_nbEleves)
{
  int nb_observations = 0;
  float somme = 0;
  float sommeCarree = 0;

  // Première boucle pour calculer la somme totale des observations
  for (int i = 0; i < *p_nbEleves; i++)
    {
      for (int j = 0; j < MAX_EXAMENS; j++)
        {
          somme += p_tabNotes[i][j];
          nb_observations ++;
        }
    }
  float moyenne;
  moyenne = somme / nb_observations;

  // Deuxième boucle pour calculer la somme des écarts au carré
  for (int i = 0; i < *p_nbEleves; i++)
    {
      for (int j = 0; j < MAX_EXAMENS; j++)
        {
          sommeCarree += pow ((p_tabNotes[i][j] - moyenne), 2);
        }
    }
  double variance;
  variance = sommeCarree / (nb_observations - 1);
  double ecartType;
  ecartType = sqrt (variance);
  return ecartType;
}


void
afficherTableau (std::array<std::array<int, MAX_EXAMENS>, MAX_ETUDIANTS >& p_tabNotes, int* p_nbEleves)
{
  for (int i = 0; i < *p_nbEleves; i++)
    {
      cout << "Notes de l'étudiant " << i + 1 << "" << endl;
      for (int j = 0; j < MAX_EXAMENS; j++)
        {
          cout << "Examen " << j + 1 << " : " << p_tabNotes[i][j] << endl;
        }
    }
}
