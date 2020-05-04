#ifndef __ELEMENTFACTURABLE_H__
#define __ELEMENTFACTURABLE_H__

class ElementFacturable {
protected:
	double montant;
	
public:
	ElementFacturable() { montant = 0; }

	virtual void calculerMontant() = 0;
	virtual int getQuantite() = 0;
	virtual void setQuantite(int quantite) = 0;
	virtual double getMontant() = 0;
	virtual std::string getNom() = 0;
	virtual int getPrix() = 0;
};

#endif
