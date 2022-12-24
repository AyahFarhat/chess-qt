/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#pragma once
#include"Case.h"
#include<iostream>
#include<map>
#include"constantes.h"
class Piece;

class Grille {

public:
	Grille();//creates the cases_
	void setupGrille(char option);//met les pieces dasn la grille selon loption de setup
	void setupPiecesA();
	void setupPiecesC();
	void setupPiecesB();
	void resetGrille();
	std::shared_ptr<Piece> getPiece  (const Coordonnees& coord) ; //returns the piece sitting at that coord
	void setPiece(const Coordonnees& from, const Coordonnees& to); //changer la position dune piece
	bool mouvementValidePiece(const Coordonnees& from, const Coordonnees& to) ;// checks if valid move for specific piece
	bool caseOccupee(const Coordonnees& coord) ;
	void addPiece(std::shared_ptr<Piece> pieceAAjouter, const Coordonnees& coord);
	void removePiece(std::shared_ptr<Piece> pieceAEnlever);
	std::shared_ptr<Piece>  findPiece(char type, char colour);

	std::map<Coordonnees, std::shared_ptr<Case>> cases_;

};


