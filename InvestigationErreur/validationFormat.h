/*
 * TP1 remise le 01/10/2022
 * GIF-1003
 * Auteur: Nicolas Gagné
 * B-IFT 111 124 001
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>

bool validerFormatNom (const std::string& p_nom);
bool validerCodeIssn (const std::string& p_issn);
bool validerCodeIsbn (const std::string& p_isbn);

#endif /* VALIDATIONFORMAT_H */

