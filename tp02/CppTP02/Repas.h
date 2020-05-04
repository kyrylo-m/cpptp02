#ifndef __REPAS_H__
#define __REPAS_H__

#include "facturableparunite.h"

class Repas : public FacturableParUnite {
private:
	std::string nom_element;
	
public:
	Repas(int quantite) : FacturableParUnite(quantite) {
		prix_unitaire = 20;
		nom_element = "Repas";
	}

	std::string getNom() { return nom_element; }
		
};

#endif