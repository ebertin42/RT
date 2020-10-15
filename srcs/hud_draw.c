/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:01:46 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/02 17:00:18 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	empty_rect_hud(t_rect b, t_env *e, int t, int color)
{
	int	i;

	i = b.x;
	while (i != b.x + b.len)
	{
		if (t == 1)
		{
			ft_put_pixel_hud(e->hud, i, b.y, color);
			ft_put_pixel_hud(e->hud, i, b.y + b.hei, color);
		}
		else
		{
			ft_put_pixel_winrend(e->pixels, i, b.y, color);
			ft_put_pixel_winrend(e->pixels, i, b.y + b.hei, color);
		}
		i++;
	}
}

void	empty_rect_pixel(t_rect b, t_env *e, int t, int color)
{
	int	i;

	i = b.y;
	while (i != b.y + b.hei)
	{
		if (t == 1)
		{
			ft_put_pixel_hud(e->hud, b.x, i, color);
			ft_put_pixel_hud(e->hud, b.x + b.len, i, color);
		}
		else
		{
			ft_put_pixel_winrend(e->pixels, b.x, i, color);
			ft_put_pixel_winrend(e->pixels, b.x + b.len, i, color);
		}
		i++;
	}
}

void	empty_rect(t_rect b, t_env *e, int t, int color)
{
	empty_rect_hud(b, e, t, color);
	empty_rect_pixel(b, e, t, color);
}

void	ornement(SDL_Rect p, int color, int size, t_env *e)
{
	t_vec	p1;
	t_vec	p2;
	int		l;

	l = p.h / 2 + p.y;
	p2.y = l;
	p1.y = l;
	p1.x = p.x - size;
	p2.x = p.x - 10;
	horizontal_trait(p1, p2, color, e);
	p1.x = p.x + p.w + 10;
	p2.x = p.x + p.w + size;
	horizontal_trait(p1, p2, color, e);
}
