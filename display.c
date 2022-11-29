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
 *
 */
void wall(App *app)
{
	double teta, Lo, Lp, Ln;
	Point p;
	SideLen SL;
	p.x = app->px;
	p.y = app->py;
	
	SDL_SetRenderDrawColor(app->ren, 255, 0, 0, SDL_ALPHA_OPAQUE);
	Lo = len(p, 60, app->map, 16).len;

	for (int i = 0; i < app->scw; i++)
	{	
		teta = 30 + (i * 60)/app->scw;
		//SL = len(p, teta, app->map, 16) ;
		Lp = len(p, teta, app->map, 16).len * cos(30 - (i * 60)/app->scw);
		Ln = Lo/Lp * 50; /* cos(30 - (i * 60)/app->scw) * M_PI / 180 * 30*/ 
		
		SDL_RenderDrawLine(app->ren, i, app->sch/2  - Ln * 0.20, i, app->sch/2 + Ln * 0.20);
		//SDL_RenderDrawLine(app->ren, i, app->sch/2 - SL.len * 50, i, app->sch/2 + SL.len * 50);
	}



}

/**
 *
 *
 *
 */
void player(App *app)
{
	SDL_Rect pl;
	SDL_SetRenderDrawColor(app->ren, 0xFF, 0xFF, 0xFF, 0xFF);
	pl.w = 8;
        pl.h = 8;
        pl.x = app->px;
        pl.y = app->py;
        SDL_RenderFillRect(app->ren, &pl);

}

/**
 *
 *
 *
 */
void floor_ceil(App *app)
{
	SDL_Rect cr, fr;
	cr.w = fr.w = app->scw;
	cr.h = fr.h = app->sch/2;
	cr.x = fr.x = cr.y = 0;
	fr.y = app->sch/2;
	
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
						app->px -= 0.31;
					}
					else if (e.key.keysym.sym == SDLK_RIGHT)
					{
						app->px += 0.31;
					}
					else if (e.key.keysym.sym == SDLK_DOWN)
					{
						app->py += 0.31;
					}
					else if (e.key.keysym.sym == SDLK_UP)
					{
						app->py -= 0.31;
					}

			}
			
		}

		SDL_SetRenderDrawColor(app->ren, 50, 50, 50, 255);
		SDL_RenderClear(app->ren);
		floor_ceil(app);
		wall(app);
		//player(app);
		SDL_UpdateWindowSurface(app->win);
		SDL_RenderPresent(app->ren);
	}
	SDL_Quit();
}
