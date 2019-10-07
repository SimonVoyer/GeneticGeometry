#ifndef SET_UP_TASK_H
#define SET_UP_TASK_H

#include "Task.h"
#include "Parameters.h"
#include "Circle.h"
#include "PopulationEngine.h"

class SetUpTask : public Task {
	void process(ConsoleKeyReader::KeyEvents keyList) override;
	void process() override;
	void render() override;
	void generateInitialSolutions(parameters currentParameters, Population & population);

	//méthodes de test
	void testPrintParentCircles();
	void testPrintChildCircles();
	void testMutation();
	void testParentChoice();
	void testChildGeneration();
	void testGenerateNewGeneration();
	void testMultipleGenerations();
};


#endif // !SET_UP_TASK_H
