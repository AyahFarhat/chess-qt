/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#include "Toure.h"


Toure::Toure(char couleur) {
	setCouleur(couleur);
	setType(TOURE);
};
bool Toure::mouvementValide(const Coordonnees& from, const Coordonnees& to,  Grille& grille) {
	grille;
	bool temp = 1;
	if (grille.caseOccupee(to))
		if (grille.getPiece(to)->getCouleur() == getCouleur())
			temp = false;
	if (((from.X==to.X) && (from.Y!=to.Y))|| ((from.X != to.X) && (from.Y == to.Y)) ){
		if(clearPath(from, to, grille)&& temp)
			return true;
	}
	else
		return false;
}
bool Toure::clearPath(const Coordonnees& from, const Coordonnees& to,  Grille& grille) {
	if (to.X == from.X)//deplacement verticale
	{
		Coordonnees temp = from;
		if (to.Y > from.Y) {
				temp.Y++;
			while (temp.Y != to.Y) {
				Coordonnees temptemp(temp.X, temp.Y);
				bool occuppee = grille.caseOccupee(temptemp);
					temp.Y++; 
				if (occuppee){
					return false;
				}
			} 
		}
		if (to.Y < from.Y) {
			temp.Y--;
			while (temp.Y != to.Y) {
				Coordonnees temptemp(temp.X, temp.Y);
				bool occuppee = grille.caseOccupee(temptemp);
					temp.Y--;
				if (occuppee) {
					return false;
				}
			}
			
		}

	}

	if (to.Y == from.Y)//deplacement horizontal
	{
		Coordonnees temp = from;
		if (to.X > from.X) {
				temp.X++;
				while (temp.X != to.X) {
				Coordonnees temptemp(temp.X, temp.Y);
				temp.X++;
				if (grille.caseOccupee(temptemp))
					return false;
			} 
		}
		if (to.X < from.X) {
				temp.X--;
				while (temp.X != to.X) {
				Coordonnees temptemp(temp.X, temp.Y);
				temp.X--;
				if (grille.caseOccupee(temptemp))
					return false;
			} 
		}

	}
	return true;



}