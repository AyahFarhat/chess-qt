/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#include "Grille.h"
#include"cppitertools/range.hpp"
#include"gsl/span"
#include"Roi.h"
#include"Fou.h"
#include"Toure.h"


Grille::Grille() {// creer la grille
	for (int i : iter::range(8)){
		for (int j : iter::range(8)) {
			Coordonnees temp(i, j);
			cases_.insert(std::pair<Coordonnees, std::shared_ptr<Case>>(temp, std::make_shared<Case>())); 
		}
	}
}
std::shared_ptr<Piece>  Grille::findPiece(char type, char couleur) {
	for (auto it = cases_.begin();it != cases_.end();++it) {
		if (caseOccupee(it->first)) {
			if (it->second->getPiece()->getCouleur() == couleur && it->second->getPiece()->getType() == type)
				return it->second->getPiece();
		}				
	}
	return nullptr;
}
void Grille::resetGrille() {
	for (auto it = cases_.begin();it != cases_.end();++it) {
		it->second.get()->setPiece(nullptr);
	}
}
void Grille::setupGrille(char option) {//mettre les pieces dasn la grille
	resetGrille();
	switch (option) {
			case 'a': setupPiecesA();
				break;       // and exits the switch
			case 'b': setupPiecesB();
				break;       // and exits the switch
			case 'c': setupPiecesC();
				break;       // and exits the switch
			}
}
void Grille::addPiece(std::shared_ptr<Piece> pieceAAjouter, const Coordonnees& coord) {
	auto it = cases_.find(coord);
	it->second.get()->setPiece(pieceAAjouter);
}
void Grille::removePiece(std::shared_ptr<Piece> pieceAEnlever) {
	for (auto it = cases_.begin();it != cases_.end();++it) {
		if (it->second.get()->getPiece() == pieceAEnlever)
			it->second.get()->setPiece(nullptr);
	}
}
bool Grille::caseOccupee(const Coordonnees& coord) { 
	return cases_[coord]->caseOccupee(); 
}

std::shared_ptr<Piece> Grille::getPiece (const Coordonnees& coords)  {

	return cases_[coords]->getPiece();
}
void Grille::setPiece(const Coordonnees& from, const Coordonnees& to) {
	auto fromIterator = cases_.find(from);// key is a cordonnee
	auto toIterator = cases_.find(to);
	toIterator->second = fromIterator->second; //put the piece that was in first click position to secnd click position
	fromIterator->second = std::make_shared<Case>();

}
bool Grille::mouvementValidePiece(const Coordonnees& from, const Coordonnees& to) {
	if (cases_[from]->getPiece()->mouvementValide(from, to, *this))
		return true;
	return false;
}



void Grille::setupPiecesA() {//rouge
	Roi roiB(BLANC), roiN(NOIRE);//, roiR(NOIRE);
	cases_[{0, 3}]->setPiece(std::make_shared<Roi>(roiN));
	cases_[{6, 6}]->setPiece(std::make_shared<Roi>(roiB));

	Fou fouB(BLANC);
	Toure toureN(NOIRE);
	cases_[{1, 6}]->setPiece(std::make_shared<Fou>(fouB));
	cases_[{4, 3}]->setPiece(std::make_shared<Toure>(toureN));
}

void Grille::setupPiecesB() {
		Roi roiB(BLANC), roiN(NOIRE);
		cases_[{0, 0}]->setPiece(std::make_shared<Roi>(roiN));
		cases_[{3, 0}]->setPiece(std::make_shared<Roi>(roiB));

		Fou fouB(BLANC);
		Toure toureN(NOIRE);
		cases_[{0, 4}]->setPiece(std::make_shared<Fou>(fouB));
		cases_[{6, 3}]->setPiece(std::make_shared<Toure>(toureN));
	}

void Grille::setupPiecesC() {
			Roi roiB(BLANC), roiN(NOIRE);
			cases_[{2, 2}]->setPiece(std::make_shared<Roi>(roiN));
			cases_[{3, 5}]->setPiece(std::make_shared<Roi>(roiB));

			Fou fouB(BLANC);
			Toure toureN(NOIRE);
			cases_[{1, 0}]->setPiece(std::make_shared<Fou>(fouB));
			cases_[{4, 5}]->setPiece(std::make_shared<Toure>(toureN));
}
