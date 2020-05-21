/// Shane Snediker
/// CS 273 Dr. Tucker
/// Final Project
/// 7-15-2018
/// MAIN FILE

#include "ER_Simulator.h"							/// Our ER simulator runs the show
#include "Patient.h"



int main()
{
	/// Start by pre-loading our names vectors all at once, so we don't have to do it upon every new patient generation
	FinalProject::Patient NameLoader;
	NameLoader.load_names();

	/// Now, let's create an ER_Simulation object
	FinalProject::ER_Simulator EmergencyRoom;

	/// Let's get to simulating...

	EmergencyRoom.prompt_user();
	EmergencyRoom.simulate();
	EmergencyRoom.display();





	return 0;
}
