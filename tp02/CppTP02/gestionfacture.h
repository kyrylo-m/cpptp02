#ifndef __GESTIONFACTURE_H__
#define __GESTIONFACTURE_H__

#include <iostream>
#include <string>
#include <map>

#include "facturablefraisfixe.h"
#include "Nuitee.h"
#include "Repas.h"
#include "elementdejaexisteex.h"

class GestionFacture {
private:
	std::map<int, ElementFacturable*> facturables;

public:
	GestionFacture() {}

	bool ajouterNuitees(int quantite);
	bool ajouterRepas(int quantite);
	bool ajouterAccesSpa();
	bool ajouterAccesGym(); 
	void afficherFacture();
	void libererMemoire();
	void afficherElement(int index);
	int getQuantite(int index);
	void setQuantite(int index, int nouvelle_quantite);
};

#endif