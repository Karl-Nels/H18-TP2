/********************************************
* Titre: Travail pratique #3 - main.cpp
* Date: 16 septembre 2018
* Auteur: David Dratwa
*******************************************/

#include <iostream>
#include "depense.h"
#include "utilisateur.h"
#include "transfert.h"
#include "groupe.h"

using namespace std;

int main() {

	DepenseGroupe* depense1 = new DepenseGroupe("cafe", 3.5, "Montreal");
	DepenseGroupe depense2(*depense1);
	DepenseGroupe depense3;
	depense3 = *depense1;

	depense1->setNombreParticipants(45);
	depense2.setNombreParticipants(12);
	depense3.setNombreParticipants(29);


	cout << *depense1 << endl;
	cout << depense2 << endl;
	cout << depense3 << endl;

	Utilisateur user1("Carl");	
	Utilisateur user2(user1);
	Utilisateur user3;
	user3 = user1;

	user2.ajouterInteret(5);
	user3.ajouterInteret(7);
	user1 += depense1;
	cout << user1;
	UtilisateurRegulier* albert = new UtilisateurRegulier("albert");

	UtilisateurRegulier * Paul = new UtilisateurRegulier(user1);

	Paul = albert;

	cout << user2;
//	cout << user3;
/*
	//initialisation des utilisateurs et des comptes utilisateurs: 
	UtilisateurPremium* alex = new UtilisateurPremium("alex");
	UtilisateurPremium* max = new UtilisateurPremium("Max");
	UtilisateurPremium* henri = new UtilisateurPremium("Henri");
	UtilisateurPremium* louis = new UtilisateurPremium("Louis"); 

	UtilisateurRegulier* albert = new UtilisateurRegulier("albert");
	UtilisateurRegulier* charles = new UtilisateurRegulier("Charles");
	UtilisateurRegulier* allan = new UtilisateurRegulier("Allan");
	UtilisateurRegulier* clemence = new UtilisateurRegulier("Clemence");

	// Initialisation des depenses 
	Depense* d1 = new Depense("d1", 10, "Bruxelles");
	Depense* d2 = new Depense("d2", 30, "Bruxelles");
	Depense* d3 = new Depense("d3", 15, "Bruxelles");
	Depense* d4 = new Depense("d4", 100, "Bruxelles");
	Depense* d5 = new Depense("d5", 120, "Bruxelles");

	DepenseGroupe* d6 = new DepenseGroupe("d6", 1000, "Montreal");
	DepenseGroupe* d7 = new DepenseGroupe( "d7", 430, "Montreal");
	DepenseGroupe* d8 = new DepenseGroupe( "d8", 50, "Montreal");
	DepenseGroupe* d9 = new DepenseGroupe("d9", 330, "Montreal");

	//Initialisation des groupes
	Groupe vacances("Madrid");
	Groupe collocation("Coollocation");

	//Changement nombre de jours pour l'abonnement premium de Louis
	louis->setJoursRestants(0); 

	//Ajouts Utilistaeurs dans les groupes
	(((((((vacances += alex) += max) += henri) += albert) += charles) += allan) += clemence)+=louis; 

	//ajout des depenses indiviuelles 
	*henri += d1; 
	*henri += d2; 
	*henri += d3; 
	*henri += d4;
	*henri += d5; 

	//ajout des depenses groupe

	//vecteur pour le partage de la depense
	vector<Utilisateur*> payePour1;
	payePour1.push_back(alex);
	payePour1.push_back(max);
	payePour1.push_back(charles);
	payePour1.push_back(allan);

	vacances.ajouterDepense(d1, clemence, payePour1); 
	vacances.ajouterDepense(d6, clemence, payePour1); 

	//vecteur pour le partage de la depense
	vector<Utilisateur*> payePour2;
	payePour2.push_back(charles);
	payePour2.push_back(henri);
	payePour2.push_back(max);
	payePour2.push_back(allan);
	vacances.ajouterDepense(d7, albert, payePour2);


	vector<Utilisateur*> payePour3;
	payePour3.push_back(alex);
	payePour3.push_back(max);
	vacances.ajouterDepense(d8, louis, payePour3); 

	
	vacances.calculerTotalDepense();
	vacances.equilibrerComptes(); 

	//ajout d'un utilisateur regulier deja groupe au groupe collocation
	collocation += clemence; 


	//affichage du groupe vacances 
	cout << vacances; 


	//fin du programme 
	delete d1; 
	d1 = nullptr; 
	delete d2;
	d2 = nullptr;
	delete d3;
	d3 = nullptr;
	delete d4;
	d4 = nullptr;
	delete d5;
	d5 = nullptr;
	delete d6;
	d6 = nullptr;
	delete d7;
	d7 = nullptr;
	delete d8;
	d8 = nullptr;
	delete d9;
	d9 = nullptr;
	
	delete alex; 
	delete charles; 
 	delete henri; 
	delete louis; 

	delete albert; 
	delete max; 
	delete allan;
	delete clemence; 
	*/
	system("pause");
	return 0;
}
