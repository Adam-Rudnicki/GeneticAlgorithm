cmake_minimum_required(VERSION 3.24)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(GeneticAlgorithm main.cpp SourceFiles/CBinaryKnapsackProblem.cpp HeaderFiles/CBinaryKnapsackProblem.h SourceFiles/CGeneticAlgorithm.cpp HeaderFiles/CGeneticAlgorithm.h HeaderFiles/BinaryCrossovers.h SourceFiles/BinaryCrossovers.cpp HeaderFiles/CMutation.h SourceFiles/BinaryMutations.cpp HeaderFiles/BinaryMutations.h HeaderFiles/CIndividual.h HeaderFiles/CCrossover.h HeaderFiles/IProblem.h HeaderFiles/CSelection.h SourceFiles/Selections.cpp HeaderFiles/Selections.h HeaderFiles/CMySmartPointer.h SourceFiles/CIndividual.cpp)
