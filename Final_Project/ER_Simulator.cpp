/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// Simulator Implementation File

#include "ER_Simulator.h"

namespace FinalProject {

	Randomizer ER_random;

	/// Implementation of the read_int member function
	/// This function takes in a string as a prompt message for the user, an integer representing the low end, and an integer representing the high end
	/// This function returns an integer representing the user's choice
	/// This function prompts the user to make a number choice somewhere between the low end and the high end
	int FinalProject::ER_Simulator::read_int(const std::string & prompt, int low, int high)
		{
			{
				if (low >= high) // invalid range
					throw std::invalid_argument("invalid range specified");

				std::cin.exceptions(std::ios_base::failbit);
				int num = 0;
				while (true) {
					try {
						while (true) {
							std::cout << prompt;
							std::cin >> num;
							if (num >= low && num <= high) { // within the specified range
								std::cout << std::endl;
								return num;
							}
						}
					}
					catch (std::ios_base::failure) {
						std::cout << "Bad numeric string -- try again\n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<int>::max(), '\n');
					}
				}
			}
		}

	/// Implementatino of the prompt_user member function
	/// No Arg function that returns void
	/// This function prompts the user to input how many patients will arrive per hour for our simulation,
	/// how many doctors will be on staff in the ER, and how many nurses will be on staff in the ER
	void ER_Simulator::prompt_user()
		{
			std::cout << "Today we will be simulating a hospital emergency room.\n";
			std::cout << "We will begin by getting a couple pieces of information from you.\n";
			std::cout << "Let's begin...\n";

			/// Declare and initialize a variable to hold the user inputted average patients per hour entering the ER
			int av_pat_per_hour = read_int("Please enter how many sick patients you want to enter the emergency room per hour: ", 1, 60);
			/// Convert the integer value of patients per hour into a double value by dividing by 60 minutes
			double arrival_rate = (av_pat_per_hour / 60.0);

			/// Declare and initialize an integer value to hold the user inputted amount of doctors the ER will have on staff
			int amount_of_docs = read_int("Please enter how many doctors you want to be working in the ER: ", 1, 5);
			/// Declare and initialize an integer value to hold the user inputted amount of nurses the ER will have on staff
			int amount_of_nurses = read_int("Now enter how many nurses you want to be working in the ER: ", 1, 8);

			/// Now that we know the average rate of ER patient arrival, let's set it
			waiting_queue->setArrivalRate(arrival_rate);

			/// Now that we know how many doctors are working in the ER for the simulation, let's set that number
			doctor_queue->setDocs(amount_of_docs);

			/// Now that we know how many nurses are working in the ER for the simulation, let's set that number
			nurse_queue->setNurses(amount_of_nurses);

			/// Now let's set our Doctor and Nurse class WaitRoom pointers to point to the correct object
			doctor_queue->setWait(waiting_queue);
			nurse_queue->setWait(waiting_queue);
		}

	/// Member function for initiating the emergency room 1 week simulation
	/// Function takes no arguments and returns void
	/// This function initializesa for loop that runs a series of iterations representing minutes in time at an emergency room
	/// Each minute (clock tick) provokes an update of the pertinent emergency room activities
	void ER_Simulator::simulate()
		{
			for (tick = 0; tick < TOTAL_TICKS; ++tick)
			{
				/// each iteration of time initiates updates...
				waiting_queue->clock(tick);
				doctor_queue->clock(tick);
				nurse_queue->clock(tick);
			}
		}

	/// Member function for displaying the hospital records upon completion of the simulation
	/// No Arg function returns void
	/// This function will send the console an overview of the results of the simulation
	void ER_Simulator::display()
		{
		int total_patients = waiting_queue->patients.size();
		int holder = 0;
		for (int i = 0; i < waiting_queue->patients.size(); i++) {
			holder += (waiting_queue->patients[i]->getTotalService());
		}
			std::cout << "Well, it was a great week at the CS273 Emergency Room!\n";
			std::cout << "Throughout the full week at the hospital, there was " << doctor_queue->getDocs() << "doctors on the clock and " << nurse_queue->getNurses() << "nurses.\n";
			std::cout << "The nurses served " << nurse_queue->getPatientsServed() << "patients and the doctors served\n";
			std::cout << doctor_queue->getPatientsServed() << "patients for a grand total of " << (nurse_queue->getPatientsServed() + doctor_queue->getPatientsServed()) << "patients.\n";
			std::cout << "\n";
			std::cout << "And in the end the average time spent by the emergency room patients from the time they checked \n";
			std::cout << "into the waiting room until they received full treatment and were discharged was: \n";
			std::cout << "\n";
			std::cout << total_patients / holder << endl;

		}

}
