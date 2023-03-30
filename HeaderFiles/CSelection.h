#ifndef GENETICALGORITHM_CSELECTION_H
#define GENETICALGORITHM_CSELECTION_H


#include "CIndividual.h"
#include "CMySmartPointer.h"
#include <random>


class ISelection {

public:
    virtual CIndividual *pcSelectIndividual(vector<CIndividual *> &vpcPopulation) = 0;

};

class CSelection : public ISelection {

protected:
    mt19937 &c_random_engine;

public:
    CSelection(mt19937 &cRandomEngine) : c_random_engine(cRandomEngine) {}

};


#endif //GENETICALGORITHM_CSELECTION_H
