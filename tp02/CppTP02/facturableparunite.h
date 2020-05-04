#ifndef __FACTURABLEPARUNITE_H__
#define __FACTURABLEPARUNITE_H__

#include "elementfacturable.h"

class FacturableParUnite : public ElementFacturable {
protected:
	double taxe_de_vente;
	double taxe_hebergement;
	int quantite;
	int prix_unitaire;

public:
	FacturableParUnite(int quantite) {
		taxe_de_vente = 0.08;
		taxe_hebergement = 0.05;
		this->quantite = quantite;
		this->prix_unitaire = 0;
	}

	void calculerMontant() { montant = ((double)prix_unitaire * quantite) * (1 + taxe_de_vente + taxe_hebergement); }

	int getQuantite() { return quantite; }

	void setQuantite(int quantite) { this->quantite = quantite; }

	double getMontant() { return montant; }

	int getPrix() { return prix_unitaire; }
		
};

#endif
