#ifndef __FACTURABLEFRAISFIXE_H__
#define __FACTURABLEFRAISFIXE_H__

#include <iostream>
#include <string>
#include "elementfacturable.h"

class FacturableFraisFixe : public ElementFacturable {
protected:
	double taxe_de_vente;
	double taxe_additionnelle;
	int quantite = 1;
	int prix_fixe;
	std::string nom;

public:
	FacturableFraisFixe(std::string nom, int prix) {
		taxe_de_vente = 0.08;
		taxe_additionnelle = 0.07;
		this->nom = nom;
		this->prix_fixe = prix;

	}

	void calculerMontant() { montant = (double)prix_fixe * (1 + taxe_de_vente + taxe_additionnelle); }
	
	double getMontant() { return montant; }
	
	int getPrix() { return prix_fixe; }
	
	std::string getNom() { return nom; }

	// Pour les elements facturables par frais fixe la quantite n'est pas pertinente comme un attribut,
	// mais on doit le declarer, aussi que definir le getter et le setter, pour que la classe ne soit pas abstraite.
	int getQuantite() { return 1; }
	void setQuantite(int quantite) { this->quantite = 1; }

};

#endif
