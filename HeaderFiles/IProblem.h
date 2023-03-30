#ifndef GENETICALGORITHM_IPROBLEM_H
#define GENETICALGORITHM_IPROBLEM_H


#include "CIndividual.h"

class CIndividual;

class IProblem {

public:
    virtual ~IProblem() = default;


    // Method for loading data relating to the c_problem class
    virtual bool bLoadDataFromFile(string sFileName) = 0;

    // Method for calculating the i_fitness of cIndividual
    virtual int iCalculateIndividualsFitness(CIndividual &cIndividual) = 0;

    // Method for calculating the i_fitness of a solution represented by a given pi_genotype
    virtual int iCalculateGenotypeFitness(vector<int> &viGenotype) = 0;

    virtual int iGetSizeOfProblem() = 0;

};


#endif //GENETICALGORITHM_IPROBLEM_H
