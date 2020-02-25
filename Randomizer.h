/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// Random number generator class header file

/// Class to encapsulate the generation of random numbers
#ifndef RANDOMIZER_H_
#define RANDOMIZER_H_

#include <cstdlib>
#include <ctime>

/// Let's encapsulate our hiearchical class program in our own namespace called FinalProject
namespace FinalProject {

	class Randomizer {
	private:

	public:
		/// No Arg constructor that uses the time as a seed for its randomly generated numbers
		Randomizer() { srand((unsigned int)std::time(0)); }

		/// Constructor that takes a specified integer seed as an argument and seeds the random number generator
		Randomizer(int seed) { srand(seed);	}

		///  Member function prototypes-these functions help us generate the random numbers we will need for our simulation
		int randomized_int(int n);
		/// Overloaded function to randomly generate a number between 0 & 1999
		int randomized_int();
		/// Return a random number between 0 & 999 which will allow us to randomly assign a last name
		int randomized_last_name_int();
		/// Return a random decimal value
		double randomized_double();
		/// My clever little function for assigning a priority number based off of 70%/20%/10% probability
		int random_priority_number();

	};

}

#endif // RANDOMIZER_H_