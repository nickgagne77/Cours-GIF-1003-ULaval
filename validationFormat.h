/**
 * \file validationFormat.h
 * \brief Fichier d'entête de fonctions de validations de formats string
 * \author Nicolas Gagné
 * \version 0.1
 * \date 2022-10-22
 *
 * Fichier d'entête des fonctions de validation de nom d'auteur et codes identifiants
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>

namespace util
{
  bool validerFormatNom (const std::string& p_nom);
  bool validerCodeIssn (const std::string& p_issn);
  bool validerCodeIsbn (const std::string& p_isbn);
} // namespace util
#endif /* VALIDATIONFORMAT_H */

