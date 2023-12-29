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
	//проходим по всему экрану
	for (int x = 0; x < ConsoleController::nScreenWidth; x++)
	{
		//расчитывание угла проекции потенциально выпущенного луча. От -FOV/2 до FOV/2
		double rayAngle = (player.viewAngle - player.FOV / 2.0) + ((double)x / (double)ConsoleController::nScreenWidth) * player.FOV;

		//расстояние от игрока до стены для этого расчитанного угла
		double distanceToWall = 0;

		bool isHitWall = false;

		//вектор направления, куда смотрит игрок
		double eyeX = sin(rayAngle);
		double eyeY = cos(rayAngle);

		//маленькими приращениями увеличиваем расстояние и проверяем, не столкнулись ли мы со стеной
		while (!isHitWall && distanceToWall < player.viewRadius)
		{
			distanceToWall += 0.1;

			//начинаем строить луч маленькими шажками. 
			int nTestX = (int)(player.x + eyeX * distanceToWall);
			int nTestY = (int)(player.y + eyeY * distanceToWall);

			//если мы ушли за границы карты, значит мы точно врезались в ее границу
			if (nTestX < 0 || nTestX >= MapController::nMapWidth || nTestY < 0 || nTestY >= MapController::nMapHeight)
			{
				isHitWall = true;
				distanceToWall = player.viewRadius;
			}
			else //если мы внутри карты
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
