////////////////////////////////////////////////////////////////////
//	Ayah Farhat 2153946, Mariem Ben Jaber 2082688
//	Jeu d'echecs: Remise Finale
//	202-05-06
//////////////////////////////////////////////////////////////////


#pragma once


#include "Game.h"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include<QButtonGroup>
#include<iostream>
#include<memory>

#include <QLabel>
#pragma pop()



	class Vue : public QMainWindow {
		Q_OBJECT

	public:
		Vue(QWidget* parent = nullptr);
		~Vue() override = default;
		void updateView(std::string message);
		int calculateID(int x, int y) { return (x * x * x + y * 3); }
		void setmoveFromView(int x, int y);
		
	signals:
		void clickDetecte(QPushButton*);

	private:
		QPushButton* nouveauBouton(	const char& couleur);
		Game game_;  // Le Modèle (pourrait être un pointeur mais pas nécessaire dans ce cas).
		QLabel* message_;
		QButtonGroup* boutons_;
	};
