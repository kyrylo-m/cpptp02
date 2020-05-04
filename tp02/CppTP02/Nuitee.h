#ifndef __NUITEE_H__
#define __NUITEE_H__

#include "facturableparunite.h"

class Nuitee : public FacturableParUnite {
private:
	std::string nom_element;

public:
	Nuitee(int quantite) : FacturableParUnite(quantite) {
		prix_unitaire = 100;
		nom_element = "Nuitee";

	}

	std::string getNom() { return nom_element; }
		
};

#endif
