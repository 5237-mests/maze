#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

/**
 *struct App - struct containing global variables
 *@px: player position
 *@py: pl
 *@scw: scwd
 *@sch: scrh
 *@teta: angle
 *@worldmap: map
 *@map_size: size
 *@win: sdl window
 *@ren: renderer
 *
 */
typedef struct App
{
	double px;
	double py;
	int scw;
	int sch;
	double teta;
	int **map;
	int map_size;
	SDL_Window *win;
	SDL_Renderer *ren;
	SDL_Texture *floor, *ceil;

	
} App;


/**
 *struct map - map array
 *@length: ray length
 *@side: wall side vertical or horizontal
 *
 */

typedef struct SideLen
{
	double len;
	int face;
} SideLen;

typedef struct Point
{
	double x;
	double y;
} Point;

#endif
