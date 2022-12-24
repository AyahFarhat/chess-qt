/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#include "Roi.h"

using namespace std;

bool Roi::mouvementValide (const Coordonnees& from, const Coordonnees& to,    Grille& grille) {
	bool temp=1;
	if (grille.caseOccupee(to))
		if (grille.getPiece(to)->getCouleur() == getCouleur())
			temp = false;

	if (abs(to.X - from.X) <= 1 && abs(to.Y-from.Y) <= 1 && temp)
	{
			return true;
	}//checks if piece at that position is different colour
	//if it is, allow mouvement
	else
		return false;
}
bool Roi::clearPath(const Coordonnees& from, const Coordonnees& to,   Grille& grille) {
	return true;
}
Roi::Roi(const char& couleur) {

	setCouleur(couleur);
	setType(ROI);

};
