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



bool aTrouveUtilisateur(Utilisateur* utilisateur, vector<Utilisateur*> groupe_) {

	bool estEgal = false;
	vector<Depense *> depenseTmp;

	for (unsigned i = 0; i < groupe_.size(); i++)
		if (utilisateur == groupe_[i])
			estEgal = true;

	return estEgal;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour)
{

	bool existe = false;
	existe = aTrouveUtilisateur(payePar, utilisateurs_);
	//payePour.push_back(payePar);

	if ((depense->getType() == groupe) && (existe == true)) {
		
		for (unsigned i = 0; i < payePour.size(); i++) {
			//payePour[i] = static_cast<UtilisateurPremium*>(payePour[i]);

			existe = aTrouveUtilisateur(payePour[i], utilisateurs_);

			if (existe == true) {
				//static_cast<DepenseGroupe*>(depense)->setNombreParticipants(payePour.size());
				payePour[i]->operator+=(depense);
				payePour[i]->calculerTotalDepenses();


			}
		}
		payePar->operator+=(depense);
		payePar->calculerTotalDepenses();
		depenses_.push_back(static_cast<DepenseGroupe*>(depense));
	}
	else if ((depense->getType() == individuelle) || existe == false)
		cout << "Erreur: vous tentez d'ajouter une depense individuelle "
		<< "au groupe ou alors les personnes impliquees dans la "
		<< "depense groupe ne sont pas dans le groupe" << endl << endl;

	return *this;
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
	else{

		UtilisateurRegulier * userTmp = static_cast<UtilisateurRegulier *>(utilisateur);

		if (userTmp->estGroupe() == true)
			cout << "Erreur : L'utilisateur " << userTmp->getNom()
			<< " n'est pas souscrit a un abonnement premium, et est deja groupe." << endl;
		else {
			userTmp->setEtatGroupe(true);
			utilisateurs_.push_back(userTmp);
		}
}

	return *this;
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

		for (unsigned j = 0; j < depenseTmp.size(); j++)
			if (depenseTmp[j]->getType() == Premium)
				totalDepenses_ += depenseTmp[j]->getMontant();

	}

}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	os << "L'evenement nomme : " << groupe.nom_ << " a coute un total de : " << groupe.getTotalDepenses()
		<< " voici les utilisateurs et toutes leurs depenses : " << endl;

	for (unsigned i = 0; i < groupe.utilisateurs_.size(); i++) {
		
		if(groupe.utilisateurs_[i]->getType() == Premium)
			os << *(static_cast<UtilisateurPremium*>(groupe.utilisateurs_[i])) << endl << endl;
		else
			os << *(static_cast<UtilisateurRegulier*>(groupe.utilisateurs_[i])) << endl << endl;

		}


		return os;
}
