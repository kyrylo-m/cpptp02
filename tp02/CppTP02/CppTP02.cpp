#include <iostream>
#include <stdexcept>
#include <climits>

#include "gestionfacture.h"
#include "elementdejaexisteex.h"

void ajouterNuitees(GestionFacture& gestion);
void ajouterRepas(GestionFacture& gestion);
void ajouterAccesSpa(GestionFacture& gestion);
void ajouterAccesGym(GestionFacture& gestion);

int main()
{
	// On crée l'objet de la classe GestionFacture pour gerer les éléments et les procedures de facturation
	GestionFacture gestion;

	int choix = 0;
							// Menu principal
	do {
		std::cout << "\n===================== Bienvenue au Systeme de facturation! ===================== " << std::endl;
		std::cout << "                   Faites votre choix parmi les options suivantes: " << std::endl;
		std::cout << "=================================================================================" << std::endl;
		std::cout << "1 - Ajouter des nuitees      2 - Ajouter des repas    3 - Ajouter un acces au spa" << std::endl;
		std::cout << "4 - Ajouter un acces au gym  5 - Afficher la facture  0 - Quitter le programme" << std::endl;
		std::cout << "\nVotre choix: ";
		std::cin >> choix;

		switch (choix)
		{
		case 1:
			ajouterNuitees(gestion);
			break;
		case 2:
			ajouterRepas(gestion);
			break;
		case 3:
			ajouterAccesSpa(gestion);
			break;
		case 4:
			ajouterAccesGym(gestion);
			break;
		case 5:
			gestion.afficherFacture();
			break;
		case 0:
			gestion.libererMemoire();
			std::cout << "Bye!" << std::endl;
			break;
		default:
			std::cout << "Choix errone. Entrez une valeur entre 0 et 5:" << std::endl;
			break;
		};
	} while (choix != 0);
	
} // main

// Pour ajouter des nuitées à la facture on demande la quantite de l'utilisateur
void ajouterNuitees(GestionFacture& gestion) {
	int nombreNuits;
	bool saisie_correcte;

	do {
		saisie_correcte = true;
		std::cout << "Entrez le nombre de nuitees a ajouter: ";
		try { // On vérifie si la quantité entrée est plus grande que zéro
			std::cin >> nombreNuits;
			if (nombreNuits <= 0) {
				throw std::range_error("Saisie incorrecte. Reessayez.");
			}
		}		
		catch (const std::exception & ex) {
			if (std::cin.fail()) {  // On gère aussi d'autres erreurs possibles de saisie
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
			std::cout << ex.what() << std::endl;
			saisie_correcte = false;
		}
	} while (!saisie_correcte);

	//On ajoute les nuitée à la facture en appelant la méthode ajouterNuitee de la classe GestionFacture
	try {   
		if (gestion.ajouterNuitees(nombreNuits)) {
			std::cout << "Les nuitees ont ete ajoutees a facture avec succes:" << std::endl;
			gestion.afficherElement(1);
		}
	}
	// Si l'élément Nitée était déjà inclus dans la facture, on modifie la quantité de nuits
	catch (const ElementDejaExisteEx& ex) {
		std::cout << ex.what() << std::endl;
		gestion.afficherElement(1);
		if (ex.getNouvelleQuantite() != gestion.getQuantite(1)) {
			gestion.setQuantite(1, ex.getNouvelleQuantite());
			std::cout << "\nLa quantite de nuitees a ete mise a jour: " << std::endl;
			gestion.afficherElement(1);
		}
	}
} // ajouterNuitees 


// La procedure ajouterRepas fonctionne de la même manière que ajouterNuitee
void ajouterRepas(GestionFacture& gestion) {
	int nombreRepas;
	bool saisie_correcte;

	do {
		saisie_correcte = true;
		std::cout << "Entrez le nombre de repas a ajouter: ";
		try {
			std::cin >> nombreRepas;
			if (nombreRepas <= 0) {
				throw std::range_error("Saisie incorrecte. Reessayez.");
			}
		}
		catch (const std::exception & ex) {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
			std::cout << ex.what() << std::endl;
			saisie_correcte = false;
		}
	} while (!saisie_correcte);

	try {
		if (gestion.ajouterRepas(nombreRepas)) {
			std::cout << "Les repas ont ete ajoutes a facture avec succes:" << std::endl;
			gestion.afficherElement(2);
		}
	}		// Si l'élément Repas était déjà inclus dans la facture, on modifie la quantité
	catch (const ElementDejaExisteEx& ex) {
		std::cout << ex.what() << std::endl;
		gestion.afficherElement(2);
		if (ex.getNouvelleQuantite() != gestion.getQuantite(2)) {
			gestion.setQuantite(2, ex.getNouvelleQuantite());
			std::cout << "\nLa quantite de repas a ete mise a jour: " << std::endl;
			gestion.afficherElement(2);
		}
	}
} // ajouterRepas 


// Les procedure ajouterAccesSpa et ajouterAccesGym n'ont pas besoin de paramètre de quantité
void ajouterAccesSpa(GestionFacture& gestion) {
	try {
		if (gestion.ajouterAccesSpa()) {
			std::cout << "L'acces au spa a ete ajoute a facture avec succes:" << std::endl;
			gestion.afficherElement(3);
		}
	}     //On vérifie si l'élément ajouterAccesSpa était déjà inclus dans la facture
	catch (const ElementDejaExisteEx & ex) {
		std::cout << ex.what() << std::endl;
		gestion.afficherElement(3);		
	}
} // ajouterAccesSpa


void ajouterAccesGym(GestionFacture& gestion) {
	try {
		if (gestion.ajouterAccesGym()) {
			std::cout << "L'acces au gym a ete ajoute a facture avec succes:" << std::endl;
			gestion.afficherElement(4);
		}
	}
	catch (const ElementDejaExisteEx & ex) {
		std::cout << ex.what() << std::endl;
		gestion.afficherElement(4);
	}
} // ajouterAccesGym

