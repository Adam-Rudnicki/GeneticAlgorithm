#ifndef GENETICALGORITHM_CMUTATION_H
#define GENETICALGORITHM_CMUTATION_H

#include "CIndividual.h"
#include <random>

using namespace std;

class CIndividual;

class IMutation {

public:
    virtual ~IMutation() = default;

    // Method for mutating cIndividual's pi_genotype
    virtual bool bMutateIndividual(CIndividual &cIndividual) = 0;

    virtual float fGetProbability() = 0;

    virtual void vSetProbability(float fMutationProbability) = 0;

};

class CMutation : public IMutation {

protected:
    mt19937 &c_random_engine;
    float f_mutation_probability;

public:
    CMutation(float fMutationProbability, mt19937 &cRandomEngine) : f_mutation_probability(fMutationProbability),
                                                                    c_random_engine(cRandomEngine) {}

    float fGetProbability() override { return f_mutation_probability; }

    void vSetProbability(float fMutationProbability) override { f_mutation_probability = fMutationProbability; }

};

#endif //GENETICALGORITHM_CMUTATION_H
