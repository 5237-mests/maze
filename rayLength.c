#include "./src/headers/header.h"

/**
 * len1 - calculate length of ray in first quadrant(0->90)
 * @p: player position point
 * @teta: ray angle with x axis
 * @map: map array
 * @size: size of map
 * Return: lenght of ray and face of wall hit by ray
 */
SideLen len1(Point p, double teta, int **map, int size)
{

	double dx, dy, Dx, Dy, rx, ry, Rx, Ry, R, r, x, y;
	SideLen ray;
	int X, Y;

	x = p.x;
	y = p.y;
	dx = 1 + (int)p.x - p.x;
	dy = p.y - (int)p.y;
	rx = dx / cos(teta * M_PI / 180);
	ry = dy / sin(teta * M_PI / 180);
	Dx = size - 1 - p.x;
	Dy = p.y - 1;
	Rx = Dx / cos(teta * M_PI / 180);
	Ry = Dy / sin(teta * M_PI / 180);
	R = Rx;
	ray.face = 1;
	if (Ry < R)
	{
		R = Ry;
		ray.face = 0;
	}
	r = min(rx, ry);
	while (r <= R)
	{
		if (rx == ry)
		{
			x = x + dx;
			y = y - dy;
			dx = 1;
			dy = 1;
			if (map[(int)(y - 0.2)][(int)(x + 0.2)] == 1)
			{
				ray.len = (p.y - y) / sin(teta * M_PI / 180);
				ray.face = 0;
				return (ray);
			}
		}
		else if (rx < ry)
		{
			x  = x + dx;
			y = y - dx * tan(teta * M_PI / 180);
			dx = 1;
			dy = y - (int)y;
			if (map[(int)y][(int)(x + 0.2)] == 1)
			{
				ray.len = (x - p.x) / cos(teta * M_PI / 180);
				ray.face = 1;
				return (ray);
			}
		}
		else if (rx > ry)
		{

			x = x + dy / tan(teta * M_PI / 180);
			y = y - dy;
			dx = 1 + (int)x - x;
			dy = 1;
			if (map[(int)(y - 0.2)][(int)x] == 1)
			{
				ray.len = (p.y - y) / sin(teta * M_PI / 180);
				ray.face = 0;
				return (ray);
			}
		}

		rx = dx / cos(teta * M_PI / 180);
		ry = dy / sin(teta * M_PI / 180);
		r += min(rx, ry);
	}
	ray.len = R;
	return (ray);
}
/**
 * len2 - calculate length of ray in first quadrant(0->90)
 * @p: player position point
 * @teta: ray angle with x axis
 * @map: map array
 * @size: size of map
 * Return: lenght of ray and face of wall hit by ray
 */
SideLen len2(Point p, double teta, int **map, int size)
{
	double dx, dy, Dx, Dy, rx, ry, Rx, Ry, R, r, x, y;
	SideLen ray;
	int X, Y;

	x = p.x;
	y = p.y;
	dx = p.x - (int)p.x;
	dy = p.y - (int)p.y;
	rx = dx / cos((180 - teta) * M_PI / 180);
	ry = dy / sin((180 - teta) * M_PI / 180);
	Dx = p.x - 1;
	Dy = p.y - 1;
	Rx = Dx / cos((180 - teta) * M_PI / 180);
	Ry = Dy / sin((180 - teta) * M_PI / 180);
	R = Rx;
	ray.face = 1;
	if (Ry < R)
	{
		R = Ry;
		ray.face = 0;
	}
	r = min(rx, ry);
	while (r <= R)
	{
		if (rx == ry)
		{
			x = x - dx;
			y = y - dy;
			dx = 1;
			dy = 1;
			if (map[(int)(y - 0.2)][(int)(x - 0.2)] == 1)
			{
				ray.len = (p.y - y) / sin((180 - teta) * M_PI / 180);
				ray.face = 0;
				return (ray);
			}
		}
		else if (rx < ry)
		{
			x = x - dx;
			y = y - dx * tan((180 - teta) * M_PI / 180);
			dx = 1;
			dy = y - (int)y;
			if (map[(int)y][(int)(x - 0.2)] == 1)
			{
				ray.len = (p.x - x) / cos((180 - teta) * M_PI / 180);
				ray.face = 1;
				return (ray);
			}
		}
		else if (ry < rx)
		{

			x = x - dy / tan((180 - teta) * M_PI / 180);
			y = y - dy;
			dx = x - (int)x;
			dy = 1;
			if (map[(int)(y - 0.2)][(int)x] == 1)
			{
				ray.len = (p.y - y) / sin((180 - teta) * M_PI / 180);
				ray.face = 0;
				return (ray);
			}
		}
		rx = dx / cos((180 - teta) * M_PI / 180);
		ry = dy / sin((180 - teta) * M_PI / 180);
		r += min(rx, ry);
	}
	ray.len = R;
	return (ray);
}
/**
 * len2 - calculate length of ray in first quadrant(0->90)
 * @p: player position point
 * @teta: ray angle with x axis
 * @map: map array
 * @size: size of map
 * Return: lenght of ray and face of wall hit by ray
 */
