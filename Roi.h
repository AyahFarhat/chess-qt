/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#pragma once
#include"Piece.h"


class Roi : public Piece {
public:
	Roi(const char& couleur);
	bool clearPath(const Coordonnees& from, const Coordonnees& to,  Grille& grille)override;	
	bool mouvementValide(const Coordonnees& from, const Coordonnees& to,   Grille& grille)override;

};

