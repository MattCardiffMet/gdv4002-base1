#include "Engine.h"

// Function prototypes


int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//
	// Setup game scene objects here
	//

	hideAxisLines(); // this function removes the ugly lines. I really hate them :(

	// the following section is variable initialization
	// ------------------------------------------------
	float pi = 3.14159265f;
	addObject("player");
	addObject("asteroid");
	GameObject2D* player = getObject("player", "Resources\\Textures\\player1_ship.png");
	GameObject2D* asteroid = getObject("asteroid", glm::vec2(1.0f, 1.0f), "Resources\\Textures\\mcblock01.png");
	// ------------------------------------------------

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}

