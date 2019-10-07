#ifndef STATE_H
#define STATE_H
#include "Task.h"
#include <list>
#include "Transition.h"
class State
{
private:
	Task * mTaskPointer;
	std::list<Transition> mTransitions;
public:
	State(Task * taskPointer);
	State();
	~State();
	Task * taskPointer();
	void setTaskPointer(Task * task);
	void addTransition(Transition transition);
	State * isTransiting(char const & event);
	
};

#endif //!STATE_H