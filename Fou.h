/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#pragma once
#include"Piece.h"

class Fou : public Piece {
public:
	Fou(const char& couleur);
	bool mouvementValide(const Coordonnees& from, const Coordonnees& to,  Grille& grille)override;
	bool clearPath(const Coordonnees& from, const Coordonnees& to,  Grille& grille)override;

};