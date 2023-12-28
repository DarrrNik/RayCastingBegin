#include "RayCasting.h"

Raycasting::Raycasting() : player()
{

}

Raycasting::Raycasting(const Player& _player)
{
	player = _player;
}

void Raycasting::Raycast()
{
	for (int x = 0; x < ConsoleController::nScreenWidth; x++)
	{
		double rayAngle = (player.viewAngle - player.FOV / 2.0) + ((double)x / (double)ConsoleController::nScreenWidth) * player.FOV;
		double distanceToWall = 0;

		bool isHitWall = false;

		double eyeX = sin(rayAngle);
		double eyeY = cos(rayAngle);

		while (!isHitWall && distanceToWall < player.viewRadius)
		{
			distanceToWall += 0.1;

			int nTestX = (int)(player.x + eyeX * distanceToWall);
			int nTestY = (int)(player.y + eyeY * distanceToWall);

			if (nTestX < 0 || nTestX >= MapController::nMapWidth || nTestY < 0 || nTestY >= MapController::nMapHeight)
			{
				isHitWall = true;
				distanceToWall = player.viewRadius;
			}
			else
			{
				if (MapController::buf[nTestY * MapController::nMapWidth + nTestX] == '#')
				{
					isHitWall = true;
				}
			}
		}

		int nCeiling = (double)(ConsoleController::nScreenHeight / 2.0) - ConsoleController::nScreenHeight / distanceToWall;
		int nFloor = ConsoleController::nScreenHeight - nCeiling;

		for (int y = 0; y < ConsoleController::nScreenHeight; y++)
		{
			if (y < nCeiling)
			{
				ConsoleController::screen[y * ConsoleController::nScreenWidth + x] = ' ';
			}
			else if(y > nCeiling && y <= nFloor)
			{
				ConsoleController::screen[y * ConsoleController::nScreenWidth + x] = '#';
			}
			else
			{
				ConsoleController::screen[y * ConsoleController::nScreenWidth + x] = ' ';
			}
		}
	}
}
