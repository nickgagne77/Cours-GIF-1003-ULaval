/*
 * TP1 remise le 01/10/2022
 * GIF-1003
 * Auteur: Nicolas Gagné
 * B-IFT 111 124 001
 */

#include "validationFormat.h"
#include <string>
using namespace std;


bool
validerFormatNom (const string& p_nom)
{
  if (!isalpha (p_nom[0]))
    {
      return false;
    }

  for (int i = 1; i < p_nom.length (); i++)
    {
      if (!isalpha (p_nom[i]))
        {
          if (p_nom[i] == '-' || p_nom[i] == ' ')
            {
              if (i == p_nom.length () - 1 || p_nom[i + 1] == '-' || p_nom[i + 1] == ' ')
                {
                  return false;
                }
            }
          else
            {
              return false;
            }
        }
    }
  return true;
}


bool
validerCodeIssn (const string& p_issn)
{
  int total = 0;
  int ponderation = 8;
  istringstream chaine (p_issn);

  string type_code;
  chaine >> type_code;

  string code_issn;
  chaine >> code_issn;
  int longueur_issn = code_issn.length ();

  if (type_code != "ISSN" || longueur_issn != 9 || code_issn[4] != '-')
    {
      return false;
    }

  for (int i = 0; i < longueur_issn; i++)
    {
      if (i == 4)
        {
          continue;
        }
      else
        {
          if (!isdigit (code_issn[i]))
            {
              return false;
            }
          else
            {
              if (i != longueur_issn - 1)
                {
                  char t = code_issn[i];
                  int n = t - '0';
                  total += n * ponderation;
                  ponderation--;
                }
            }
        }
    }

  char tmp_cle = code_issn[longueur_issn - 1];
  if (isdigit (tmp_cle))
    {
      int cle = tmp_cle - '0';
      int verif_cle = 11 - total % 11;
      if (verif_cle == 11)
        {
          return cle == 0;
        }
      else
        {
          return cle == verif_cle;
        }
    }
  else
    {
      return tmp_cle == 'X';
    }
}


bool
validerCodeIsbn (const string& p_isbn)
{
  int total = 0;
  int ponderation;
  string pays_livre;
  string domaine;
  string num_editeur;
  string num_publication;
  int nb_tirets = 0;

  string type_code = p_isbn.substr (0, 4);
  string code_isbn = p_isbn.substr (5);
  string copie_code_isbn = code_isbn;
  int longueur_isbn = code_isbn.length ();

  int cle = code_isbn[longueur_isbn - 1] - '0';
  int verif_cle;

  for (int i = 0; i < longueur_isbn; i++)
    {
      if (code_isbn[i] == '-')
        {
          nb_tirets++;
        }
    }

  size_t position = code_isbn.find ('-');
  int y = 1;
  while (y <= 4)
    {
      if (y == 1)
        {
          pays_livre = copie_code_isbn.substr (0, position);
          copie_code_isbn.erase (0, position + 1);
          y++;
        }
      else if (y == 2)
        {
          domaine = copie_code_isbn.substr (0, position);
          copie_code_isbn.erase (0, position + 1);
          y++;
        }
      else if (y == 3)
        {
          num_editeur = copie_code_isbn.substr (0, position);
          copie_code_isbn.erase (0, position + 1);
          y++;
        }
      else if ( y == 4)

        {
          num_publication = copie_code_isbn.substr (0, position);
          copie_code_isbn.erase (0, position + 1);
          y++;
        }
      position = copie_code_isbn.find ('-');
    }

  string code_isbn_chiffres = pays_livre + domaine + num_editeur + num_publication;

  for (int i = 0; i < code_isbn_chiffres.length (); i++)
    {
      if (!isdigit (code_isbn_chiffres[i]))
        {
          return false;
        }
    }

  int domaine_entier = atoi (domaine.c_str ());
  int num_editeur_entier = atoi (num_editeur.c_str ());

  if (
      !(type_code == "ISBN"  && (pays_livre == "978" || pays_livre == "979")
        && longueur_isbn == 17  && nb_tirets == 4
        && (domaine_entier == 7
            || (0 <= domaine_entier && domaine_entier <= 19)
            || (80 <= domaine_entier && domaine_entier <= 94)
            || (950 <= domaine_entier && domaine_entier <= 989)
            || (9900 <= domaine_entier && domaine_entier <= 9989)
            || (99900 <= domaine_entier && domaine_entier <= 99999))
        && ((0 <= num_editeur_entier && num_editeur_entier <= 19)
            || (200 <= num_editeur_entier && num_editeur_entier <= 699)
            || (7000 <= num_editeur_entier && num_editeur_entier <= 8499)
            || (85000 <= num_editeur_entier && num_editeur_entier <= 89999)
            || (900000 <= num_editeur_entier && num_editeur_entier <= 949999)
            || (9500000 <= num_editeur_entier && num_editeur_entier <= 9999999)))
      )
    {
      return false;
    }

  for (int i = 0; i < code_isbn_chiffres.length (); i++)
    {
      int n = code_isbn_chiffres[i] - '0';
      if ((i + 1) % 2 == 0)
        {
          ponderation = 3;
        }
      else
        {
          ponderation = 1;
        }
      total += n * ponderation;
    }

  if (total % 10 == 0)
    {
      return cle == '0';
    }
  else
    {
      verif_cle = 10 - total % 10;
      return cle == verif_cle;
    }
}
