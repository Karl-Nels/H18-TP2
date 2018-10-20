#include "utilisateurPremium.h"
#include <math.h>

//Constructeurs
UtilisateurPremium::UtilisateurPremium(const string& nom): Utilisateur::Utilisateur(nom, Premium), joursRestants_(30),taux_(0.05) {
}

UtilisateurPremium::UtilisateurPremium(const Utilisateur& utilisateur) {

	this->Utilisateur::Utilisateur(utilisateur);
	this->joursRestants_ = 30;
	this->taux_= 0.05;

}

//accesseurs
unsigned int UtilisateurPremium::getJoursRestants() const {

	return joursRestants_;
}

double UtilisateurPremium::getTaux() const {
	return taux_;
}

//modificateur
void UtilisateurPremium::setJoursRestants(unsigned int joursRestants) {

	joursRestants_ = joursRestants;
}


void UtilisateurPremium::calculerTaux() {
	unsigned int nbDepenses = getNombreDepenses();

	taux_ -=  (floor(nbDepenses / 2) / 100);
}

//Surcharge d'operateurs
UtilisateurPremium& UtilisateurPremium::operator= (Utilisateur* utilisateur) {

	if(this != utilisateur)
		this->Utilisateur::operator=(utilisateur);

	return *this;
}

ostream& operator << (ostream& os, const UtilisateurPremium& utilisateur) {
	//utilisateur.calculerTaux();
	os << static_cast<Utilisateur>(utilisateur)
	   << "(taux final de : " << utilisateur.getTaux()*100 << "%)" << endl << endl;

	return os;
}
