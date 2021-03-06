/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:05:53 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/28 14:03:42 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	usage(void)
{
	ft_putstr("\nUSAGE : ./rt <scene>\n\n");
	exit(0);
}

void	parser_error(int err)
{
	if (err == 0)
		ft_putstr("\nPARSER ERROR :\n\n");
	exit(0);
}

void	ft_sdl_error(char *msg, const char *error)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(error, 2);
	ft_putchar('\n');
	exit(1);
}

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putchar('\n');
	exit(1);
}
