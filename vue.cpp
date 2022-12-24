/////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////


#include "vue.h"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QVBoxLayout>
#include<QHBoxLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>
#include <QString>
#include <QVariant>
#pragma pop()
#include <iostream>

#include <type_traits>
#include <cppitertools/range.hpp>




using iter::range;

	QPushButton* Vue::nouveauBouton( const char& couleur)
	{
		auto bouton = new QPushButton(this);
		bouton->setFixedSize(80, 80);
		if (couleur == BRUN)
			bouton->setStyleSheet("background: brown;font:bold 25px;");
		if (couleur == GRIS)
			bouton->setStyleSheet("background: grey;font:bold 25px;");

		return bouton;
	}
	Vue::Vue(QWidget* parent) :
		QMainWindow(parent)
	{

		boutons_ = new QButtonGroup;
		auto widgetPrincipal = new QWidget(this);
		auto layoutVertical = new QVBoxLayout;
		auto layoutHorizontal = new QHBoxLayout;
		layoutHorizontal->addLayout(layoutVertical);
		auto layoutGrid = new QGridLayout;
		layoutVertical->addLayout(layoutGrid);
		auto layoutVertical2 = new QVBoxLayout;
		layoutHorizontal->addLayout(layoutVertical2);

		auto infolabel = new QLabel(this);
		infolabel->setStyleSheet("font:bold 25px;color:black;");
		infolabel->setText(QString::fromStdString("Bienvenue au jeu d'echecs simple. \nPour commencer une partie, \nchoisissez une des variations suivantes.\n\nLegende:\nRN: Roi Noir\nTN: Toure Noire\nFB: Fou Blanc\nRB: Roi Blanc\n"));
		layoutVertical2->addWidget(infolabel);
		auto newgamebuttonA = new QPushButton();			
		newgamebuttonA->setText("nouvelle partie avec variation A");
		layoutVertical2->addWidget(newgamebuttonA);
		connect(newgamebuttonA, &QPushButton::clicked, [&] {
			game_.startGame('a');
			updateView("Variation A, C'est le tour des pieces blanches");
			});

		auto newgamebuttonB = new QPushButton();
		newgamebuttonB->setText("nouvelle partie avec variation B");
		layoutVertical2->addWidget(newgamebuttonB);
		connect(newgamebuttonB, &QPushButton::clicked, [&] {
			game_.startGame('b');
			updateView("Variation B, C'est le tour des pieces blanches");
			});

		auto newgamebuttonC = new QPushButton();
		newgamebuttonC->setText("nouvelle partie avec variation C");
	
		layoutVertical2->addWidget(newgamebuttonC);
		connect(newgamebuttonC, &QPushButton::clicked, [&] {

			game_.startGame('c');
			updateView("Variation C, C'est le tour des pieces blanches");
			
			});



		widgetPrincipal->setLayout(layoutHorizontal);
		layoutGrid->setSpacing(0);


		int count = 0;//pour pouvoir afficher les differentes couleurs de cases_
		for (auto j : range(8)) {

			for (int i : range(8)) {
				QPushButton* bouton;
				if (count % 2 == 0)
					bouton = nouveauBouton(GRIS);
				
				else
					bouton = nouveauBouton(BRUN);

				//donne un nom au bouton pour pouvoir lidentifier dasn le qpushbuttongroup
				std::string str = "";
				str.push_back(i);
				str.push_back(j);
				bouton->setObjectName(QString::fromStdString(str));
				

				connect(bouton, &QPushButton::clicked, [&, i, j] {
					std::cout << "button clicked" << std::endl;
					std::cout << "x: " << i << " y: " << j << std::endl;
					setmoveFromView(j, i);
					});

				layoutGrid->addWidget(bouton, i, j); // L'ID du bouton est calcule avec calculate ID (doit être un entier).
				boutons_->addButton(bouton, calculateID(j, i));
				count++;
			}
			count++;
		}
		auto label = new QLabel(this);
		label->setText(QString::fromStdString("selectionnez une variation de nouveau jeu"));
		label->setMaximumWidth(650);
		layoutVertical->addWidget(label);
		label->setStyleSheet("background: white;font:bold 25px;color:black;");
		message_ = label;
		setCentralWidget(widgetPrincipal);
		setWindowTitle("Jeu Echecs Simple");

	}
	
	void Vue::updateView(std::string message) {

		int count = 0;//pour pouvoir afficher les differentes couleurs de cases_
		for (auto j : range(8)) {

			for (int i : range(8)) {
					boutons_->button(calculateID(j, i))->setText(QString::fromStdString(game_.getPieceChar(Coordonnees(i, j))));
				if (game_.caseOccupee({ i,j })) {
					if (count % 2 == 0) {

						if (game_.getGrille()->getPiece(Coordonnees(i, j))->getCouleur() == BLANC)
							boutons_->button(calculateID(j, i))->setStyleSheet("background: grey;font:bold 25px;color:white");
						else
							boutons_->button(calculateID(j, i))->setStyleSheet("background: grey;font:bold 25px;color:black");
					}
					else {

						if (game_.getGrille()->getPiece(Coordonnees(i, j))->getCouleur() == BLANC)
							boutons_->button(calculateID(j, i))->setStyleSheet("background: brown;font:bold 25px;color:white");
						else
							boutons_->button(calculateID(j, i))->setStyleSheet("background: brown;font:bold 25px;color:black");
					}
				}	count++;
				
			}count++;		
		}	
		message_->setText(QString::fromStdString(message));
		std::cout << message << std::endl;
	}
	void Vue::setmoveFromView(int x, int y) {

		std::string message = game_.setMove(Coordonnees(y, x));
		updateView(message);
	}

