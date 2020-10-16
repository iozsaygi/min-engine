#include "min_engine.h"

int main( int argc, char *argv[] )
{
	min::EngineEntry *engineEntry = new min::EngineEntry( "Min Engine", 800, 600, 60 );
	
	min::World *world = new min::World( engineEntry, true );
	min::WorldManager::SetActiveWorld( world );

	world->Tick();

	delete world;
	delete engineEntry;

	return 0;
}