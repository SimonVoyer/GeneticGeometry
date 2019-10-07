// File name :		Transition.cpp
// Creation :		2018-12-15
// Author :			Basile Paradis, Pierre-Marc Dameus, Vanessa Daneault-Pilote  Simon Voyer
// Additional credit: Tiré du projet Snake (Guillaume Bergeron-Geoffroy, Mathieu Laverdure, Simon Voyer)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Context :		AlgoGenetique
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Brief :			Programme de l'algorithme génétique. 
//
// Codede la classe qui gère les transitions
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#include "Transition.h"

Transition::Transition(char key, State * nextStatePointer)
	: mKey{ key },
	mNextStatePointer{ nextStatePointer }
{
}

State * Transition::isTransiting(char const & event) {
	if (event == mKey) {
		return mNextStatePointer;
	}
	else {
		return nullptr;
	}
}

