#include "min_engine.h"

int main( int argc, char *argv[] )
{
	// Create the engine entry to initialize dependencies and setup game window.
	min::EngineEntry *engineEntry = new min::EngineEntry( "Min Engine", 800, 600, 60 );

	// Create new world (scene) and set is as current active world.
	min::World *world = new min::World( engineEntry, true );
	min::WorldManager::SetActiveWorld( world );

	// Start the tick process of the world.
	world->Tick();

	// Clean up.
	delete world;
	delete engineEntry;

	return 0;
}