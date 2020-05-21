/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// Patient class header file


#ifndef PATIENT_H_
#define PATIENT_H_
#include "Records.h"
#include "Randomizer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
using std::map;
using std::string;
using std::vector;
using std::ifstream;

/// Let's encapsulate our hiearchical class program in our own namespace called FinalProject
namespace FinalProject {


	extern Randomizer ER_random;
	
	/// Sub Class derived from the Resident base class
	class Patient {

	private:

		/// Member variables
		string name;					/// String variable holding this patient's first name
		string surname;					/// String variable holding this patient's last name
		int priority_number;			/// Integer value representing this patient's priority number
		int arrival_time;				/// Integer value representing when this patient arrived in the waiting room
		int start_service_time;			/// Integer value representing the time when this patient begins being treated by a nurse or doc
		int total_waitRoom_time;		/// Integer value representing the total time this patient spent in the wait room
		int discharge_time;				/// Integer value representing the time that this patient was discharged
		int totat_service_time;			/// Integer value representing the total time this patient will be in treatment
		int number_visits;				/// Amount of times this patient has visited the ER
		vector<Records *> pat_records;	/// A vector holding this patient's ER visit records
		vector<string> first_names;		/// A vector holding the 2000 first names from our .txt file
		vector<string> surnames;				/// A vector holding the 1000 last names from our .txt file
		map<string, vector<Records*>> ER_stats;	/// A map member variable to be referenced upon demand by the user
		
	public:
		
		/// I needed to overload the constructor for this patient class, so that I could declare
		/// a patient object in the very beginning of the program without using our emergency room
		/// patient constructor in order to be able to access Patient::load_names()
		/// No Arg overloaded constructor
		Patient() {}

		/// Patient Constructor...the meat and potatoes of this program
		/// You pass in the current time setting this patient's arrival time and set the start
		/// service time to -1 as a beginning default
		Patient(int tick) : arrival_time(tick), start_service_time(-1) {
			/// Start by using our random priority number generator to capture this patient's priority number
			int holder = ER_random.random_priority_number();
			/// Give this patient their random (based off of the guideline probabilities) priority illness number
			priority_number = holder;
			/// Declare and initialize a new Records object for this patient
			Records * newRecord = new Records;
			/// Update this new record's member variable
			newRecord->setPriority(holder);
			/// Push it into this patient's records file
			pat_records.push_back(newRecord);
			/// Incremement this patient's number of emergency room stops
			number_visits++;
			/// Now, let's randomly generate a number between 0 and 1999 so that we can randomly assign this patient a first name
			int firstNameHolder = ER_random.randomized_int();
			/// Now, let's capture a random number between 0 & 999 for our last name distribution
			int surnameHolder = ER_random.randomized_last_name_int();
			/// Give our patient a name!
			name = first_names[firstNameHolder];
			/// Now, that he/she has a given name, what's their surname?
			if (this->number_visits == 0) {		/// But only if this patient is a new patient and doesn't already have a last name
				surname = surnames[surnameHolder];
			}
			/// Now we just need to insert this patient into our map data structure, unless he/she is already there
			auto search = ER_stats.find(surname);
			if (search == ER_stats.end()) {			/// If this iterator has reached the end of the file, this is a new patient
				ER_stats.insert(make_pair(surname, pat_records));	/// So add him/her to our map
			}
			
		}
		
		/// Accessor function prototypes
		int getPriority();
		int getArrival();
		int getStartService();
		int getVisits();
		int getTotalService();
		string getName();
		string getSurname();
		/// Accessor member functions to retrieve our names vectors
		vector<string> getNameVec();
		vector<string> getSurnameVec();
		

		/// Mutator function prototypes
		void setDischarge(int tick);
		void setStartService(int tick);
		void setTotal_WaitRoom_Time(int time);

		/// Overload precedence operator for our priority queue patient distribution
		bool operator<(Patient & other);

		/// Our File input function to read 273ville names from our .txt files
		void load_names();

	};

}

#endif // PATIENT_H_
