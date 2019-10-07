//entête
#include "StartTask.h"
#include <iostream>

void StartTask::process(ConsoleKeyReader::KeyEvents keyList) {
	std::cout << "\nPress 1 for a single step foward and c for continuous steps.";
}

void StartTask::render() {
	std::cout << "\nStart rendering.";
}