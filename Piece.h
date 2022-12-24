/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#pragma once

#include"constantes.h"
#include "Grille.h"
#include<memory>
#include<iostream>

class Piece {
public:
	virtual ~Piece() = default;	
	//Piece() = default;
	virtual bool mouvementValide(const Coordonnees& from, const Coordonnees& to, Grille& grille) = 0; //checks to see if the move is valid for that specific piece in terms of chess rules
	virtual bool clearPath(const Coordonnees& from, const Coordonnees& to, Grille& grille) = 0;
	char getCouleur() const { return couleur_; };
	char getType() const { return type_; };
	void setCouleur(const char& c) { couleur_ = c; }
	void setType(const char& t) { type_ = t; }

protected:
	char couleur_;
	char type_;
};