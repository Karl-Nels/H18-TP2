#include "utilisateurRegulier.h"

//Constructeurs
UtilisateurRegulier::UtilisateurRegulier(const string& nom): estGroupe_(false),Utilisateur(nom, Regulier){
	this->ajouterInteret(TAUX_REGULIER);
}

UtilisateurRegulier::UtilisateurRegulier(const Utilisateur& utilisateur) {

//	*this = utilisateur;
	this->Utilisateur::Utilisateur(utilisateur);
	this->estGroupe_ = false;

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

	//*this = utilisateur;
	this->Utilisateur::operator=(utilisateur);
	 this->estGroupe_ = false;

	 return *this;
}

ostream& operator<< (ostream& os, const UtilisateurRegulier& utilisateur) {
	
	os << static_cast<Utilisateur>(utilisateur);
	/*if(utilisateur.estGroupe_)
		os << "Appartient deja a un groupe: " << utilisateur.estGroupe_ << endl;*/

	return os;
}
