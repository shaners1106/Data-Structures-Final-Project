/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// Doctor's queue implementation file

#include "Doctor_queue.h"

namespace FinalProject {

	/// Mutator member function for setting the amount of doctors in the ER
	void FinalProject::Doctor_queue::setDocs(int docs) { amount_of_docs = docs; }

	/// Mutator member function for setting this object's WaitRoom pointer to point to the correct object
	void Doctor_queue::setWait(WaitRoom * waiting_queue) { this->waiting_queue = waiting_queue;	}

	/// Accessor member function for retrieving the number of doctors working in the ER
	int Doctor_queue::getDocs() { return amount_of_docs; }

	/// Accessor member function for retrieving the amount of patients that have been served 
	/// by the doctors during this simulation
	int Doctor_queue::getPatientsServed() {	return patients_served;	}

	/// Member function that repeatedly updates the status of the ER doctors, 
	/// by pulling patients out of the waiting room and into the doctor's queue,
	/// servicing the sick patients per the average doctor service time,
	/// and discharging patients after they have elapsed their service time
	/// Doctors can service any patient in the ER
	void Doctor_queue::clock(int tick)
	{
		/// Let's begin our doctor office update by potentially discharging any patients that have elapsed their service time
		if (!doctor_queue.empty()) {
			/// Establish a pointer that will point to the patient that has been in the doctor's office the longest
			Patient * patient = doctor_queue.front();
			if ((tick - patient->getArrival()) > (patient->getTotalService())) {
				/// Discharge this patient from the hospital!
				doctor_queue.pop();
				/// Update this patient's discharge time
				patient->setDischarge(tick);
			}
		}

		/// Now, let's check and see if the doctor's are ready to see another patient
		if (doctor_queue.size() < amount_of_docs) {
			/// Pull a patient from the waiting room into the service room
			if (!waiting_queue->wait_queue.empty()) {
				/// Initialize a pointer that will point to the top member of the wait room
				Patient * patient = waiting_queue->wait_queue.top();
				/// Bring the top member of the waiting room into the doctor's room
				waiting_queue->wait_queue.pop();
				/// Initialize an integer variable to capture this patient's total time waiting in the waiting room
				/// And set this patient's total wait room wait
				int total_waitRoom_wait = tick - patient->getArrival();
				patient->setTotal_WaitRoom_Time(total_waitRoom_wait);
				/// And increment the amount of patients served by doctors 
				patients_served++;
				/// Update the start service time for this patient
				patient->setStartService(tick);
				/// Don't forget to add this patient to the doctor's queue!
				doctor_queue.push(patient);

			}
		}
	}	
	
}