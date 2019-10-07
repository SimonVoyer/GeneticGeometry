#ifndef TASK_H
#define TASK_H
#include "Point2d.h"
#include "Console.h"
class Automaton;

class Task
{
public:
	Task();
	~Task();
	Automaton * automatonPointer();
	void setAutomatonPointer(Automaton * automatonPointer);
	virtual void process(ConsoleKeyReader::KeyEvents keyList);
	virtual void process();
	virtual void render();

protected: 
	Automaton * mAutomatonPointer;
};

#endif //!TASK_H