#include "../HeaderFiles/CGeneticAlgorithm.h"

bool CGeneticAlgorithm::bConfigure(int iPopulationSize, float fCrossoverProbability) {
    if (iPopulationSize < 1) return false;
    i_population_size = iPopulationSize;
    f_crossover_probability = fCrossoverProbability;
    return true;
}


void CGeneticAlgorithm::vRun(int iMaxIterations) {
    vInitializePopulation();
    for (int i = 0; i < iMaxIterations; i++) {
        vRunIteration();
    }

}

void CGeneticAlgorithm::vRunIteration() {
    vCrossPopulation();
    vMutatePopulation();
    vEvaluatePopulation();
}

void CGeneticAlgorithm::vInitializePopulation() {
    vpc_population.resize(i_population_size);

    for (int i = 0; i < i_population_size; i++) {
        vpc_population[i] = pcCreateIndividual();
    }

    vEvaluatePopulation();
    vi_best_solution = vpc_population[0]->viGetGenotype();
    i_best_solution_value = vpc_population[0]->iCalculateFitness();
}

void CGeneticAlgorithm::vEvaluatePopulation() {

    for (int i = 0; i < i_population_size; i++) {
        vpc_population[i]->iCalculateFitness();
        if (vpc_population[i]->iGetFitness() > i_best_solution_value) {
            vi_best_solution = vpc_population[i]->viGetGenotype();
            i_best_solution_value = vpc_population[i]->iGetFitness();
        }
    }
}

void CGeneticAlgorithm::vCrossPopulation() {
    uniform_real_distribution<float> cProbabilityDistribution(0, 1);

    // Create new vpc_population
    vector<CIndividual *> vpc_newPopulation;
    vpc_newPopulation.reserve(i_population_size);

    while (vpc_newPopulation.size() < vpc_population.size()) { //todo odd number vpc_population 333
        // Select two individuals from the vpc_population
        CIndividual *pc_individual1 = c_selection.pcSelectIndividual(vpc_population);
        CIndividual *pc_individual2 = c_selection.pcSelectIndividual(vpc_population);
        // CCrossover with probability
        if (cProbabilityDistribution(c_random_engine) < f_crossover_probability) {
            vector<CIndividual *> vpc_children = pc_individual1->vpcCross(*pc_individual2);

            vpc_newPopulation.push_back(vpc_children[0]);
            vpc_newPopulation.push_back(vpc_children[1]);
        } else {
            vpc_newPopulation.push_back(new CIndividual(*pc_individual1));
            vpc_newPopulation.push_back(new CIndividual(*pc_individual2));
        }
    }

    // Delete current vpc_population
    for (int i = 0; i < i_population_size; ++i) {
        delete vpc_population[i];
    }

    // Replace the current vpc_population with the new vpc_population
    vpc_population = vpc_newPopulation;
}

void CGeneticAlgorithm::vMutatePopulation() {
    for (int i = 0; i < i_population_size; i++) {
        vpc_population[i]->bMutate();
    }
}

CIndividual *CGeneticAlgorithm::pcCreateIndividual() {
    uniform_int_distribution<int> cDistribution(0, 1);

    auto *vi_genotype = new vector<int>;
    int genotype_size = c_problem.iGetSizeOfProblem();
    vi_genotype->resize(genotype_size);

    for (int i = 0; i < genotype_size; ++i) {
        (*vi_genotype)[i] = cDistribution(c_random_engine);
    }

    return new CIndividual(vi_genotype, c_problem, c_crossover, c_mutation);
}

void CGeneticAlgorithm::vPrintBestSolution() {
    cout << "Best result" << endl;
    cout << "Genotype = ";
    for (int i: vi_best_solution) {
        cout << i;
    }
    cout << endl;
    cout << "Fitness = " << i_best_solution_value << endl;
}


