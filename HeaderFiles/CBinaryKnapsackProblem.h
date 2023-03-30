#ifndef GENETICALGORITHM_CBINARYKNAPSACKPROBLEM_H
#define GENETICALGORITHM_CBINARYKNAPSACKPROBLEM_H

#include "CIndividual.h"
#include "IProblem.h"
#include <vector>

using namespace std;

class CBinaryKnapsackProblem : public IProblem {

private:
    // Number of items
    int i_number_of_items;
    // Knapsack capacity
    int i_knapsack_capacity;
    // Item weights
    vector<int> vi_weight_of_items;
    // Item values
    vector<int> vi_values_of_items;

public:
    CBinaryKnapsackProblem() {
        i_number_of_items = 0;
        i_knapsack_capacity = 0;
    }

// Files format:
// i_number_of_items
// i_knapsack_capacity
// w_1 v_1
// w_2 v_2
// ...
// s_i_item_weight v_i_item_value
    bool bLoadDataFromFile(string sFileName) override;

    int iCalculateIndividualsFitness(CIndividual &cIndividual) override;

    int iCalculateGenotypeFitness(vector<int> &viGenotype) override;

    int iGetSizeOfProblem() override { return i_number_of_items; }

};


#endif //GENETICALGORITHM_CBINARYKNAPSACKPROBLEM_H
