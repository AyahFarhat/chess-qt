/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////

//#include "Calc.hpp"
//#include "CalcWindow.hpp"
//#include"Game.h"
#pragma once
#include "vue.h"

#include <QApplication>
#include<Qwidget>
#include<memory>

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.
	
	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
	#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}
using namespace std;
void testsEchec() {
	Game testGame;
	testGame.startGame('a');
	cout << "MOUVEMENTS VALIDES" << endl;
	cout << "*****************************************************************************************************" << endl;
	cout << "deplacement de du roi blanc (RB) de la position (6,6) vers (5,5)" << endl;
	auto temp=testGame.getGrille()->findPiece(ROI, BLANC);
	if (temp != nullptr)
		cout << "le roi a ete deplace, voici les nouvelles positions" << endl;
	cout << testGame.setMove({ 6,6 }) << endl;
	cout << testGame.setMove({ 5,5 }) << endl;
	cout << testGame.setMove({ 4,3 }) << endl;
	cout << testGame.setMove({ 2,3 }) << endl;
	cout << testGame.setMove({ 1,6 }) << endl;
	cout << testGame.setMove({ 6,1 }) << endl;
	cout << testGame.setMove({ 0,3 }) << endl;
	cout << testGame.setMove({ 1,3 }) << endl;
	cout << "CHANGEMENT DE VARIATION DE DEBUT DE JEU" << endl;
	cout << "*****************************************************************************************************" << endl;
	testGame.startGame('c');
	cout << "VARIATION C" << endl;
	testGame.startGame('b');
	cout << "VARIATION B" << endl;
	testGame.afficherPieces();
	cout << "MOUVEMENTS NON-VALIDES AVEC MESSAGE DERREUR" << endl;
	cout << "*****************************************************************************************************" << endl;
	cout<<testGame.setMove({ 6,3 });
	cout << testGame.setMove({ 3,0 }) << endl;
	cout << testGame.setMove({ 3,2 }) << endl;
	cout << testGame.setMove({ 0,4 }) << endl;
	cout << testGame.setMove({ 3,4 }) << endl;
	cout << testGame.setMove({ 0,4 }) << endl;
	testGame.setMove({ 2,2 });
	cout<<  testGame.setMove({ 0,0 }) << endl;
	cout << testGame.setMove({3,3 }) << endl;
	testGame.afficherPieces();
	cout << "TESTS DE MISE EN ECHEC AVEC VARIATION A" << endl;
	cout << "*****************************************************************************************************" << endl;
	testGame.startGame('a');
	 testGame.setMove({ 6,6 });
	 testGame.setMove({ 5,6 });
	 testGame.setMove({ 4,3 });
	 testGame.setMove({ 4,6 });
	 testGame.setMove({ 5,6 });
	cout << testGame.setMove({ 6,6 }) << endl;
}

int main(int argc, char *argv[])
{
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	QApplication app(argc, argv);
	initialiserBibliothequeCours(argc, argv);
	testsEchec();
	Vue chessGame;	
	chessGame.show();
	return app.exec();
}
