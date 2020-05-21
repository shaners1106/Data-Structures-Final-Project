/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// Waiting Room Implementation File

#include "WaitRoom.h"
namespace FinalProject {

	/// Mutator function to set the arrival rate of patients in the ER (per hour)
	void FinalProject::WaitRoom::setArrivalRate(double arrival_rate) { this->arrival_rate = arrival_rate; }

	/// Member function to set the doctor pointer to the relevant Doctor_queue object
	void WaitRoom::setDoctorQueue(Doctor_queue * doctor_queue) { this->doctor_queue = doctor_queue;	}

	/// Memeber function to set the nurse pointer to the relevant Nurse_queue object
	void WaitRoom::setNurseQueue(Nurse_queue * nurse_queue) { this->nurse_queue = nurse_queue;	}

	/// Member function that repeatedly updates the status of the waiting room
	/// adding new patients to the ER per the user-chosen average patients per hour
	void WaitRoom::clock(int tick)
	{
		if (ER_random.randomized_double() < arrival_rate) {
			Patient * newPatient = new Patient(tick);
			wait_queue.push(newPatient);
			patients.push_back(newPatient);
		}
	}

}