/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// Waiting Room Header File

#ifndef WAITROOM_H_
#define WAITROOM_H_
#include "ER_queue.h"
#include "Patient.h"
#include "Randomizer.h"
#include <queue>
using std::priority_queue;

/// Let's encapsulate our hiearchical class program in our own namespace called FinalProject
namespace FinalProject {

	extern Randomizer ER_random;

	class WaitRoom : public ER_queue {

		friend class Doctor_queue;
		friend class Nurse_queue;

	private:

		/// Member variables

		double arrival_rate;					/// Average amount of patients arriving to the ER per hour
		Doctor_queue * doctor_queue;			/// Pointer to the doctor queue
		Nurse_queue * nurse_queue;				/// Pointer to the nurse queue
		priority_queue<Patient *> wait_queue;	/// Priority queue holding our ER wait room

	public:
		/// No Arg constructor
		WaitRoom() {}
		/// Copy Constructor
		WaitRoom(const WaitRoom& other) {
			arrival_rate = other.arrival_rate;
			doctor_queue = other.doctor_queue;
			nurse_queue = other.nurse_queue;
			wait_queue = other.wait_queue;
		}
		/*
		Couldn't figure out my circular dependency issue

		/// Destructor
		/// ~WaitRoom() { delete[] doctor_queue;
		delete[] nurse_queue; }
		/// Assignment operator
		/// WaitRoom & operator=(WaitRoom & other)  {
		doctor_queue = new Doctor_queue(*other.doctor_queue);
		nurse_queue = new Nurse_queue(*other.nurse_queue);
	}      

		*/

		/// Mutator member function prototypes
		void setArrivalRate(double arrival_rate);
		void setDoctorQueue(Doctor_queue * doctor_queue);
		void setNurseQueue(Nurse_queue * nurse_queue);
		
		/// Waiting Room update member function prototype
		void clock(int tick);

	};

}

#endif // WAITROOM_H_
