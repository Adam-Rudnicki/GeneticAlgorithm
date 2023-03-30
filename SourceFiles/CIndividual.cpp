#include "../HeaderFiles/CIndividual.h"

int CIndividual::iCalculateFitness() {
    if (!b_is_evaluated) {
        i_fitness = c_problem.iCalculateIndividualsFitness(*this);
        b_is_evaluated = true;
    }
    return i_fitness;
}

bool CIndividual::bMutate() {
    return c_mutation.bMutateIndividual(*this);
}

vector<CIndividual *> CIndividual::vpcCross(CIndividual &cPartner) {
    auto *c_child1 = new CIndividual(*this);
    auto *c_child2 = new CIndividual(cPartner);

    return c_crossover.vpcCrossIndividuals(*this, cPartner, *c_child1, *c_child2);
}

