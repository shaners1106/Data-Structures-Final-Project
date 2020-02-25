/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// Patient class implementation file


#include "Patient.h"
namespace FinalProject {

	/// Accessor function for retrieving this patient's priority number
	int Patient::getPriority() { return priority_number; }

	/// Accessor function for retrieving this patient's arrival time
	int Patient::getArrival() {	return arrival_time; }

	/// Accessor function for retrieving this patient's start service time
	int Patient::getStartService() { return start_service_time;	}

	/// Accessor function for retrieving this patient's number of visits
	int Patient::getVisits() { return number_visits; }

	/// Accessor function for retrieving this patient's total service time
	int Patient::getTotalService() { return totat_service_time;	}

	/// Accessor functions for retrieving this objects name and last name
	string Patient::getName() { return name; }

	string Patient::getSurname() { return surname; }

	vector<string> Patient::getNameVec() {	return first_names;	}

	vector<string> Patient::getSurnameVec() { return surnames; }
	

	/// Mutator function for setting this patient's discharge time
	void Patient::setDischarge(int tick) {	discharge_time = tick;	}

	/// Mutator function for setting when this patient enters the doctor/nurses office
	void Patient::setStartService(int tick) { start_service_time = tick; }

	/// Mutator function for setting this patient's total time in the waiting room
	void Patient::setTotal_WaitRoom_Time(int time) { total_waitRoom_time = time; }

	/// This function establishes the precedence of the > and < operators so that our priority queue can operate accurately
	bool Patient::operator<(Patient & other)
	{
		/// Precedence will be based solely upon the patient's priority number
		if (this->priority_number < other.priority_number)
			return true;
		else if ((this->priority_number == other.priority_number) && (this->getSurname() < other.getSurname()))
			return true;
		else
			return false;
	}

	/// Our member function for loading names into our static member variable vectors
	/// It begins by opening the 273ville first names .txt file and pushing back each name into the vector
	/// Then it opens the 273ville surnames .txt file and pushes back each surname into the vector
	/// It ends by closing the file
	void Patient::load_names()
	{
		ifstream first_name_file("C:\\Users\\Snediker\\Documents\\Whitworth\\Year 1\\Summer 18\\Data Structures\\FINAL PROJECT\\residents_of_273ville.txt");
		if (first_name_file.is_open()) {
			string name;
			while (first_name_file >> name) {
				first_names.push_back(name);
			}
		}

		first_name_file.close();

		ifstream surname_file("C:\\Users\\Snediker\\Documents\\Whitworth\\Year 1\\Summer 18\\Data Structures\\FINAL PROJECT\\surnames_of_273ville.txt");
		if (surname_file.is_open()) {
			string name;
			while (surname_file >> name) {
				surnames.push_back(name);
			}
		}

		surname_file.close();
	}

}
