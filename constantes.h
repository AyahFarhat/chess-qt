/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#pragma once
#include<math.h>
#include<iostream>
using std::string;

const char NOIRE = 'n';
const char BLANC = 'b';
const char BRUN = 'r';
const char GRIS = 'g';
const char ROI = 'r';
const char FOU = 'f';
const char TOURE = 't';

const	string WhiteTurn = "C'est le tour des pieces blanches";
const	string BlackTurn = "C'est le tour des pieces noires";
const	string InvalidMove = "Mouvement invalide";
const	string NotYourTurn = "C'est pas ton tour";
const	string InvalidMoveKingInCheck = "Mouvement invalide, ton roi serait en echec";

struct Coordonnees {
	Coordonnees(int x, int y) {
		X = x; Y = y;	
		count_ = (x * x * x + y * 3);//formule pour creer un "ID" different pour chauqe paire de coordonnees differentes pour pouboir les ordonner dans un ordre precis selon lattribut count qui represente le ID specifique de chaque paire de donnees
		
	}
	~Coordonnees() = default;
	Coordonnees(const Coordonnees& coord) {
		X = coord.X;
		Y = coord.Y;
		count_ = (X * X * X + Y * 3);
	}
	Coordonnees() {
		X = 111;
		Y = 111;
		count_ = ( X * X * X + Y * 3);
	}	
	bool operator< (const Coordonnees& coord) const {
	
		return count_ < coord.count_;
	}
	bool operator==(const Coordonnees& coord) const {

		return (coord.X == X && coord.Y == Y);
	}
	Coordonnees& operator=(const Coordonnees& coord)  {

		X = coord.X;
		Y = coord.Y;
		count_ = (X * X * X + Y * 3);
		return *this;
	}
	int count_ = 0;
	int X;
	int Y;
	
};
const Coordonnees NULLCOORD(111, 111);//utilise pour avoir une coordonnee dite nulle sans utiliser 0,0 car ces une coordonnee valable


