#include "utilisateurRegulier.h"

//Constructeurs
UtilisateurRegulier::UtilisateurRegulier(const string& nom): estGroupe_(false),Utilisateur(nom, Regulier){
	//this->ajouterInteret(TAUX_REGULIER);
}

UtilisateurRegulier::UtilisateurRegulier(const Utilisateur& utilisateur): Utilisateur(utilisateur), estGroupe_(false) {

}


//getters
bool UtilisateurRegulier::estGroupe() const {

	return estGroupe_;
}

//setters
void UtilisateurRegulier::setEtatGroupe(bool etat) {

	estGroupe_ = etat;
}

//Surcharge d'operateurs

UtilisateurRegulier& UtilisateurRegulier::operator=(Utilisateur* utilisateur) {

	if (this != utilisateur) {
		this->Utilisateur::operator=(utilisateur);
		this->estGroupe_ = false;
	}
	 return *this;
}

ostream& operator<< (ostream& os, const UtilisateurRegulier& utilisateur) {
	
	os << static_cast<Utilisateur>(utilisateur);

	return os;
}
