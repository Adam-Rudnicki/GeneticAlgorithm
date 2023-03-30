#ifndef GENETICALGORITHM_SELECTIONS_H
#define GENETICALGORITHM_SELECTIONS_H


#include "CSelection.h"

class CRouletteSelection : public CSelection {

public:

    CRouletteSelection(mt19937 &cRandomEngine) : CSelection(cRandomEngine) {}

    CIndividual *pcSelectIndividual(vector<CIndividual *> &vpcPopulation) override;

};

class CTournamentSelection : public CSelection {

private:

    int i_kIndividuals;

public:

    CTournamentSelection(mt19937 &cRandomEngine, int iKIndividuals) : CSelection(cRandomEngine) {
        i_kIndividuals = iKIndividuals;
    }

    CIndividual *pcSelectIndividual(vector<CIndividual *> &vpcPopulation) override;

};


#endif //GENETICALGORITHM_SELECTIONS_H
