#include <SDL.h>
#include "audio.h"

namespace min
{
	Mix_Chunk *LoadWaveChunk( const std::string &path )
	{
		return Mix_LoadWAV( path.c_str() );
	}
}