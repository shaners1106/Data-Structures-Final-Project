/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// Random number generator class implementation file

#include "Randomizer.h"
namespace FinalProject {

	/// Function that takes in an integer argument (n) and returns a random number between 0 & n
	int FinalProject::Randomizer::randomized_int(int n) { return int(randomized_double() * n); }

	/// Function that returns a random number between 0 & 1999 for distributing random 1st names for our patients
	int Randomizer::randomized_int()
	{
		return rand() % 2000;
	}

	/// Function that returns a random number between 0 & 999 for distributing random last names for our patients
	int Randomizer::randomized_last_name_int() { return rand() % 1000; }

	/// No Arg function that returns a random number between 0 & 1
	double Randomizer::randomized_double() { return double(rand()) / RAND_MAX;	}

	/// Let's create a function that will allow us to randomly assign our patient objects a priority number between 1 & 20
	/// based off of the probabilities outlined in the Final Project Specs
	int Randomizer::random_priority_number()
	{
		/// Randomly capture a number between 1 & 10
		int val = rand() % 10 + 1;
		/// Declare a variable that will allow us to return the random number (1-20)
		int random;
		/// If the random value is 1-7, this represents our 70% likelihood category, 
		/// so we need to allow this option to generate & return a 1-10 priority number
		if (val < 8) {
			random = 1 + rand() % 11;		/// Captures a number between 1 & 10 (all with equal probability)
			return random;					/// Returns that number
		}
		/// If our randomly generated number between 1 & 10 is 8 or 9, this represents our 20% likelihood 
		/// category, so we need to allow this option to generate & return a 11-15 priority number
		else if ((val == 8) || (val == 9)) {
			random = rand() % 5 + 11;		/// Captures a random number between 11 & 15 (with equal probability)
			return random;					/// Returns this number
		}
		/// The only other option of our randomly generated val is for it to be 10
		/// This represents our 10% likelihood category, in which case we need to randomly generate 
		/// a 16-20 priority number and return it
		else {
			random = rand() % 5 + 16;		/// Captures a random number between 16 & 20 (with equal probability)
			return random;					/// Returns this number
		}
	}

}