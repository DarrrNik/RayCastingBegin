#pragma once

#include <iomanip>
#include <fstream>

#define DEFAULT_MAP_WIDTH (16)
#define DEFAULT_MAP_HEIGHT (16)

class MapController
{
public:
	MapController();
	MapController(std::string fileName);
	MapController(MapController& exemp);
private:
	int nMapWidth;
	int nMapHeight;
	std::string buf;
};

