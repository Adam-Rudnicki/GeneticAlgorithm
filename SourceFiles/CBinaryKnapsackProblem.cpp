#include <fstream>
#include "../HeaderFiles/CBinaryKnapsackProblem.h"


bool CBinaryKnapsackProblem::bLoadDataFromFile(string sFileName) {
    ifstream file(sFileName);
    if (!file.is_open()) return false;
    file >> i_number_of_items;
    if (i_number_of_items <= 0) return false;
    file >> i_knapsack_capacity;

    vi_weight_of_items.resize(i_number_of_items);
    vi_values_of_items.resize(i_number_of_items);
    for (int i = 0; i < i_number_of_items; i++) {
        file >> vi_weight_of_items[i] >> vi_values_of_items[i];
    }
    file.close();

    return true;
}

int CBinaryKnapsackProblem::iCalculateIndividualsFitness(CIndividual &cIndividual) {
    return iCalculateGenotypeFitness(cIndividual.viGetGenotype());
}

int CBinaryKnapsackProblem::iCalculateGenotypeFitness(vector<int> &viGenotype) {
    int i_value = 0;
    int i_weight = 0;
    for (int i = 0; i < i_number_of_items; ++i) {
        if (viGenotype[i] == 1) {
            i_weight += vi_weight_of_items[i];
            if (i_weight > i_knapsack_capacity) return 0;
            i_value += vi_values_of_items[i];
        }
    }
    return i_value;
}
