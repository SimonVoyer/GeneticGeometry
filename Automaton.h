// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// File name :		Automaton.h
// Creation :		2018-12-11
// Author :			Basile Paradis, Pierre-Marc Dameus, Vanessa Daneault-Pilote  Simon Voyer
// Additional credit: Tir� du projet Snake (Guillaume Bergeron-Geoffroy, Mathieu Laverdure, Simon Voyer)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Context :		AlgoGenetique
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Brief :			Programme d'algorithme g�n�tique.
//
// Header de la classe qui impl�mente le design pattern de l'Automate fini (Finite State Machine) 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

#ifndef AUTOMATON_H
#define AUTOMATON_H
#include "State.h"
#include "Console.h"
#include "Parameters.h"
#include "RandomTools.h"
#include <list> 
#include "Civilization.h"
#include "Screen.h"

class Automaton
{
public:
	Automaton();
	~Automaton();
	std::list<State> stateList();
	void setStateList(std::list<State> & stateList);
	void initialize();
	State * initialState();
	State * currentState();
	void setInitialState(State * state);
	void launchInitialState();
	void processTask(ConsoleKeyReader::KeyEvents keyList); 
	parameters & currentParameters();
	void setCurrentParameters(parameters currentParameters);
	Civilization & civilization();
	void launchDrawing();

private:
	std::list<State> mStateList;
	State * mInitialState;
	State * mCurrentState;
	parameters mCurrentParameters;
	Civilization mCivilization;

};


#endif // !AUTOMATON_H


