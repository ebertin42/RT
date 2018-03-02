/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:40:11 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/02 18:11:42 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ft_put_pixel(t_sdl *sdl, int x, int y, int color)
{
	sdl->pixels[(y * SIZE_X + x)] = color;
}

void	one_pixel(t_obj obj, t_sdl *sdl, int i, int j)
{
	int a;
	int b;
	int c;
	int xr;
	int yr;
	int zr;
	//double t1;
	//double t2;
	int delta;
	int vx;
	int vy;
	int vz;

	xr = 0;
	yr = 0;
	zr = 42;
	printf("%d|%d|%d|%d\n", obj.sphere[0].pos.x,obj.sphere[0].pos.y,obj.sphere[0].pos.z, obj.sphere[0].rayon);
	vx = (i - SIZE_X / 2);
	vy = (j - SIZE_Y / 2);
	vz = (SIZE_X / 2) / tan(30);
	a = (vx * vx) + (vy * vy) + (vz * vz);
	b = 2 * (vx * (xr - obj.sphere[0].pos.x) + vy *
	(yr - obj.sphere[0].pos.y) + vz * (zr - obj.sphere[0].pos.z));
	c = ((((xr - obj.sphere[0].pos.x) * (xr - obj.sphere[0].pos.x)) +
	((yr - obj.sphere[0].pos.y) * (yr - obj.sphere[0].pos.y)) +
	((zr - obj.sphere[0].pos.z) *
	(zr - obj.sphere[0].pos.z))) -
	(obj.sphere[0].rayon * obj.sphere[0].rayon));
	delta = (b * b) - 4 * a * c;
	if (delta >= 0)
	{
	/*	if (delta > 0)
		{
			t1 = (-b + sqrt(delta)) / (2 * a);
			t2 = (-b - sqrt(delta)) / (2 * a);
		}*/
		ft_put_pixel(sdl, i, j, obj.sphere[0].color);
	}
}

void	raytracing(t_obj obj, t_sdl s)
{
	int x;
	int y;

	x = 0;
	(void)obj;
	while (x != SIZE_X)
	{
		y = 0;
		while (y != SIZE_Y)
		{
			one_pixel(obj, &s, x, y);
			y++;
		}
		x++;
	}
	s.surface->pixels = s.pixels;
	display(&s);
}
