#include "min_engine.h"

int main( int argc, char *argv[] )
{
	// Create the engine entry with window properties.
	min::EngineEntry *engineEntry = new min::EngineEntry( "Min Engine", 800, 600, 60 );
	
	// Create new world (scene) and set is as current active world.
	min::World *world = new min::World( engineEntry, true );
	min::WorldManager::SetActiveWorld( world );

	// Create test actor and add it to the current active world.
	min::Actor *actor = new min::Actor( "Actor" );
	world->AddActor( actor );

	// Start the tick process of the world.
	world->Tick();

	delete world;
	delete engineEntry;

	return 0;
}