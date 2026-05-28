#include "../GameEngine.h"
#include "../Utils.h"
#include <iostream>

int SDL_main(int argc, char* argv[]) {
	srand(time(NULL));

	GameEngine engine(SCREEN_WIDTH, SCREEN_HEIGHT);

	engine.Update();
	engine.Finish();

	return 0;
}