/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "groupe.h"

// Constructeurs

Groupe::Groupe() {
	nom_ = ""; 
}
Groupe::Groupe(const string& nom) : nom_(nom) {
}

Groupe::~Groupe() {
	for (unsigned int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}
}


// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

vector<DepenseGroupe*> Groupe::getDepenses() const
{
	return depenses_;
}

vector<Utilisateur*> Groupe::getUtilisateurs() const
{
	return utilisateurs_;
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}


double Groupe::getTotalDepenses() const {

	return totalDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour)
{
	vector<Depense*> depenseTmp;
	
	if (depense->getType() == groupe) {
		for (unsigned i = 0; i < payePour.size(); i++) {		
			depenseTmp = payePour[i]->getDepenses();


			}
		}
	
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	if (utilisateur->getType() == Premium) {
		UtilisateurPremium * userTmp = static_cast<UtilisateurPremium *>(utilisateur);

		if (userTmp->getJoursRestants() == 0)
			cout << "Erreur : l'utilisateur " << utilisateur->getNom()
			<< " doit renouveller son abonnement premium" << endl;
		else
			utilisateurs_.push_back(userTmp);

	}
	else
		utilisateurs_.push_back(utilisateur);
}

void Groupe::equilibrerComptes() {
	
	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
	
		}
		else if (-min > max  && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
			
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (unsigned(count) >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}
	
}

void Groupe::calculerTotalDepense() {

	vector<Depense*> depenseTmp;

	for (unsigned i = 0; i < utilisateurs_.size(); i++) {
		utilisateurs_[i]->calculerTotalDepenses();

		depenseTmp = utilisateurs_[i]->getDepenses();

		for (unsigned j = 0; j < depenseTmp.size(); j++) {

			if (depenseTmp[j]->getType() == Premium) {

				totalDepenses_ += depenseTmp[j]->getMontant();
			}
		}

	}

}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	
}
