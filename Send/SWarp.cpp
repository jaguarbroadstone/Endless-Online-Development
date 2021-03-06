#include "SWarp.h"
#include "..\Game.h"
#include <iostream>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys\utime.h>
#include <iostream>
#include <chrono>
#include <ctime>

void SWarp::AcceptWarp(pt::ipstream* ClientStream,int MapID, int x, int y ,LPVOID game)
{
	Game* gme = (Game*)game;
	PacketBuilder builder = PacketBuilder(PACKET_WARP, PACKET_ACCEPT);
	builder.AddShort(MapID);
	builder.AddChar(x);
	builder.AddChar(y);
	World::Send(gme,ClientStream,builder);
}
void SWarp::AcceptFile(pt::ipstream* ClientStream, LPVOID game)
{
	Game* gme = (Game*)game;
	PacketBuilder builder = PacketBuilder(PACKET_WARP, PACKET_TAKE);

	World::Send(gme, ClientStream, builder);
}