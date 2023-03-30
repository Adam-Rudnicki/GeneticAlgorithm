#include <algorithm>
#include "../HeaderFiles/BinaryMutations.h"

bool CBinaryBitFlipMutation::bMutateIndividual(CIndividual &cIndividual) {
    bool b_successful_mutation = false;
    //This cDistribution produces random real number in a range [a,b] where each possible value has an equal likelihood of being produced.
    uniform_real_distribution<float> cDistribution(0, 1);

    vector<int> &vi_genotype = cIndividual.viGetGenotype();
    int i_genotype_size = vi_genotype.size();

    for (int i = 0; i < i_genotype_size; ++i) {
        if (f_mutation_probability < cDistribution(c_random_engine)) {
            vi_genotype[i] = vi_genotype[i] == 0 ? 1 : 0;
            b_successful_mutation = true;
        }
    }

    if (b_successful_mutation) cIndividual.vSetIsEvaluated(false);

    return b_successful_mutation;
}

bool CInversionMutation::bMutateIndividual(CIndividual &cIndividual) {
    bool b_successful_mutation = false;
    //This cDistribution produces random integer number in a range [a,b] where each possible value has an equal likelihood of being produced.
    uniform_real_distribution<float> cDistribution(0, 1);

    //Mutate subset of genes if 0, otherwise continue
    if (cDistribution(c_random_engine) < f_mutation_probability) {
        b_successful_mutation = true;
        vector<int> &vi_genotype = cIndividual.viGetGenotype();
        int i_genotype_size = vi_genotype.size();

        uniform_int_distribution<int> cDist(0, i_genotype_size - 1);
        int a = cDist(c_random_engine);
        cDist = uniform_int_distribution<int>(a, i_genotype_size - 1);
        int b = cDist(c_random_engine);
        std::shuffle(std::begin(vi_genotype) + a, std::begin(vi_genotype) + b, c_random_engine);
    }

    if (b_successful_mutation) cIndividual.vSetIsEvaluated(false);

    return b_successful_mutation;
}
