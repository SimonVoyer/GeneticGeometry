// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// File name :		Automaton.cpp
// Creation :		2018-12-15
// Author :			Basile Paradis, Pierre-Marc Dameus, Vanessa Daneault-Pilote  Simon Voyer
// Additional credit: Tiré du projet Snake (Guillaume Bergeron-Geoffroy, Mathieu Laverdure, Simon Voyer)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Context :		AlgoGenetique
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Brief :			Programme de l'algorithme génétique. 
//
// Code de la classe qui implémente le design pattern de l'Automate fini (Finite State Machine)
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

//procédure par laquelle l'automaton active la tâche de son état actuelle
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

	// Crée le writer
	ConsoleWriter & writer{ Console::getInstance().writer() };
	writer.createImage(Screen::CONSOLE_VIEW);

	// Crée et initialise le vecteur d'obstacle
	Obstacle listePoints;
	listePoints.initializeVector(250, 600, 300);

	// Crée le screen
	Screen screen{ Screen(Console::MinWidth, Console::MinHeight, Console::MaxWidth, Console::MaxHeight) };

	// Objet solution
	Solution s{ Solution() };

	size_t anglerotation = 0;

	// Boucle pour dessine les formes géométriques
	while (currentState() == nullptr)
	{
		// Génère un rectangle avec coordonnées arbitraires (pour test)
		Rectangle2d rect{ Rectangle2d(50, 25, Point2d(300, 150), anglerotation) };

		// Génère un cercle avec coordonnées arbitraires (pour test)
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

