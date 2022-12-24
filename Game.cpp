/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#include "Game.h"
using namespace std;

void Game::afficherPieces(){
	for (auto it = echiquier_.cases_.begin();it != echiquier_.cases_.end();++it) {

		if (it->second->caseOccupee())
			cout << "(" << it->first.X << "," << it->first.Y << ") " << getPieceChar({ it->first.X,it->first.Y }) << endl;

	}
	cout << "-----------------------------------------------------------" << endl;
}



Coordonnees Game::getRoi(char couleur) {
	Coordonnees roi;
	for (auto it = echiquier_.cases_.begin();it != echiquier_.cases_.end();it++) {
		if (it->second->caseOccupee()) {
			if (it->second->getPiece()->getType() == ROI && it->second->getPiece()->getCouleur() == couleur) {
				return it->first;

			}
		}
	}	
}
bool Game::miseEnEchec(Coordonnees from, Coordonnees to, char couleur) {//its my turn im colour, am i in check after i make a move
	bool resultat=false;
	Coordonnees PositionDeMonRoi = getRoi(couleur);
	//echiquier_.setPiece(from, to);
	for (auto it = echiquier_.cases_.begin();it != echiquier_.cases_.end();it++) {
		if (it->second->caseOccupee()) {
			if (it->second->getPiece()->getCouleur() != couleur) {
				if (echiquier_.mouvementValidePiece(it->first, PositionDeMonRoi)) {
					echiquier_.setPiece(to, from);
					return true;
				}
			}		
		}
	}

	return resultat;
}


	void Game::changeTurn() {
		if (nextTurn_ == BLANC)
			nextTurn_ = NOIRE;
		else
			nextTurn_ = BLANC;
	}
	std::string Game::getPieceChar(const Coordonnees& coords) {//pour afficher sur lechequier le type de piece et la couleur
		std::string str = "";
		if (caseOccupee(coords)) {
			str.push_back(std::toupper(echiquier_.getPiece(coords)->getType()));
			str.push_back(std::toupper(echiquier_.getPiece(coords)->getCouleur()));
		}
		else
			str.push_back(' ');
		return str;
	}
	Grille* Game::getGrille() { return &echiquier_; }
	void Game::ajouterPiece(std::shared_ptr<Piece> pieceAAjouter, const Coordonnees& coord) {
		echiquier_.addPiece(pieceAAjouter, coord);
	}
	std::string Game::nextTurn_Message() {
		if (nextTurn_ == BLANC)
			return WhiteTurn;
		else return BlackTurn;
	}
	char Game::getTurn() { return nextTurn_; }
	bool Game::caseOccupee(const Coordonnees& coords) {
		return echiquier_.caseOccupee(coords);
	}
	void Game::resetMoves() {
		firstClickFrom_ = NULLCOORD;
		secondClickTo_ = NULLCOORD;
	}
	Game::Game():echiquier_() {
	}
	void Game::startGame(char option) {
		echiquier_.setupGrille(option);
		resetMoves();
		nextTurn_ = BLANC;
		
	}

	bool Game::makeAmove(const Coordonnees& from, const Coordonnees& to) {
		//bool mouvementValide = echiquier_.mouvementValidePiece(from, to);
		if (from!=to && echiquier_.mouvementValidePiece(from, to)) {
		echiquier_.setPiece(from, to);
		return true;		
	}
	else
		return false;
	}


	std::string Game::setMove(const Coordonnees& coord) {
		if (secondClickTo_ != NULLCOORD) {//if both clicks have happened
			resetMoves();
		}
		if (firstClickFrom_ == NULLCOORD) {//after both clicks have happened, want to set first click as "from"
			if (echiquier_.caseOccupee(coord)) {//make sure that a piece is actually there to move
				if (echiquier_.getPiece(coord)->getCouleur() == nextTurn_)	{ // check to see if its your turn	
					firstClickFrom_ = coord;					
				}
				else {
					resetMoves();
					return NotYourTurn;
				}
			}
		}
		else {//if first click has already been set, want to set second click to complete move
				secondClickTo_ = coord;							
				if (makeAmove(firstClickFrom_, secondClickTo_)) {
					if (miseEnEchec(firstClickFrom_, secondClickTo_, nextTurn_))
						return InvalidMoveKingInCheck;
					else {
						changeTurn();
						afficherPieces();
					}
				}
				else {
					resetMoves();
					return InvalidMove;
				}
			}		
		return nextTurn_Message();
	}


