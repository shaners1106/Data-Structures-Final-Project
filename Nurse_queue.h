/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// Nurse's queue header file


#ifndef NURSE_QUEUE_H_
#define NURSE_QUEUE_H_
#include "ER_queue.h"
#include "Randomizer.h"
#include "WaitRoom.h"
#include "Patient.h"
#include <algorithm>
#include <iterator>
#include <list>
#include <queue>
using std::priority_queue;
using std::list;
using std::iterator;

/// Let's encapsulate our hiearchical class program in our own namespace called FinalProject
namespace FinalProject {

	extern Randomizer ER_random;

	class Nurse_queue : public ER_queue {

	private:
		
		/// Member variables

		size_t amount_of_nurses;			/// How many doctors working in the ER
		int patients_served;				/// How many patients the doctors have served throughout this simulation
		list<Patient *> nurse_queue;		/// Queue holding the patients currently being seen by doctors
		WaitRoom * waiting_queue;			/// Pointer to reference our waiting room queue

	public:
		/// No Arg constructor
		Nurse_queue() {}
		/// Copy constructor
		Nurse_queue(const Nurse_queue & other) {
			amount_of_nurses = other.amount_of_nurses;
			patients_served = other.patients_served;
			nurse_queue = other.nurse_queue;
			waiting_queue = other.waiting_queue;
		}
		/// Destructor
		~Nurse_queue() { delete[] waiting_queue; }
		/// Assignment operator
		Nurse_queue & operator= (Nurse_queue& other) {
			waiting_queue = new WaitRoom(*other.waiting_queue);
			return *this;
		}

		/// Mutator and Accessor member function prototypes

		void setNurses(int nurses);
		void setWait(WaitRoom * waiting_queue);
		int getNurses();
		int getPatientsServed();

		/// Nurse queue update member function prototype
		void clock(int tick);

	};

}

#endif // NURSE_QUEUE_H_