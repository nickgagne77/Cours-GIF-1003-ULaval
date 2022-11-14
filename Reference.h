/**
 * \file Reference.h
 * \brief Fichier d'interface de la classe Reference
 * \author Nicolas Gagné
 * \version 0.1
 * \date 2022-10-08
 *
 * Programme d'interface de la classe Reference
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>

namespace biblio
{

  /**
   * \class Reference
   * \brief Classe Reference permettant de modéliser des objets de
   *        références bibliographiques.
   */

  class Reference
  {
  public:
    Reference (const std::string& p_auteurs, const std::string& p_titre, int p_annee,
               const std::string& p_identifiant);
    const std::string& reqAuteurs () const;
    const std::string& reqTitre () const;
    int reqAnnee () const;
    const std::string& reqIdentifiant () const;
    void asgAnnee (int p_annee);
    std::string reqReferenceFormate () const;
    bool operator== (const Reference& p_reference) const;

  private:
    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;
  };

} // namespace bilio


#endif /* REFERENCE_H */

