/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#pragma once
#include"Grille.h"
#include"Roi.h"
#include"Fou.h"
#include"Toure.h"
#include <vector>
#include <QDebug>
#include <QObject>
#include <QString>
#include<iostream>
#include "constantes.h"
#include <QPushButton>
#include"constantes.h"
#include<map>



	class Game : public QObject {
		Q_OBJECT
	public:
		Game();
		char getTurn();
		void startGame(char option);
		bool caseOccupee(const Coordonnees& coords);
		void resetMoves();
		std::string setMove(const Coordonnees& coord); //the method called in the vue
		std::string getPieceChar(const Coordonnees& coords); //pour afficher sur lechequier le type de piece et la couleur
		std::string nextTurn_Message();
		bool makeAmove(const Coordonnees& from, const Coordonnees& to);
		void ajouterPiece(std::shared_ptr<Piece> pieceAAjouter, const Coordonnees& coord);
		Grille* getGrille();	
		bool miseEnEchec(Coordonnees from, Coordonnees to,char couleur);
		Coordonnees getRoi(char couleur);
		void afficherPieces();
		
	private:
		Grille echiquier_;
		char nextTurn_ = BLANC;
		Coordonnees firstClickFrom_;
		Coordonnees secondClickTo_;		
		void changeTurn();
	};
