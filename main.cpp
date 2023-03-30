#include <random>
#include <algorithm>
#include "HeaderFiles/CBinaryKnapsackProblem.h"
#include "HeaderFiles/BinaryMutations.h"
#include "HeaderFiles/BinaryCrossovers.h"
#include "HeaderFiles/Selections.h"
#include "HeaderFiles/CGeneticAlgorithm.h"


using namespace std;

void vRunExperiment(CGeneticAlgorithm &cGeneticAlgorithm) {

    int i_max_iterations = 3333;

    cGeneticAlgorithm.vRun(i_max_iterations);
    cGeneticAlgorithm.vPrintBestSolution();

}

void vRunBinaryKnapsackExperiment(mt19937 &cRandomEngine) {

    CBinaryKnapsackProblem c_problem;
//    c_problem.bLoadDataFromFile("../TestFiles/BinaryKnapsackProblemTest1.txt");
//    c_problem.bLoadDataFromFile("../TestFiles/BinaryKnapsackProblemTest2.txt");
    c_problem.bLoadDataFromFile("../TestFiles/BinaryKnapsackProblemTest3.txt");

    int i_population_size = 300;
//    float f_mutation_probability = 1.0f / c_problem.iGetSizeOfProblem();
    float f_mutation_probability = 0.1;
    float i_crossover_probability = 0.6;

    CBinaryOnePointCrossover c_binaryOnePointCrossover(cRandomEngine);
    CBinaryBitFlipMutation c_binaryBitFlipMutation(f_mutation_probability, cRandomEngine);
    CRouletteSelection c_rouletteSelection(cRandomEngine);

    CGeneticAlgorithm c_geneticAlgorithm(c_problem, c_binaryOnePointCrossover,
                                         c_binaryBitFlipMutation, c_rouletteSelection,
                                         cRandomEngine);
    c_geneticAlgorithm.bConfigure(i_population_size, i_crossover_probability);


    vRunExperiment(c_geneticAlgorithm);

}

/*
Seed be used to obtain a seed for the random number engine.
Uniform random bit engine objects act as sources of randomness.
Distribution objects produce random numbers.

#include <random>
random_device seed;
random_engine_type engine {seed};
distribution_type distribution {parameters,…};
auto random_value = distribution(engine);
 */
int main() {

    random_device c_seed_generator;
    auto seed = c_seed_generator();
    mt19937 c_random_engine(seed);

    vRunBinaryKnapsackExperiment(c_random_engine);

    return 0;
}