#ifndef GENETICALGORITHM_BINARYCROSSOVERS_H
#define GENETICALGORITHM_BINARYCROSSOVERS_H


#include <vector>
#include <random>
#include "CCrossover.h"

using namespace std;

class CBinaryOnePointCrossover : public CCrossover {

public:
    CBinaryOnePointCrossover(mt19937 &cRandomEngine) : CCrossover(cRandomEngine) {};

    vector<CIndividual *> vpcCrossIndividuals(CIndividual &cParent1, CIndividual &cParent2, CIndividual &cChild1,
                                              CIndividual &cChild2) override;
};

class CBinaryUniformCrossover : public CCrossover {

public:
    CBinaryUniformCrossover(mt19937 &cRandomEngine) : CCrossover(cRandomEngine) {};

    vector<CIndividual *> vpcCrossIndividuals(CIndividual &cParent1, CIndividual &cParent2, CIndividual &cChild1,
                                              CIndividual &cChild2) override;
};

#endif //GENETICALGORITHM_BINARYCROSSOVERS_H