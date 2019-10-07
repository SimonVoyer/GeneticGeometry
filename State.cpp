#include "State.h"



State::State(Task* taskPointer)
	:mTaskPointer{taskPointer}
{
}

State::State()
{}


State::~State(){
}

Task * State::taskPointer() {
	return mTaskPointer;
}

void State::setTaskPointer(Task * task)
{
	mTaskPointer = task;
}

void State::addTransition(Transition transition){
	mTransitions.push_back(transition);
}

State * State::isTransiting(char const & event) {

	for (auto t : mTransitions) {
		if (t.isTransiting(event) != nullptr) {
			return t.isTransiting(event);
		}
	}

	return nullptr;

}
