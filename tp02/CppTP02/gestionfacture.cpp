#include "gestionfacture.h"
#include "elementdejaexisteex.h"
#include <utility>

bool GestionFacture::ajouterNuitees(int quantite)
{ 
	const int ordre = 1;
	// On verifie si un objet Nuitee existe deja dans le conteneur
	if (facturables.count(ordre) > 0) {
		throw ElementDejaExisteEx("\nL'element Nuitee etait deja inclus dans la facture:", quantite);
	}
	// On forme la paire et on l'insère au conteneur
	std::pair<int, ElementFacturable*> paire_ajouter (ordre, new Nuitee(quantite));
	facturables.insert(paire_ajouter);

	// On verifie si notre objet Nuitee a été inséré avec succès:
	if (facturables.count(ordre) > 0)
		return true;
	return false;

} // ajouterNuitee


bool GestionFacture::ajouterRepas(int quantite)
{
	const int ordre = 2;
	// On verifie si un objet Repas existe deja dans le conteneur
	if (facturables.count(ordre) > 0) {
		throw ElementDejaExisteEx("\nL'element Repas etait deja inclus dans la facture:", quantite);
	}		

	std::pair<int, ElementFacturable*> paire_ajouter(ordre, new Repas(quantite));
	facturables.insert(paire_ajouter);

	// On verifie si notre objet Repas a été inséré avec succès:
	if (facturables.count(ordre) > 0)
		return true;
	return false;

} // ajouterRepas


bool GestionFacture::ajouterAccesSpa()
{
	const int ordre = 3;
	// On verifie si un element Acces au Spa existe deja dans le containeur
	if (facturables.count(ordre) > 0) {
		throw ElementDejaExisteEx("\nL'element Acces au spa etait deja inclus dans la facture:");
	}

	std::pair<int, ElementFacturable*> paire_ajouter(ordre, new FacturableFraisFixe("Acces au spa", 75));
	facturables.insert(paire_ajouter);

	// On verifie si notre objet AccesSpas a été inséré avec succès:
	if (facturables.count(ordre) > 0)
		return true;
	return false;

} // ajouterAccesSpa


bool GestionFacture::ajouterAccesGym()
{
	const int ordre = 4;
	// On verifie si un element Acces au Gym existe deja dans le containeur
	if (facturables.count(ordre) > 0) {
		throw ElementDejaExisteEx("\nL'element Acces au gym etait deja inclus dans la facture:");
	}

	std::pair<int, ElementFacturable*> paire_ajouter(ordre, new FacturableFraisFixe("Acces au gym", 50));
	facturables.insert(paire_ajouter);

	// On verifie si notre objet AccesSpas a été inséré avec succès:
	if (facturables.count(ordre) > 0)
		return true;
	return false;

} // ajouterAccesGym


void GestionFacture::afficherFacture()
{	
	double total_a_payer = 0;
	std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "              Facture de services hoteliers" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	for (int i = 1; i <= 4; i++) {
		if (facturables.count(i) > 0) {
			afficherElement(i);
			total_a_payer += facturables[i]->getMontant();
		} // if
	} // for
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
	std::cout << "Le montant total a payer: " << total_a_payer << " $, taxes incluses." << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;

 } // afficherFacture


void GestionFacture::afficherElement(int index) {
	if (facturables.count(index) > 0) {
		facturables[index]->calculerMontant();
		std::cout << facturables[index]->getNom() << ", prix: " << facturables[index]->getPrix() << " $";
		if (index == 1 || index == 2)
			std::cout << ", quantite: " << facturables[index]->getQuantite();
		std::cout << ", sous-total: " << facturables[index]->getMontant() << " $, taxes incluses;" << std::endl;
	}
} // afficherElement

int GestionFacture::getQuantite(int index) {
	if (facturables.count(index) > 0)
		return facturables[index]->getQuantite();
	return 0;
}

void GestionFacture::setQuantite(int index, int nouvelle_quantite) {
	if (facturables.count(index) > 0)
		facturables[index]->setQuantite(nouvelle_quantite);
}


void GestionFacture::libererMemoire() {
	std::map<int, ElementFacturable*>::iterator it;
	for (it = facturables.begin(); it != facturables.end(); it++) {
		delete it->second;
		it->second = NULL;
	}
}// libererMemoire