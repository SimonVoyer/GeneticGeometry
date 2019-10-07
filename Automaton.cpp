// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// File name :		Automaton.cpp
// Creation :		2018-12-15
// Author :			Basile Paradis, Pierre-Marc Dameus, Vanessa Daneault-Pilote  Simon Voyer
// Additional credit: Tir� du projet Snake (Guillaume Bergeron-Geoffroy, Mathieu Laverdure, Simon Voyer)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Context :		AlgoGenetique
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Brief :			Programme de l'algorithme g�n�tique. 
//
// Code de la classe qui impl�mente le design pattern de l'Automate fini (Finite State Machine)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include "Automaton.h"
#include "Obstacle.h"
#include "State.h"
#include "ContinuousTask.h"
#include <iostream>

Automaton::Automaton()
	:mInitialState{ nullptr },
	 mCurrentState{ nullptr }
{
}

Automaton::~Automaton()
{}

std::list<State> Automaton::stateList() {
	return mStateList;
}

void Automaton::setStateList(std::list<State> & stateList) {
	mStateList = stateList;
}

State * Automaton::initialState() {
	return mInitialState;
};

State * Automaton::currentState() {
	return mCurrentState;
};

void Automaton::initialize() {
	mCurrentState = mInitialState;
}

//proc�dure par laquelle l'automaton active la t�che de son �tat actuelle
void Automaton::processTask(ConsoleKeyReader::KeyEvents keyList) {
	bool stateChanged = false;
		for (auto key : keyList) {
			if (currentState()->isTransiting(key.keyA()) != nullptr) {
				mCurrentState = currentState()->isTransiting(key.keyA());
				stateChanged = true;
			}
			if (key.keyA() == '1') { //test
				stateChanged = true;
			}
		}
		if (stateChanged || dynamic_cast<ContinuousTask*>(currentState()->taskPointer()) != nullptr) {
			currentState()->taskPointer()->process(keyList);
		}
	}


parameters & Automaton::currentParameters() {
	return mCurrentParameters;
}

void Automaton::setInitialState(State * state) {
	mInitialState = state;
}

void Automaton::launchInitialState() {
	mInitialState->taskPointer()->process();
}


void Automaton::setCurrentParameters(parameters currentParameters) {
	mCurrentParameters = currentParameters;
}

Civilization & Automaton::civilization(){
	return mCivilization;
}

void Automaton::launchDrawing()
{
	ConsoleContext consoleContext(600, 300, "AlgoGenetique", 3, 3, L"Consolas");
	Console::defineContext(consoleContext);

	// Cr�e le writer
	ConsoleWriter & writer{ Console::getInstance().writer() };
	writer.createImage(Screen::CONSOLE_VIEW);

	// Cr�e et initialise le vecteur d'obstacle
	Obstacle listePoints;
	listePoints.initializeVector(250, 600, 300);

	// Cr�e le screen
	Screen screen{ Screen(Console::MinWidth, Console::MinHeight, Console::MaxWidth, Console::MaxHeight) };

	// Objet solution
	Solution s{ Solution() };

	size_t anglerotation = 0;

	// Boucle pour dessine les formes g�om�triques
	while (currentState() == nullptr)
	{
		// G�n�re un rectangle avec coordonn�es arbitraires (pour test)
		Rectangle2d rect{ Rectangle2d(50, 25, Point2d(300, 150), anglerotation) };

		// G�n�re un cercle avec coordonn�es arbitraires (pour test)
		Circle cercle{ Circle(Point2d(300, 150), 80) };

		//s.shape()->x()
		writer.image(Screen::CONSOLE_VIEW).drawCircle(cercle.point().x(), cercle.point().y(), cercle.radius(), ' ', ConsoleColor::tR);

		// Dessine les rectangles
		screen.showRectangle(writer.image("ConsoleView"), rect, ConsoleColor::tB);

		// Pour dessiner cercles
		screen.showCircle(ConsoleColor::tB, writer, cercle, listePoints);

		// Affiche dans Screen
		screen.showScreen(ConsoleColor::tW, writer, listePoints);

		anglerotation += 3;
	}
}

