#include "Task.h"

Task::Task(){
	
}

Task::~Task(){
}

void Task::process(ConsoleKeyReader::KeyEvents keyList) {
}

void Task::process() {

}
void Task::render() {
}

Automaton * Task::automatonPointer() {
	return mAutomatonPointer;
}

void Task::setAutomatonPointer(Automaton * automatonPointer) {
	mAutomatonPointer = automatonPointer;
}