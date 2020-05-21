/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// Simulator Header File


#ifndef ER_SIMULATOR_H_
#define ER_SIMULATOR_H_
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <ios>
#include <iomanip>
#include <vector>
#include "ER_queue.h"
#include "Doctor_queue.h"
#include "Nurse_queue.h"
#include "WaitRoom.h"
#include "Randomizer.h"
#include "Patient.h"
using std::vector;
using std::cout;
using std::endl;


/// Let's encapsulate our hiearchical class program in our own namespace called FinalProject
namespace FinalProject {

	class ER_Simulator {

	private:
		/// Member variables
		const int TOTAL_TICKS = 10080;		/// The total amount of minutes for this simulation
		int tick;							/// The current iteration that simulates a minute of time

		/// member variable pointers to our ER queues
		Doctor_queue * doctor_queue;
		Nurse_queue * nurse_queue;
		WaitRoom * waiting_queue;
		/// private member function
		int read_int(const std::string &prompt, int low, int high);

	public:

		/// No Arg Simulator Constructor
		ER_Simulator() {
			waiting_queue = new WaitRoom;
			nurse_queue = new Nurse_queue;
			doctor_queue = new Doctor_queue;
		}
		/// Copy Constructor
		ER_Simulator(const ER_Simulator& other) {
			tick = other.tick;
			waiting_queue = other.waiting_queue;
			doctor_queue = other.doctor_queue;
			nurse_queue = other.nurse_queue;
		}
		/// Destructor
		~ER_Simulator() {
			delete[] waiting_queue;
			delete[] nurse_queue;
			delete[] doctor_queue;
		}
		/// Assignment operator
		ER_Simulator & operator=(ER_Simulator & other) 
			{
				doctor_queue = new Doctor_queue(*other.doctor_queue);
				nurse_queue = new Nurse_queue(*other.nurse_queue);
				waiting_queue = new WaitRoom(*other.waiting_queue);

				return *this;
			}

		/// Member function prototypes
		void prompt_user();
		void simulate();
		void display();

	};

}

#endif // ER_SIMULATOR_H_