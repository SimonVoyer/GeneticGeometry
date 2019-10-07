// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// File name :		ExitTask.cpp
// Creation :		2018-12-15
// Author :			Basile Paradis, Pierre-Marc Dameus, Vanessa Daneault-Pilote  Simon Voyer
// Additional credit: Tir� du projet Snake (Guillaume Bergeron-Geoffroy, Mathieu Laverdure, Simon Voyer)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Context :		AlgoGenetique
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Brief :			Programme de l'algorithme g�n�tique
//
// Code de la classe qui h�rite de task et g�re les actions de l'�tat Exit
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

#include "ExitTask.h"
#include <iostream>

ExitTask::ExitTask() 
{

}
void ExitTask::process(ConsoleKeyReader::KeyEvents keyList) {
	exit(0);
	
}
void ExitTask::render() {
	std::cout << "\nRendering Exit.";
}

