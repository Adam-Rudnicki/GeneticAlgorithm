
#include "../HeaderFiles/BinaryCrossovers.h"

vector<CIndividual *>
CBinaryOnePointCrossover::vpcCrossIndividuals(CIndividual &cParent1, CIndividual &cParent2, CIndividual &cChild1,
                                              CIndividual &cChild2) {
    int i_genotype_size = cParent1.viGetGenotype().size();
    //This cDistribution produces random integers in a range [a,b] where each possible value has an equal likelihood of being produced.
    uniform_int_distribution<int> cDistribution(0, i_genotype_size - 1);
    int i_pivot = cDistribution(c_random_engine);

    if (i_genotype_size - i_pivot < i_pivot) {
        for (int i = i_pivot; i < i_genotype_size; ++i) {
            cChild1.vSetGeneAtIndex(i, cParent2.iGetGeneAtIndex(i));
            cChild2.vSetGeneAtIndex(i, cParent1.iGetGeneAtIndex(i));
        }
    } else {
        for (int i = 0; i < i_pivot; ++i) {
            cChild1.vSetGeneAtIndex(i, cParent2.iGetGeneAtIndex(i));
            cChild2.vSetGeneAtIndex(i, cParent1.iGetGeneAtIndex(i));
        }
    }

    vector<CIndividual *> vpc_children{&cChild1, &cChild2};

    return vpc_children;
}

vector<CIndividual *>
CBinaryUniformCrossover::vpcCrossIndividuals(CIndividual &cParent1, CIndividual &cParent2, CIndividual &cChild1,
                                             CIndividual &cChild2) {
    int i_genotype_size = cParent1.viGetGenotype().size();
    //This cDistribution produces random integers in a range [a,b] where each possible value has an equal likelihood of being produced.
    uniform_int_distribution<int> cDistribution(0, 1);
    //When 0 then swap genes, otherwise continue
    for (int i = 0; i < i_genotype_size; ++i) {
        if (cDistribution(c_random_engine) == 0) {
            cChild1.vSetGeneAtIndex(i, cParent2.iGetGeneAtIndex(i));
            cChild2.vSetGeneAtIndex(i, cParent1.iGetGeneAtIndex(i));
        }
    }

    vector<CIndividual *> vpc_children{&cChild1, &cChild2};

    return vpc_children;
}
