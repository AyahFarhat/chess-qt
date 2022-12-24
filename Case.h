/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#pragma once
#include<memory>
#include<QGraphicsRectItem>

class Piece;

class Case  {
public:
	void setPiece(std::shared_ptr<Piece> piece);
	std::shared_ptr<Piece> getPiece();
	bool caseOccupee();

private:
	std::shared_ptr<Piece> piece_ = nullptr;

};