/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// Emergency Room Records Header File

#ifndef RECORDS_H_
#define RECORDS_H_

/// Let's encapsulate our hiearchical class program in our own namespace called FinalProject
namespace FinalProject {

	class Records {

	private:
		/// Member variable
		int priority;					/// integer value ranging from 1-20 representing severity of illness
		
	public:
		/// Mutator member function for holding this hospital record priority number
		void setPriority(int priority_number) { priority = priority_number; }
		
		/// Accessor member function for retrieving this hospital record information
		int getPriority() { return priority; }

	};

}

#endif // RECORDS_H_
