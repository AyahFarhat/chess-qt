/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#pragma once
#include"Piece.h"

class Toure : public Piece {
public:
	Toure(char couleur);
	bool mouvementValide(const Coordonnees& from, const Coordonnees& to,  Grille& grille);
	bool clearPath(const Coordonnees& from, const Coordonnees& to,  Grille& grille);
	
};
