Genetic Algorithm Skeleton for Solving Knapsack Problem
This is a C++ implementation of a genetic algorithm for solving the Knapsack problem. This implementation includes two types of mutation of genotype, two types of selection from population, and two types of crossover.

The knapsack problem is the following problem in combinatorial optimization:
Given a set of items, each with a weight and a value, determine which items to include in the collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.

Usage
To use this implementation using input file, provide the following format:

<number of items>
<knapsack capacity>
<weight of item 1> <value of item 1>
<weight of item 2> <value of item 2>
...
<weight of item n> <value of item n>

For example:
4 10
2 6
3 8
4 9
5 11

Mutation methods implemented:
BitFlipMutation
InversionMutation

Crossover methods implemented:
OnePointCrossover
UniformCrossover

Selection methods implemented:
RouletteSelection
TournamentSelection
