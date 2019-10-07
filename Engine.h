#ifndef ENGINE_H
#define ENGINE_H
#include "Automaton.h"
#include <list>
#include "Shape.h"
#include "Parameters.h"
#include "State.h"

class Engine {
private:
	Automaton mAutomaton;
	std::list<Shape*> mShapeList;
	std::list<State> mStateList;
	State mSetUpState;
	State mStartState;
	State mContinuousState;
	State mPauseState;
	State mStepState;
	State mReinitializeState;
	State mExitState;
public:
	Engine();
	~Engine();
	std::list<Shape*>  shapeList();
	Automaton & automaton();
	void startAutomaton();
	

};

#endif //!ENGINE_H