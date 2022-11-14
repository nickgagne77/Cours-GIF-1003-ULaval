/**
 * \file Reference.h
 * \brief Fichier d'implémentation de la classe Reference
 * \author Nicolas Gagné
 * \version 0.1
 * \date 2022-10-22
 *
 * Programme d'implémentation de la classe Reference
 */
#include "Reference.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
namespace biblio
{


  /**
   * \brief Constructeur avec parametres d'un objet de type Reference
   * \param[in] p_auteurs Le nom de l'auteurs (ou du premier s'ils sont plusieurs)
   * \param[in] p_titre Le titre
   * \param[in] p_annee L'annee d'edition de la référence
   * \param[in] p_identifiant Code ISSN ou ISBN de la référence
   * \return Un objet Reference
   */
  Reference::Reference (const std::string& p_auteurs, const std::string& p_titre, int p_annee,
                        const std::string& p_identifiant)
  : m_auteurs (p_auteurs), m_titre (p_titre), m_annee (p_annee), m_identifiant (p_identifiant) { }


  /**
   * \brief Accesseur pour auteurs
   * \return m_auteurs L'auteur de l'objet Reference
   */
  const std::string&
  Reference::reqAuteurs () const
  {
    return m_auteurs;
  }


  /**
   * \brief Accesseur pour titre
   * \return m_titre Le titre de l'objet Reference
   */
  const std::string&
  Reference::reqTitre () const
  {
    return m_titre;
  }


  /**
   * \brief Accesseur pour annee
   * \return m_annee L'annee de l'objet Reference
   */
  int
  Reference::reqAnnee () const
  {
    return m_annee;
  }


  /**
   * \brief Accesseur pour annee
   * \return m_annee L'annee de l'objet Reference
   */
  const std::string&
  Reference::reqIdentifiant () const
  {
    return m_identifiant;
  }


  /**
   * \brief Mutateur pour annee, modifie l'annee d'édition de la référence
   * \param[in] p_annee nouvellee annee
   */
  void
  Reference::asgAnnee (int p_annee)
  {
    if (p_annee > 0)
      {
        m_annee = p_annee;
      }
    else
      {
        cout << "Entrée invalide, l'année demeure inchangée." << endl;
      }
  }


  /**
   * \brief Retourne une chaine de caractere qui contient l'information de l'objet Reference
   * \return un string qui contient l'information formatee
   */
  std::string
  Reference::reqReferenceFormate () const
  {
    ostringstream os;
    os << reqAuteurs () << ", ";
    os << reqTitre () << ", ";
    os << reqAnnee () << ", ";
    os << reqIdentifiant () << ".";
    return os.str ();
  }


  /**
   * \brief surcharge de l'opérateur ==
   * \param[in] p_reference à comparer à la référence courante
   * \return un booléen indiquant si les deux références sont égales ou non
   */
  bool Reference::operator== (const Reference& p_reference) const
  {
    return (m_auteurs == p_reference.m_auteurs
            && m_titre == p_reference.m_titre
            && m_annee == p_reference.m_annee
            && m_identifiant == p_reference.m_identifiant);
  }

} // namespace biblio
