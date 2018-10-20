/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa 
*******************************************/

#include "utilisateur.h"

// Constructeurs

Utilisateur::Utilisateur(const string& nom, TypeUtilisateur type): nom_(nom),interet_(0.0)
,totalDepense_(0.0),type_(type){

	depenses_.clear();
}

Utilisateur::Utilisateur(const Utilisateur& utilisateur) {

	interet_ = utilisateur.interet_;
	nom_ = utilisateur.nom_;
	type_ = utilisateur.type_;
	depenses_ = utilisateur.depenses_;
	totalDepense_ = utilisateur.totalDepense_;
}


//Destructeur

Utilisateur::~Utilisateur(){
	

}

// Methodes d'acces

string Utilisateur::getNom() const {
	return nom_;
}

double Utilisateur::getTotalDepenses() const {
	return totalDepense_;
}

TypeUtilisateur Utilisateur::getType() const {
	return type_; 
}

double Utilisateur::getInteret() const {
	return interet_; 
}

unsigned int Utilisateur::getNombreDepenses() const {
	
	return depenses_.size();
}

vector <Depense*> Utilisateur::getDepenses() const {
	return depenses_; 
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

void Utilisateur::calculerTotalDepenses() {
	totalDepense_ = 0;
	for (unsigned i = 0; i < depenses_.size(); i++) {

		if (depenses_[i]->getType() == individuelle)
			totalDepense_ += depenses_[i]->getMontant();
		else
			totalDepense_ += static_cast<DepenseGroupe*>(depenses_[i])->getMontantPersonnel();
	}
}

Utilisateur& Utilisateur::operator=(Utilisateur * utilisateur)
{
	if (this != utilisateur) {
		
		interet_ = utilisateur->interet_;
		nom_ = utilisateur->nom_;
		type_ = utilisateur->type_;
		depenses_ = utilisateur->depenses_;
		totalDepense_ = utilisateur->totalDepense_;
	}

	return *this;
}


void Utilisateur::ajouterInteret(double montant) {
	interet_ += montant;
}

Utilisateur& Utilisateur::operator+=(Depense* depense) {

	depenses_.push_back(depense);
	

	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)

{
	string typeUtilisateur[] = { "Regulier","Premium" };

	os << "\t Utilisateur " << utilisateur.nom_ << " (" << typeUtilisateur[utilisateur.type_]
		<< ") a developpe pour un total de : " << utilisateur.getTotalDepenses()
		<< ", PolyCount prend en interet : " << utilisateur.interet_
		<< " , voici les depenses: " << endl;
	
	for (unsigned i = 0; i < utilisateur.depenses_.size(); i++)
		if (utilisateur.depenses_[i]->getType() == individuelle)
			os << *(static_cast<DepenseIndividuelle*>(utilisateur.depenses_[i]));
		else
			os << *(static_cast<DepenseGroupe*>(utilisateur.depenses_[i]));

	os << endl;


	return os;
}
