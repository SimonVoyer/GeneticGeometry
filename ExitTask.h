// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// File name :		ExitTask.h
// Creation :		2018-12-15
// Author :			Basile Paradis, Pierre-Marc Dameus, Vanessa Daneault-Pilote  Simon Voyer
// Additional credit: Tiré du projet Snake (Guillaume Bergeron-Geoffroy, Mathieu Laverdure, Simon Voyer)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Context :		AlgoGenetique
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Brief :			Programme de l'algorithme génétique
//
// Header de la classe qui hérite de task et gère les actions de l'état Exit
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

#ifndef EXIT_TASK_H
#define EXIT_TASK_H
#include "Task.h"
#include "State.h"

class ExitTask : public Task {
public:
	ExitTask();
	void process(ConsoleKeyReader::KeyEvents keyList) override;
	void render() override;

};

#endif // !EXIT_TASK_H

