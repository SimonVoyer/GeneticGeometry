// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// File name :		ExitTask.h
// Creation :		2018-12-15
// Author :			Basile Paradis, Pierre-Marc Dameus, Vanessa Daneault-Pilote  Simon Voyer
// Additional credit: Tir� du projet Snake (Guillaume Bergeron-Geoffroy, Mathieu Laverdure, Simon Voyer)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Context :		AlgoGenetique
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Brief :			Programme de l'algorithme g�n�tique
//
// Header de la classe qui h�rite de task et g�re les actions de l'�tat Exit
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