SideLen len3(Point p, double teta, int **map, int size)
{
	double dx, dy, Dx, Dy, rx, ry, Rx, Ry, R, r, x, y;
	SideLen ray;
	int X, Y;

	x = p.x;
	y = p.y;
	dx = p.x - (int)p.x;
	dy = 1 + (int)p.y - p.y;
	rx = dx / cos((teta - 180) * M_PI / 180);
	ry = dy / sin((teta - 180) * M_PI / 180);
	Dx = p.x - 1;
	Dy = size - p.y - 1;
	Rx = Dx / cos((teta - 180) * M_PI / 180);
	Ry = Dy / sin((teta - 180) * M_PI / 180);
	R = Rx;
	ray.face = 1;
	if (Ry < R)
	{
		R = Ry;
		ray.face = 0;
	}
	r = min(rx, ry);
	while (r <= R)
	{
		if (rx == ry)
		{
			x = x - dx;
			y = y + dy;
			dx = 1;
			dy = 1;
			if (map[(int)(y + 0.2)][(int)(x - 0.2)] == 1)
			{
				ray.len = (y - p.y) / sin((teta - 180) * M_PI / 180);
				ray.face = 0;
				return (ray);
			}
		}
		else if (rx < ry)
		{
			x = x - dx;
			y = y + dx * tan((teta - 180) * M_PI / 180);
			dx = 1;
			dy = 1 + (int)y - y;
			if (map[(int)y][(int)(x - 0.2)] == 1)
			{
				ray.len = (p.x - x) / cos((teta - 180) * M_PI / 180);
				ray.face = 1;
				return (ray);
			}
		}
		else if (rx > ry)
		{
			x = x - dy / tan((teta - 180) * M_PI / 180);
			y = y + dy;
			dx = x - (int)x;
			dy = 1;
			if (map[(int)(y + 0.2)][(int)x] == 1)
			{
				ray.len = (y - p.y) / sin((teta - 180) * M_PI / 180);
				ray.face = 0;
				return (ray);
			}
		}

		rx = dx / cos((teta - 180) * M_PI / 180);
		ry = dy / sin((teta - 180) * M_PI / 180);
		r += min(rx, ry);
	}
	ray.len = R;
	return (ray);
}
/**
 * len4 - calculate length of ray in first quadrant(0->90)
 * @p: player position point
 * @teta: ray angle with x axis
 * @map: map array
 * @size: size of map
 * Return: lenght of ray and face of wall hit by ray
 */
SideLen len4(Point p, double teta, int **map, int size)
{

	double dx, dy, Dx, Dy, rx, ry, Rx, Ry, R, r, x, y;
	SideLen ray;
	int X, Y;

	x = p.x;
	y = p.y;
	dx = 1 + (int)p.x - p.x;
	dy = 1 + (int)p.y - p.y;
	rx = dx / cos((360 - teta) * M_PI / 180);
	ry = dy / sin((360 - teta) * M_PI / 180);
	Dx = size - 1 - p.x;
	Dy = size - 1 - p.y;
	Rx = Dx / cos((360 - teta) * M_PI / 180);
	Ry = Dy / sin((360 - teta) * M_PI / 180);
	R = Rx;
	ray.face = 1;
	if (Ry < R)
	{
		R = Ry;
		ray.face = 0;
	}
	r = min(rx, ry);
	while (r <= R)
	{
		if (rx == ry)
		{
			x = x + dx;
			y = y + dy;
			dx = 1;
			dy = 1;
			if (map[(int)(y + 0.2)][(int)(x + 0.2)] == 1)
			{
				ray.len = (y - p.y) / sin((360 - teta) * M_PI / 180);
				ray.face = 0;
				return (ray);
			}
		}
		else if (rx < ry)
		{
			x  = x + dx;
			y = y + dx * tan((360 - teta) * M_PI / 180);
			dx = 1;
			dy = 1 + (int)y - y;
			if (map[(int)y][(int)(x + 0.2)] == 1)
			{
				ray.len = (x - p.x) / cos((360 - teta) * M_PI / 180);
				ray.face = 1;
				return (ray);
			}
		}
		else if (rx > ry)
		{

			x = x + dy / tan((360 - teta) * M_PI / 180);
			y = y + dy;
			dx = 1 + (int)x - x;
			dy = 1;
			if (map[(int)(y + 0.2)][(int)x] == 1)
			{
				ray.len = (y - p.y) / sin((360 - teta) * M_PI / 180);
				ray.face = 0;
				return (ray);
			}
		}

		rx = dx / cos((360 - teta) * M_PI / 180);
		ry = dy / sin((360 - teta) * M_PI / 180);
		r += min(rx, ry);
	}
	ray.len = R;
	return (ray);
}

SideLen len(Point p, double teta, int **map, int size)
{

	if (teta >= 0 && teta <= 90)
		return (len1(p, teta, map, size));
	if (teta > 90 && teta <= 180)
		return (len2(p, teta, map, size));
	if (teta > 180 && teta <= 270)
		return (len3(p, teta, map, size));
	return (len4(p, teta, map, size));
}

