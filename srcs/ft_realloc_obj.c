/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:25:55 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/03 15:51:39 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_obj	realloc_plan(t_env *e, int i)
{
	t_obj	ret;

	ret.pos = init_point(e->obj[i].pos.x, e->obj[i].pos.y, e->obj[i].pos.z);
	ret.color = e->obj[i].color;
	ret.rot.x = e->obj[i].rot.x;
	ret.rot.y = e->obj[i].rot.y;
	ret.transp = e->obj[i].transp;
	ret.rot.z = e->obj[i].rot.z;
	ret.material = e->obj[i].material;
	ret.type = 4;
	ret.num = e->obj[i].num;
	ret.rot_to_print = e->obj[i].rot_to_print;
	ret.reflex = e->obj[i].reflex;
	ret.transp = e->obj[i].transp;
	return (ret);
}

t_obj	realloc_cone(t_env *e, int i)
{
	t_obj	ret;

	ret.pos = init_point(e->obj[i].pos.x, e->obj[i].pos.y, e->obj[i].pos.z);
	ret.angle = e->obj[i].angle;
	ret.angletan = e->obj[i].angletan;
	ret.rot.x = e->obj[i].rot.x;
	ret.rot.y = e->obj[i].rot.y;
	ret.transp = e->obj[i].transp;
	ret.rot.z = e->obj[i].rot.z;
	ret.rot = normalize_vec(ret.rot);
	ret.material = e->obj[i].material;
	ret.color = e->obj[i].color;
	ret.type = 3;
	ret.num = e->obj[i].num;
	ret.rot_to_print = e->obj[i].rot_to_print;
	ret.reflex = e->obj[i].reflex;
	ret.transp = e->obj[i].transp;
	return (ret);
}

t_obj	realloc_cylindre(t_env *e, int i)
{
	t_obj	ret;

	ret.pos = init_point(e->obj[i].pos.x, e->obj[i].pos.y, e->obj[i].pos.z);
	ret.rayon = e->obj[i].rayon;
	ret.rayon_2 = e->obj[i].rayon_2;
	ret.rot.x = e->obj[i].rot.x;
	ret.rot.y = e->obj[i].rot.y;
	ret.transp = e->obj[i].transp;
	ret.rot.z = e->obj[i].rot.z;
	ret.rot_to_print = e->obj[i].rot_to_print;
	ret.rot = normalize_vec(ret.rot);
	ret.material = e->obj[i].material;
	ret.color = e->obj[i].color;
	ret.type = 2;
	ret.num = e->obj[i].num;
	ret.reflex = e->obj[i].reflex;
	ret.transp = e->obj[i].transp;
	ret.taille = e->obj[i].taille;
	ret.fin = e->obj[i].fin;
	return (ret);
}

t_obj	realloc_disque(t_env *e, int i)
{
	t_obj	ret;

	ret.pos = init_point(e->obj[i].pos.x, e->obj[i].pos.y, e->obj[i].pos.z);
	ret.rayon = e->obj[i].rayon;
	ret.rayon_2 = e->obj[i].rayon_2;
	ret.rot.x = e->obj[i].rot.x;
	ret.rot.y = e->obj[i].rot.y;
	ret.transp = e->obj[i].transp;
	ret.rot.z = e->obj[i].rot.z;
	ret.rot_to_print = e->obj[i].rot_to_print;
	ret.rot = normalize_vec(ret.rot);
	ret.material = e->obj[i].material;
	ret.color = e->obj[i].color;
	ret.type = 5;
	ret.num = e->obj[i].num;
	ret.reflex = e->obj[i].reflex;
	ret.transp = e->obj[i].transp;
	return (ret);
}

t_obj	*realloc_obj(t_env *e)
{
	t_obj	*new;

	e->nb++;
	new = (t_obj *)malloc(sizeof(t_obj) * e->nb);
	if (!new)
		ft_error("malloc error\n");
	realloc_obj_helper(new, e);
	free(e->obj);
	return (new);
}
