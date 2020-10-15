/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:20:26 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/30 15:01:38 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	ft_wait_first_loadscreen(int x, int i)
{
	(void)i;
	ft_wait();
	ft_wait();
	ft_wait();
	ft_wait();
	ft_wait();
	return (x + 1);
}

void	loading_screen(int i, t_sdl *s)
{
	SDL_Rect		r;
	static int		x = 0;
	int				y;

	if (x > 3)
		y = 4;
	else
		y = 0;
	if (i > 3)
	{
		if (x < 3)
			r = init_sdl_rect(0, 0, WIN_X - 1, WIN_Y - 1);
		else
			r = init_sdl_rect(COL4 + SIZE_X - 200, SIZE_Y, 100, 20);
		i += 23;
		if ((SDL_RenderCopy(s->renderer, s->tex[i - y], NULL, &r)) < 0)
			ft_sdl_error("Texture error : ", SDL_GetError());
		SDL_RenderPresent(s->renderer);
		if (x < 3)
			x = ft_wait_first_loadscreen(x, i);
	}
}
