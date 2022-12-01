#include "./src/headers/header.h"

/**
*init - initialize evry variable.
*@app: structure
*/
void init(App *app)
{
	int worldMap[16][16] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	int i, j;

	app->map = (int **)malloc(sizeof(int *) * 16);

	for (i = 0; i < 16; i++)
	{
		app->map[i] = (int *)malloc(sizeof(int *) * 16);
	}
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			app->map[i][j] = worldMap[i][j];
		}
	}

	app->scw = 640;
	app->sch = 512;
	app->win = SDL_CreateWindow("SDL2 maze",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			app->scw,
			app->sch,
			0);
	app->ren = SDL_CreateRenderer(app->win, -1, 0);
	app->floor = SDL_CreateTexture(app->ren,
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET,
			app->scw,
			app->sch);
	app->ceil =  SDL_CreateTexture(app->ren,
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, app->scw, app->sch);
	SDL_SetRenderTarget(app->ren, app->floor);
	SDL_SetRenderDrawColor(app->ren, 0, 0xff, 0, 0xff);
	SDL_RenderClear(app->ren);

	SDL_SetRenderTarget(app->ren, app->ceil);
	SDL_SetRenderDrawColor(app->ren, 0, 0, 0xff, 0xff);
	SDL_RenderClear(app->ren);

	SDL_SetRenderTarget(app->ren, NULL);
	app->px = 2.6;
	app->py = 2.5;

	app->alpha = 10;
}
