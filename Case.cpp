//////////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////
#include "Case.h"
bool Case::caseOccupee() {
	return piece_ != nullptr;
};
void Case::setPiece(std::shared_ptr<Piece> piece) {	
	piece_ = piece ;	
};
std::shared_ptr<Piece>  Case::getPiece() {
	return piece_;
};