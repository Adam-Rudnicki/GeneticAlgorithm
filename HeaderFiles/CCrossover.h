#ifndef GENETICALGORITHM_CCROSSOVER_H
#define GENETICALGORITHM_CCROSSOVER_H

#include <vector>
#include <random>
#include "CIndividual.h"

using namespace std;

class CIndividual;

class ICrossover {

public:
    virtual ~ICrossover() = default;

    // Method for c_crossover with another individual and returning the resulting children
    virtual vector<CIndividual *>
    vpcCrossIndividuals(CIndividual &cParent1, CIndividual &cParent2, CIndividual &cChild1, CIndividual &cChild2) = 0;

};

class CCrossover : public ICrossover {

protected:
    mt19937 &c_random_engine;

public:
    CCrossover(mt19937 &cRandomEngine) : c_random_engine(cRandomEngine) {}

};

#endif //GENETICALGORITHM_CCROSSOVER_H
