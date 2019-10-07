//entête
#include "StepTask.h"
#include "Automaton.h"
#include <iostream>

void StepTask::process(ConsoleKeyReader::KeyEvents keyList) {
	//for (auto & populationEngine : automatonPointer()->civilization().populationEngineVector()) {
	//	populationEngine.newGeneration();
	//}
	automatonPointer()->civilization().newGenerations();
}

void StepTask::render() {
	std::cout << "\nStep rendering.";
}