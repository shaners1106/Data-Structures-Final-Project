/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// The Base class for all of our patient queues-HEADER FILE

#ifndef ER_QUEUE_H_
#define ER_QUEUE_H_
#include "Patient.h"
#include <vector>
using std::vector;


namespace FinalProject {

	class ER_queue {
	
	public:
		vector <Patient *> patients;
		

		/// Here's our polymorphic function that will be expressed differently in each of the sub classes
		virtual void clock(int tick) = 0;

	};
	
}

#endif // ER_QUEUE_H_
