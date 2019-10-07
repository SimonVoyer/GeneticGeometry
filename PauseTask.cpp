//entête
#include "PauseTask.h"
#include <iostream>

void PauseTask::process(ConsoleKeyReader::KeyEvents keyList) {
	std::cout << "\nPause process.";
}

void PauseTask::render() {
	std::cout << "\nPause rendering.";
}