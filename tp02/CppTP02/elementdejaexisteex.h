#ifndef __ELEMENTDEJAEXISTEEX_H__
#define __ELEMENTDEJAEXISTEEX_H__

#include <stdexcept>
#include <string>

class ElementDejaExisteEx : public std::exception {
private:
	std::string message;
	int nouvelle_quantite;
public:
	ElementDejaExisteEx(std::string le_message, int quantite) {
		this->message = le_message;
		this->nouvelle_quantite = quantite;
	}

	ElementDejaExisteEx(std::string le_message) {
		this->message = le_message;
		this->nouvelle_quantite = 1;
	}

	const char* what() const noexcept { return this->message.c_str(); }

	const int getNouvelleQuantite() const { return nouvelle_quantite; }

};

#endif
