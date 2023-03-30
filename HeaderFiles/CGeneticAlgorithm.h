#ifndef GENETICALGORITHM_CGENETICALGORITHM_H
#define GENETICALGORITHM_CGENETICALGORITHM_H

#include "CIndividual.h"
#include "IProblem.h"
#include "CSelection.h"
#include "CMySmartPointer.h"
#include <random>
#include <iostream>

using namespace std;

class CGeneticAlgorithm {

protected:
    // Reference to the c_problem instance
    IProblem &c_problem;
    // Population size
    int i_population_size;
    // Population of individuals
    vector<CIndividual *> vpc_population;
    // CCrossover probability
    float f_crossover_probability;
    // RNG engine
    mt19937 &c_random_engine;
    // Best solution
    vector<int> vi_best_solution;
    int i_best_solution_value;

    ICrossover &c_crossover;
    IMutation &c_mutation;
    ISelection &c_selection;


public:

    CGeneticAlgorithm(IProblem &cProblem, ICrossover &cCrossover,
                      IMutation &cMutation, ISelection &cSelection, mt19937 &cRandomEngine)
            : c_problem(cProblem), c_crossover(cCrossover),
              c_mutation(cMutation), c_selection(cSelection), c_random_engine(cRandomEngine) {
        i_population_size = 0;
        f_crossover_probability = 0.0f;
    }

    virtual ~CGeneticAlgorithm() = default;


    // Method for configuring basic information
    bool bConfigure(int iPopulationSize, float fCrossoverProbability);

    // Method for running the Genetic Algorithm
    virtual void vRun(int iMaxIterations);

    virtual void vRunIteration();

    // Method for creating initial vpc_population
    virtual void vInitializePopulation();

    // Calculate the i_fitness of each individual and find best one
    virtual void vEvaluatePopulation();

    // Create new vpc_population and assign it as current vpc_population
    virtual void vCrossPopulation();

    // Mutate each individual in the new vpc_population with probability
    virtual void vMutatePopulation();

    // Method for vpc_population initialize
    virtual CIndividual *pcCreateIndividual();

    virtual void vPrintBestSolution();

    virtual vector<int> &viGetBestSolution() { return vi_best_solution; }

};


#endif //GENETICALGORITHM_CGENETICALGORITHM_H
