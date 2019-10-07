#include "Engine.h"
#include "RandomTools.h"
#include "Console.h"
#include "SetUpTask.h"
#include "StartTask.h"
#include "PauseTask.h"
#include "StepTask.h"
#include "ReinitializeTask.h"
#include "ContinuousTask.h"
#include "ExitTask.h"
#include "ConsoleKeyFilterUp.h"
#include <iostream>

Engine::Engine(){
	//intialisation des tasks
	Task * setUpTask = new SetUpTask();
	Task * startTask = new StartTask();
	Task * continuousTask = new ContinuousTask();
	Task * pauseTask = new PauseTask();
	Task * stepTask = new StepTask();
	Task * reinitializeTask = new ReinitializeTask();
	Task * exitTask = new ExitTask();

	//on donne un pointeur d'automate aux tasks
	setUpTask->setAutomatonPointer(&mAutomaton);
	startTask->setAutomatonPointer(&mAutomaton);
	continuousTask->setAutomatonPointer(&mAutomaton);
	pauseTask->setAutomatonPointer(&mAutomaton);
	stepTask->setAutomatonPointer(&mAutomaton);
	reinitializeTask->setAutomatonPointer(&mAutomaton);
	exitTask->setAutomatonPointer(&mAutomaton);
	
	//assignation d'un task pointer aux states || NB: transfère de responsabilités des pointeurs de task
	mSetUpState.setTaskPointer(setUpTask);
	mStartState.setTaskPointer(startTask);
	mContinuousState.setTaskPointer(continuousTask);
	mPauseState.setTaskPointer(pauseTask);
	mStepState.setTaskPointer(stepTask);
	mReinitializeState.setTaskPointer(reinitializeTask);
	mExitState.setTaskPointer(exitTask);

	//initialisation des transitions
	Transition setUp = Transition('i', &mSetUpState);
	Transition start = Transition('s', &mStartState);
	Transition oneStep = Transition('1', &mStepState);
	Transition continuous = Transition('c', &mContinuousState);
	Transition pause = Transition('p', &mPauseState);
	Transition reinitialize = Transition('r', &mReinitializeState);
	Transition exit = Transition('q', &mExitState);

	//assignation des transitions aux states
	mSetUpState.addTransition(start);
	mStartState.addTransition(oneStep);
	mStartState.addTransition(continuous);
	mStepState.addTransition(pause);
	mStepState.addTransition(continuous);
	mContinuousState.addTransition(pause);
	mPauseState.addTransition(oneStep);
	mPauseState.addTransition(continuous);
	mPauseState.addTransition(reinitialize);
	mReinitializeState.addTransition(setUp);
	mReinitializeState.addTransition(start);
	mReinitializeState.addTransition(exit);


	//ajout des states à la liste
	mStateList.push_back(mSetUpState);
	mStateList.push_back(mStartState);
	mStateList.push_back(mContinuousState);
	mStateList.push_back(mPauseState);
	mStateList.push_back(mStepState);
	mStateList.push_back(mReinitializeState);
	
	//attribution de la liste à l'automaton;
	mAutomaton.setStateList(mStateList);
	mAutomaton.setInitialState(&mSetUpState);
	mAutomaton.initialize();

}

Engine::~Engine(){
}

std::list<Shape*> Engine::shapeList() {
	return mShapeList;
}

Automaton & Engine::automaton() {
	return mAutomaton;
}

void Engine::startAutomaton(){
	ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
	reader.installFilter(new ConsoleKeyFilterUp);
	ConsoleKeyReader::KeyEvents keyEvents;
	mAutomaton.launchInitialState();
	while (true) {
		reader.read(keyEvents);
		mAutomaton.processTask(keyEvents);
	}
}

