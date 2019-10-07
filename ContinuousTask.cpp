//entête
#include "ContinuousTask.h"
#include "Automaton.h"
#include <iostream>
//#include <thread>

void ContinuousTask::process(ConsoleKeyReader::KeyEvents keyList) {
	process();
}

void ContinuousTask::render() {
	std::cout << "\nContinuous rendering.";
}

void ContinuousTask::process() {
	automatonPointer()->civilization().newGenerations();
	automatonPointer()->currentParameters().currentIteration++;
}


