#include "../HeaderFiles/Selections.h"

CIndividual *CRouletteSelection::pcSelectIndividual(vector<CIndividual *> &vpcPopulation) {
    uniform_int_distribution<int> cDistribution(0, vpcPopulation.size() - 1);
    return vpcPopulation[cDistribution(c_random_engine)];
}

CIndividual *CTournamentSelection::pcSelectIndividual(vector<CIndividual *> &vpcPopulation) {
    uniform_int_distribution<int> cDistribution(0, vpcPopulation.size() - 1);
    vector<CIndividual *> vpcSelectedIndividuals;
    vpcSelectedIndividuals.reserve(i_kIndividuals);

    vpcSelectedIndividuals.push_back(vpcPopulation[cDistribution(c_random_engine)]);
    CIndividual *pcBestIndividual = vpcSelectedIndividuals[0];
    for (int i = 1; i < i_kIndividuals; ++i) {
        vpcSelectedIndividuals.push_back(vpcPopulation[cDistribution(c_random_engine)]);
        if (vpcSelectedIndividuals[i]->iGetFitness() > pcBestIndividual->iGetFitness()) {
            pcBestIndividual = vpcSelectedIndividuals[i];
        }
    }
    return pcBestIndividual;
}
