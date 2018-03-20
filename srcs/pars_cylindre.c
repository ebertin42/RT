/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:30:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/20 17:53:35 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	check_param(char **sp)
{
	int			ret;

	ret = 1;
	if (ft_tablen((void **)sp) != 7)
		ret = 0;
	else if (!check_value(sp[5]))
		ret = 0;
	return (ret);
}

void		add_cylindre(t_env *e, char **sp)
{
	t_obj	*new;

	if (!check_param(sp))
		ft_error("Wrong sphere parameters.");
	if (!(new = (t_obj *)malloc(sizeof(t_obj))))
		ft_error("Failed to malloc new sphere.");
	new->pos = vector_init(ft_atoi(sp[1]), ft_atoi(sp[2]), ft_atoi(sp[3]));
	new->rayon = ft_atoi(sp[5]);
	new->material = ft_atoi(sp[6]);
	new->color = ft_atoi_color(only_color(sp[4]));
	new->type = 2;
	e->obj[e->nb] = *new;
	free(new);
}