#include "depenseIndividuelle.h"

DepenseIndividuelle::DepenseIndividuelle(const string & nom, double montant, const string& lieu) : Depense(nom, montant, lieu, individuelle)
{}





ostream& operator<< (ostream& os, const DepenseIndividuelle& depense) {
	os << "\t\t Depense individuelle : "
	   << static_cast<Depense> (depense);
	os << endl;
	return os; 
 }