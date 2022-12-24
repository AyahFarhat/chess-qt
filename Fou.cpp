/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#include "Fou.h"

using namespace std;

Fou::Fou(const char& couleur) {
	setCouleur(couleur);
	setType(FOU);
};

bool Fou::mouvementValide(const Coordonnees& from, const Coordonnees& to,  Grille& grille) {
	grille;
	bool temp = 1;
	if (grille.caseOccupee(to))
		if (grille.getPiece(to)->getCouleur() == getCouleur())// if to and from are same colour meaning you cant eat the piece at position "to"
			temp = false;
		
	if( (abs(from.X - to.X) == abs(from.Y - to.Y))&&temp&& clearPath(from, to, grille)){
		return true;
	}
	else
		return false;
}
bool Fou::clearPath(const Coordonnees& from, const Coordonnees& to,  Grille& grille) {

	Coordonnees temp = from;
	if (from.X > to.X && from.Y>to.Y) {
		temp.X--; temp.Y--;
		while (temp.X != to.X) {
			Coordonnees temptemp(temp.X, temp.Y);
			bool occuppee = grille.cases_[temptemp]->caseOccupee();
			temp.X--; temp.Y--;
			if (occuppee)
				return false;
		} 
	}
	else if (from.X > to.X && from.Y < to.Y) {
		temp.X--; temp.Y++;
		while (temp.X != to.X) {
			Coordonnees temptemp(temp.X, temp.Y);
			bool occuppee = grille.cases_[temptemp]->caseOccupee();
			temp.X--; temp.Y++;
			if (occuppee)
				return false;
		}
	}
	else if (from.X < to.X && from.Y > to.Y) {
		temp.X++; temp.Y--;
		while (temp.X != to.X) {
			Coordonnees temptemp(temp.X, temp.Y);
			bool occuppee = grille.caseOccupee(temptemp);
			temp.X++; temp.Y--;
			if (occuppee)
				return false;
		}
	}
	else if (from.X < to.X && from.Y < to.Y) {
			temp.X++; temp.Y++;
		while (temp.X != to.X) {
			Coordonnees temptemp(temp.X, temp.Y);
			bool occuppee = grille.caseOccupee(temptemp);
			temp.X++; temp.Y++;
			if (occuppee)
				return false;
		}
	}	
	
	return true;

}