#include "depenseGroupe.h"

//constructeurs

DepenseGroupe::DepenseGroupe(const string& nom, double montant,
	const string& lieu): Depense::Depense(nom,montant,lieu,groupe),nombreParticipants_(0)
{
	
}
DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense): Depense(depense),nombreParticipants_(0) {}

// accesseurs
unsigned int DepenseGroupe::getNombreParticipants() const {
	return nombreParticipants_;
}

double DepenseGroupe::getMontantPersonnel() const {
	if (nombreParticipants_ == 0)
		return 0.0;
	else
		return getMontant() / getNombreParticipants();
		
}


//modificateurs

void DepenseGroupe::setNombreParticipants(unsigned int nombre) {
	nombreParticipants_ = nombre;
}


//Surcharge de l'operateur << pour affichage

ostream& operator<<(ostream& os, const DepenseGroupe& depense) {

	os << "\t\t Depense de groupe : "
	   << "\t" << static_cast<Depense>(depense)
	   << " fait par: " << depense.getNombreParticipants() << " soit: "
	   << depense.getMontantPersonnel() << " par personne." << endl;

	return os;
}
