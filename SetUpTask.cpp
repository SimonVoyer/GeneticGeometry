//entête
#include "SetUpTask.h"
#include "Automaton.h"
#include <iostream>
#include "Solution.h"

void SetUpTask::process(ConsoleKeyReader::KeyEvents keyList) {
	process();
}

void SetUpTask::process() {

	//initialisation des paramètres
	parameters currentParameters;
	std::cout << "\nEnter the desired layout height: \n";
	std::cin >> currentParameters.layoutHeight;
	std::cout << "\nEnter the desired layout length: \n";
	std::cin >> currentParameters.layoutLength;
	std::cout << "\nEnter the desired number of obstacles: \n";
	std::cin >> currentParameters.nbOfObstacles;
	std::cout << "\nEnter the desired odds of mutation: \n";
	std::cin >> currentParameters.oddsOfMutation;
	std::cout << "\nEnter the desired number of elites: \n";
	std::cin >> currentParameters.nbOfElites;
	std::cout << "\nEnter the desired population size: \n";
	std::cin >> currentParameters.populationSize;
	std::cout << "\nEnter the desired number of populations: \n";
	std::cin >> currentParameters.nbOfPopulations;
	currentParameters.currentIteration = 0 ;
	std::cout << "\nEnter the maximum number of iterations: \n";
	std::cin >> currentParameters.maxNbOfIterations;
	currentParameters.color1 = "red";
	currentParameters.color2 = "blue";
	currentParameters.color3 = "green";
	currentParameters.color4 = "yellow";

	//on set les paramètres au niveau de l'automaton
	automatonPointer()->setCurrentParameters(currentParameters);
	automatonPointer()->civilization().populationEngineVector().resize(currentParameters.nbOfPopulations);

	for (int i{ 0 }; i < currentParameters.nbOfPopulations; ++i) {
		generateInitialSolutions(currentParameters, automatonPointer()->civilization().populationEngineVector().at(i).parentPopulation());
		automatonPointer()->civilization().populationEngineVector().at(i).setParameters(currentParameters);
	}

	automatonPointer()->civilization().initializeObstacles(currentParameters);

	//section tests --------------------------------------------

	//testPrintParentCircles(); //	semble bien fonctionné
	//testMutation(); //	semble bien fonctionné
	//testParentChoice(); //	semble bien fonctionné
	//testChildGeneration(); //	semble bien fonctionné
	//testGenerateNewGeneration(); //	semble bien fonctionné
	//testMultipleGenerations(); //	semble bien fonctionné
	//-----------------------------------------------------------
}

void SetUpTask::render() {
	std::cout << "\nSetUp rendering.";
}


void SetUpTask::generateInitialSolutions(parameters currentParameters, Population & population) {
	population.solutionVector().resize(currentParameters.populationSize);
	for (int i{ 0 }; i < currentParameters.populationSize; ++i) {
		int radius = RandomTools::randomValue(1, currentParameters.layoutHeight /2); //minimum 1 et max layout /2
		int x = RandomTools::randomValue(radius, currentParameters.layoutLength - radius); //minimum du rayon et maximum layout - rayon
		int y = RandomTools::randomValue(radius, currentParameters.layoutHeight - radius);
		Point2d point = Point2d(x, y);
		Circle * circle = new Circle(point, radius);
		//Solution solution = new Solution(circle);
		//solution->calculateFitness();
		population.solutionVector().at(i).setShape(circle);
	}
}



//méthodes de test -----------------------------------------------------------------------------------------

void SetUpTask::testPrintParentCircles() {
	for (auto & populationEngine : automatonPointer()->civilization().populationEngineVector()) {
		for (auto & solution : populationEngine.parentPopulation().solutionVector()) {
			Circle * circle = static_cast<Circle*>(solution.shape());
			std::cout << "\ncircle radius: " << circle->radius();
			std::cout << "\tcircle x: " << circle->point().x();
			std::cout << "\tcircle y: " << circle->point().y();
			//solution.calculateFitness(); //ne crash plus
			std::cout << "\tsolution fitness: " << solution.fitness();
		}
		
	}
}

void SetUpTask::testPrintChildCircles() {
	for (auto populationEngine : automatonPointer()->civilization().populationEngineVector()) {
		for (auto solution : populationEngine.childPopulation().solutionVector()) {
			Circle * circle = static_cast<Circle*>(solution.shape());
			std::cout << "\ncircle radius: " << circle->radius();
			std::cout << "\tcircle x: " << circle->point().x();
			std::cout << "\tcircle y: " << circle->point().y();
			std::cout << "\tsolution fitness: " << solution.fitness();
		}

	}
}

void SetUpTask::testMutation() {
	Solution solution = automatonPointer()->civilization().populationEngineVector().at(0).parentPopulation().solutionVector().at(0);
	//solution.mutate();
	Circle * circle = static_cast<Circle*>(solution.decodeShape(solution.gene(), solution.shape()));
	std::cout << "\n---------------------------------------";
	std::cout << "\nTest mutation:";
	std::cout << "\ncircle radius: " << circle->radius();
	std::cout << "\ncircle x: " << circle->point().x();
	std::cout << "\ncircle y: " << circle->point().y();
	std::cout << "\nsolution fitness: " << solution.fitness();
	std::cout << "\n---------------------------------------";
}

void SetUpTask::testParentChoice(){
	PopulationEngine populationEngine = automatonPointer()->civilization().populationEngineVector().at(0);
	//populationEngine.calculateFitness();
	Solution solution = populationEngine.selectParent();
}

void SetUpTask::testChildGeneration(){
	PopulationEngine populationEngine = automatonPointer()->civilization().populationEngineVector().at(0);
	//populationEngine.calculateFitness();
	//populationEngine.generateChild();
}

void SetUpTask::testGenerateNewGeneration() {
	testPrintParentCircles();
	PopulationEngine populationEngine = automatonPointer()->civilization().populationEngineVector().at(0);
	populationEngine.newGeneration();
	testPrintChildCircles();
}

void SetUpTask::testMultipleGenerations() {
	
	for (int i{ 0 }; i < 100000; ++i) {
		automatonPointer()->civilization().populationEngineVector().at(0).newGeneration();
	}
}


