#ifndef GENETICALGORITHM_CINDIVIDUAL_H
#define GENETICALGORITHM_CINDIVIDUAL_H

#include <vector>
#include "CMutation.h"
#include "CCrossover.h"
#include "IProblem.h"

using namespace std;

class ICrossover;

class IMutation;

class IProblem;

class CIndividual {

protected:
    // Reference to the c_problem instance
    IProblem &c_problem;
    // Fitness
    int i_fitness;
    // Genotype
    vector<int> *pi_genotype;
    // Used to check whether i_fitness was calculated
    bool b_is_evaluated;
    // CCrossover interface
    ICrossover &c_crossover;
    // CMutation interface
    IMutation &c_mutation;

public:
    // Constructor
    CIndividual(vector<int> *viGenotype, IProblem &cProblem, ICrossover &cCrossover, IMutation &cMutation)
            : pi_genotype(
            viGenotype), c_problem(cProblem), c_crossover(cCrossover), c_mutation(cMutation) {
        b_is_evaluated = false;
    }

    // Copy Constructor
    CIndividual(const CIndividual &cOther) : c_problem(cOther.c_problem), c_crossover(cOther.c_crossover),
                                             c_mutation(cOther.c_mutation) {
        pi_genotype = new vector<int>(*(cOther.pi_genotype));
        i_fitness = cOther.i_fitness;
        b_is_evaluated = cOther.b_is_evaluated;
    }

    virtual ~CIndividual() {
        delete pi_genotype;
    }


    // Method for calculating the i_fitness of the individual
    virtual int iCalculateFitness();

    // Method for mutating the individual
    virtual bool bMutate();

    // Method for c_crossover with another individual and returning the resulting children
    virtual vector<CIndividual *> vpcCross(CIndividual &cPartner);


    // Method for obtaining the value of gene at given iIndex
    virtual int iGetGeneAtIndex(int iIndex) { return (*pi_genotype)[iIndex]; }

    // Method for setting the iValue of gene at given iIndex
    virtual void vSetGeneAtIndex(int iIndex, int iValue) { (*pi_genotype)[iIndex] = iValue; }

    virtual vector<int> &viGetGenotype() { return *pi_genotype; }

    virtual int iGetFitness() { return i_fitness; }

    virtual void vSetIsEvaluated(bool bIsEvaluated) { b_is_evaluated = bIsEvaluated; }

};


#endif //GENETICALGORITHM_CINDIVIDUAL_H
