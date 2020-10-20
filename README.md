## Min Engine
Min Engine is a minimal game engine that i used to create a game during Ludum Dare 47 event. </br>
The engine is built on top of SDL library and supports "Entity - Component" architecture.

## Dependencies
  * [SDL2](https://www.libsdl.org/)
  * [SDL_image](https://www.libsdl.org/projects/SDL_image/)
  * [SDL_mixer](https://www.libsdl.org/projects/SDL_mixer/index.html)
  * [SDL_ttf](https://www.libsdl.org/projects/SDL_ttf/)

## Building
  * <b>Windows</b>
    * Download the [Visual Studio Community 2019](https://visualstudio.microsoft.com/) (Make sure to install "Desktop development with C++")
    * Clone the repository
    * Download all the dependencies required and put them all in "dependencies" folder
    * Make sure "dependencies" folder is at the same location with ".sln" file of project
    * Build the project inside Visual Studio
    
    This is how your general folder structure should looks like (After build)
    
        .
        ├── build          
        ├── dependencies
        ├── min
        ├── sandbox
        ├── .gitignore
        ├── LICENSE
        ├── min.sln
        └── README.md
        
## Examples
<b>1. Creating a basic actor with existing components such as sprite renderer and box collider</b>
```cpp
#include "min_engine.h"

int main( int argc, char *argv[] )
{
	// Create the engine entry to initialize dependencies and setup game window.
	min::EngineEntry *engineEntry = new min::EngineEntry( "Min Engine", 800, 600, 60 );
	
	// Create new world (scene) and set is as current active world.
	min::World *world = new min::World( engineEntry, true );
	min::WorldManager::SetActiveWorld( world );

	// Create basic player actor and add basic components such as sprite renderer and box collider.
	min::Actor *player = new min::Actor( "Player" );
	player->AddComponent<min::SpriteRenderer>( player, engineEntry, "assets/imgs/player.png" );
	player->AddComponent<min::BoxCollider2D>( player );

	// Add the player to the current active world.
	world->AddActor( player );

	// Start the tick process of the world.
	world->Tick();

	// Clean up.
	delete world;
	delete engineEntry;

	return 0;
}
```
        
## Games made with Min Engine
* [Underlands - Ludum Dare 47](https://ldjam.com/events/ludum-dare/47/underlands)
* [Ripsight - Demo project](https://github.com/iozsaygi/ripsight)

## License
[MIT License](https://github.com/iozsaygi/ripsight/blob/master/LICENSE)
