/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// Nurse's queue implementation file

#include "Nurse_queue.h"
namespace FinalProject {

	/// Mutator member function for setting the amount of nurses in the ER
	void FinalProject::Nurse_queue::setNurses(int nurses) { amount_of_nurses = nurses; }

	/// Mutator member function for setting this object's WaitRoom pointer to point to the correct object
	void Nurse_queue::setWait(WaitRoom * waiting_queue) { this->waiting_queue = waiting_queue; }

	/// Accessor member function for retrieving the number of nurses working in the ER
	int Nurse_queue::getNurses() {	return amount_of_nurses; }

	/// Accessor member function for retrieving the amount of patients 
	/// that have been served by the nurses during this simulation
	int Nurse_queue::getPatientsServed() { return patients_served;	}

	/// Member function that repeatedly updates the status of the ER nurses, 
	/// by pulling patients out of the waiting room and into the nurse's queue,
	/// servicing the sick patients per the average nurse's service time,
	/// and discharging patients after they have elapsed their service time
	/// Nurses can only service patients with a priority number of 10 or less
	void Nurse_queue::clock(int tick)
	{
		/// Let's begin our nurses office update by checking to see if any patients have received
		/// full treatment and are ready for discharge...start by making sure that there's actually patients being currently serviced by nurses!
		if (!(nurse_queue.empty())) {
			/// Now that we know there are patients in the nurses queue, let's initialize an iterator object that will allow us to traverse my vector queue
			list<Patient *>::iterator iter = nurse_queue.begin(); 
			while (iter != nurse_queue.end()) {
				/// Check each person in the nurses queue: if they've elapsed their service time, they're ready for discharge!
				int holder = (*iter)->getStartService();
				int holder2 = (*iter)->getTotalService();
				if ((tick - holder) >= holder2) {
					(*iter)->setDischarge(tick);
					nurse_queue.erase(iter);
				}
				++iter;
			}
		}
		/// Now that we've discharged any applicable patients, let's see if there are any patients with
		/// illnesses in the 1-10 priority range in the waiting room that we can bring in for service
		/// First a quick check to see if there are any nurses currently available to see patients
		while (nurse_queue.size() < amount_of_nurses) {
			/// Okay, now that there is definitely at leaset 1 available nurse, let's establish a new empty priority queue 
			/// so that we can find the patient with the highest priority number (up to a priority of 10)
			/// and reference them
			/// Starting a copy priority queue will allow us to pull patients lower than the one at the top
			/// of the priority queue, not lose our patients at the top, and then update our WaitRoom priority queue
			/// Start by declaring a Patient pointer and new priority queue of patients that will temporarily hold our copy
			Patient * patient = NULL;
			priority_queue <Patient *> copy;
			/// If the patient at the top of the WaitRoom priority queue doesn't have priority number higher than 10,
			/// we don't have to monkey around with our copy priority queue, we can just pull the top patient
			if (waiting_queue->wait_queue.top()->getPriority() <= 10) {
				patient = waiting_queue->wait_queue.top();		/// Make our patient pointer point to the person at the top
				nurse_queue.push_back(patient);					/// Push_back this person into our nurse vector queue
				waiting_queue->wait_queue.pop();				/// Pop this person from the priority queue
			}
			/// Now we need to account for the scenerio where the patient in the top of our WaitRoom priority queue
			/// has a priority number higher than 10
			else {
				/// But first, let's make sure that there's actually patients in the waiting room
				if (!(waiting_queue->wait_queue.empty())) {
					/// Start a loop that will run as long as the WaitRoom priority queue isn't empty and the
					/// patient at the top of the priority queue has a priority number higher than 10
					while ((waiting_queue->wait_queue.top()->getPriority() > 10) && !(waiting_queue->wait_queue.empty())) {
						copy.push(waiting_queue->wait_queue.top());		/// Push our patient whose at the top into our copy
						waiting_queue->wait_queue.pop();				/// And pop him/her off
					}
					/// Now that we've temporarily removed all of the patients in the waiting room that can only be
					/// treated by doctors, we're ready to pull our next patient into the nurses room
					/// First, let's check to make sure that removing our patients with priority numbers above 10
					/// didn't completely empty our waiting room
					if (!(waiting_queue->wait_queue.empty())) {
						/// Okay, so now that we know that there is still someone in the waiting room, let's point to him/her
						patient = waiting_queue->wait_queue.top();
						nurse_queue.push_back(patient);				/// And push_back him/her into our nurses queue
						waiting_queue->wait_queue.pop();			/// And make sure to pop him off of the WaitRoom queue
																	/// Now, we need to make sure to return a full copy of our WaitRoom priority queue
																	/// so let's fully update our copy queue, which is currently holding our top priority patients
						while (!(waiting_queue->wait_queue.empty())) {
							/// Initialize a holder Patient pointer that will allow us to fill up our copy priority queue
							/// Make this holder point to the person at the top of the WaitRoom queue
							Patient * holder = waiting_queue->wait_queue.top();
							/// Push this patient into our copy queue
							copy.push(holder);
							/// Pop this patient off of the WaitRoom queue
							waiting_queue->wait_queue.pop();
						}
					}
				}
				/// Now that we've completed the process of re-filling our nurse queue, and have an updated
				/// copy of our WaitRoom priority queue, we need to update the actual queue with our new copy
				waiting_queue->wait_queue = copy;
			}
		}
	}

}
