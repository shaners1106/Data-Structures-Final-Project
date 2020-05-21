/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// Doctor's queue header file

#ifndef DOCTOR_QUEUE_H_
#define DOCTOR_QUEUE_H_
#include "ER_queue.h"
#include "Randomizer.h"
#include "WaitRoom.h"
#include <queue>
using std::queue;

/// Let's encapsulate our hiearchical class program in our own namespace called FinalProject
namespace FinalProject {

	extern Randomizer ER_random;

	class Doctor_queue : public ER_queue {

	private:

		/// Member variables

		size_t amount_of_docs;			/// How many doctors working in the ER
		int patients_served;			/// How many patients the doctors have served throughout this simulation
		queue<Patient *> doctor_queue;	/// Queue holding the patients currently being seen by doctors
		WaitRoom * waiting_queue;		/// Pointer to reference our waiting room queue

	public:
		/// No Arg constructor
		Doctor_queue() {}
		/// Copy Constructor
		Doctor_queue(const Doctor_queue & other) {
			amount_of_docs = other.amount_of_docs;
			patients_served = other.patients_served;
			doctor_queue = other.doctor_queue;
			waiting_queue = other.waiting_queue;
		}
		/// Destructor
		~Doctor_queue() { delete[] waiting_queue; }
		/// Assignment operator
		Doctor_queue& operator=(Doctor_queue& other) {
			waiting_queue = new WaitRoom(*other.waiting_queue);
			return *this;
		}
		
		/// Mutator and Accessor member function prototypes
		void setDocs(int docs);
		void setWait(WaitRoom * waiting_queue);
		int getDocs();
		int getPatientsServed();

		/// Doctor queue update function prototype
		void clock(int tick);
		
	};

}

#endif // DOCTOR_QUEUE_H_