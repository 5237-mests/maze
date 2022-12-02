#include "./src/headers/header.h"

/**
 * min - return minimum of two double numbers
 * @x: first num
 * @y: seconf num
 * Return: minimum of x and y
 */
double min(double x, double y)
{
	if (x <= y)
		return (x);
	return (y);
}


/**
 *wall - draw wall
 *@app: struct
 */
void wall(App *app)
{
	double Lo, Lp, Ln, angle, angle2, side;
	SDL_Rect rect;
	Point p;
	SideLen SL;

	p.x = app->px;
	p.y = app->py;

	SDL_SetRenderDrawColor(app->ren, 255, 0, 0, SDL_ALPHA_OPAQUE);
	angle = app->alpha + 30;
	SL = len(p, angle, app->map, 16);
	side = SL.face;
	Lo = SL.len;
	if (side)
		SDL_SetRenderDrawColor(app->ren, 255, 255, 255, SDL_ALPHA_OPAQUE);

	for (int i = 0; i < app->scw; i++)
	{
		app->teta = app->alpha + (i * 60) / app->scw;
		angle2 = app->alpha - ((i * 60) / app->scw);
		Lp = len(p, app->teta, app->map, 16).len;
		Ln = (Lo / (Lp * cos(angle2 * M_PI / 180)));
		SDL_RenderDrawLine(app->ren, i, app->sch / 2  - Ln * 10, i, app->sch / 2 + Ln * 10);
	}

	for (int row = 0; row < 16; row++)
	{
		for (int column = 0; column < 16; column++)
		{
			if (app->map[row][column] != 0)
			{
				SDL_SetRenderDrawColor(app->ren, 0x99, 0x9F, 0xFF, 0xFF);
				rect.w = 1;
				rect.h = 1;
				rect.x = column * rect.w;
				rect.y = row * rect.h;
				SDL_RenderFillRect(app->ren, &rect);
			}
		}
	}

}

/**
 *player - player func
 *@app: struct
 */
void player(App *app)
{
	SDL_Rect pl;
	SDL_SetRenderDrawColor(app->ren, 0xFF, 0xFF, 0xFF, 0xFF);
	pl.w = 1;
	pl.h = 1;
	pl.x = app->px;
	pl.y = app->py;
	SDL_RenderFillRect(app->ren, &pl);
}

/**
 *floor_ceil - draw ceil and floor
 *@app: struct
 */
void floor_ceil(App *app)
{
	SDL_Rect cr, fr;
	cr.w = fr.w = app->scw;
	cr.h = fr.h = app->sch / 2;
	cr.x = fr.x = cr.y = 0;
	fr.y = app->sch / 2;
	SDL_RenderCopy(app->ren, app->ceil, &cr, &cr);
	SDL_RenderCopy(app->ren, app->floor, &fr, &fr);
}

/**
 *display - init sdl win on scren
 *@app: all info
 *
 */
void display(App *app)
{
	int r = 1;
	SDL_Event e;

	while (r)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				r = 0;
			} else if (e.type == SDL_KEYDOWN)
			{
					if (e.key.keysym.sym == SDLK_LEFT)
					{
						if (app->px <= 1)
						{
							app->px += 0.1;
						} else
						{
							app->px -= 0.1;
						}
					}
					else if (e.key.keysym.sym == SDLK_RIGHT)
					{
						if (app->px >= 15)
						{	app->px -= 0.1;
						}
						else
						{
							app->px += 0.1;
						}
					}
					else if (e.key.keysym.sym == SDLK_DOWN)
					{
						if (app->py >= 15)
						{	app->py -= 0.1;
						}
						else
						{
							app->py += 0.1;
						}
					}
					else if (e.key.keysym.sym == SDLK_UP)
					{
						if (app->py <= 1)
						{	app->py += 0.1;
						}
						else
						{
							app->py -= 0.1;
						}
					} else if (e.key.keysym.sym == SDLK_a)
					{
						if (app->alpha <= 0)
						{
							app->alpha += 360;
						}
						else
						{
							app->alpha -= 3;
						}
					} else if (e.key.keysym.sym == SDLK_w)
					{
						if (app->alpha >= 300)
						{
							app->alpha -= 360;
						}
						else
						{
							app->alpha += 3;
						}
					}
			}
		}
		SDL_SetRenderDrawColor(app->ren, 50, 50, 50, 255);
		SDL_RenderClear(app->ren);
		floor_ceil(app);
		wall(app);
		player(app);
		SDL_UpdateWindowSurface(app->win);
		SDL_RenderPresent(app->ren);
	}
	SDL_Quit();
}
