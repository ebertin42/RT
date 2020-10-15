/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_obj_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:25:55 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/03 15:51:39 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	realloc_obj_helper(t_obj *new, t_env *e)
{
	int	i;

	i = 0;
	while (i != e->nb - 1)
	{
		if (e->obj[i].type == 2)
			new[i] = realloc_cylindre(e, i);
		else if (e->obj[i].type == 3)
			new[i] = realloc_cone(e, i);
		else if (e->obj[i].type == 4)
			new[i] = realloc_plan(e, i);
		else if (e->obj[i].type == 1)
			new[i] = realloc_sphere(e, i);
		else if (e->obj[i].type == 5)
			new[i] = realloc_disque(e, i);
		else
			ft_error("realloc error\n");
		i++;
	}
}
