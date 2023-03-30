#ifndef GENETICALGORITHM_BINARYMUTATIONS_H
#define GENETICALGORITHM_BINARYMUTATIONS_H

#include "CMutation.h"

class CBinaryBitFlipMutation : public CMutation {

public:

    CBinaryBitFlipMutation(float fMutationProbability, mt19937 &cRandomEngine) : CMutation(fMutationProbability,
                                                                                           cRandomEngine) {};

    bool bMutateIndividual(CIndividual &cIndividual) override;

};

class CInversionMutation : public CMutation {

public:

    CInversionMutation(float fMutationProbability, mt19937 &cRandomEngine) : CMutation(fMutationProbability,
                                                                                       cRandomEngine) {};

    bool bMutateIndividual(CIndividual &cIndividual) override;

};


#endif //GENETICALGORITHM_BINARYMUTATIONS_H
