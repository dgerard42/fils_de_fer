/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_web.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:19:59 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/31 17:20:12 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void			project(t_env *env, t_drw *drw)
{
	drw->x0 = env->ps[0];
	drw->y0 = env->ps[1];
	drw->x1 = env->ps[3];
	drw->y1 = env->ps[4];
	printf("in drw-> x0=%d, y0=%d, x1=%d, y1=%d\n", drw->x0, drw->y0, drw->x1, drw->y1);
}
/*
void			move(t_env *env)
{
	int i;

	i = 0;
	if (!xoffset)
	{

	}
	while (i < 6)
	{
		env->ps[i] =
		env->ps[i + 1] =
		env->ps[i + 2] =
		i = i + 3;
	}
}
*/
void			rotate(t_env *env)
{
	int	i;

	i = 0;

	env->xrot = 0.0;
	env->yrot = 0.0 ;
	env->zrot = 0.0;

	while (i < 6)
	{
		if (env->xrot != 0)
		{
			env->ps[i + 1] = (env->ps[i + 1] * cos(env->xrot)) + (env->ps[i + 2] * -sin(env->xrot));
			env->ps[i + 2] = (env->ps[i + 1] * sin(env->xrot)) + (env->ps[i + 2] * cos(env->xrot));
		}
		if (env->yrot != 0)
		{
			env->ps[i] = (env->ps[i] * cos(env->yrot)) + (env->ps[i + 2] * sin(env->yrot));
			env->ps[i + 2] = (env->ps[i] * -sin(env->yrot)) + (env->ps[i + 2] * cos(env->yrot));
		}
		if (env->zrot != 0)
		{
			env->ps[i] = (env->ps[i] * cos(env->zrot)) + (env->ps[i + 1] * -sin(env->zrot));
			env->ps[i + 1] = (env->ps[i] * sin(env->zrot)) + (env->ps[i + 1] * cos(env->zrot));
		}
		i = i + 3;
	}
}

void			scale(t_env *env)
{
	int i;

	i = 0;
//	printf("ps 0->[%d] 1->[%d] 2->[%d] 3->[%d] 4->[%d] 5->[%d]\n", env->ps[0], env->ps[1], env->ps[2], env->ps[3], env->ps[4], env->ps[5]);
	if (!env->scale)
	{
		env->mapmax = (env->msize[0] >= env->msize[1]) ? env->msize[0] : env->msize[1];
		env->winmax = (WIN_HI >= WIN_LEN) ? WIN_HI : WIN_LEN;
		env->scale = env->winmax / (env->mapmax + 2);
	}
	while (i < 6)
	{
		env->ps[i] = (env->ps[i] * env->scale) + env->scale;
		env->ps[i + 1] = (env->ps[i + 1] * env->scale) + env->scale;
		env->ps[i + 2] = (env->ps[i + 2]) * (env->scale / 3);
		i = i + 3;
	}
//	printf("ps 0->[%d] 1->[%d] 2->[%d] 3->[%d] 4->[%d] 5->[%d]\n", env->ps[0], env->ps[1], env->ps[2], env->ps[3], env->ps[4], env->ps[5]);
}

void			draw_web(t_env *env)
{
	int x;
	int y;
	int twice;
	t_drw drw;

	twice = 0;
	env->ps = ft_intarraynew(6);
	while (twice < 2)
	{
		y = 0;
		while (y < ((twice == 0) ? (env->msize[1]) : (env->msize[0])))
		{
			x = 0;
			while ((x + 1) < ((twice == 0) ? (env->msize[0]) : (env->msize[1])))
			{
	//			is_map(env->map);
	//			printf("twice = %d\n", twice);
	//			printf("x=%d, y=%d, z=%d\n", x, y, env->map[x][y]);
				env->ps[0] = (twice == 0) ? x : y;
				env->ps[1] = (twice == 0) ? y : x;
				env->ps[2] = (twice == 0) ? env->map[y][x] : env->map[x][y];
				env->ps[3] = (twice == 0) ? (x + 1) : y;
				env->ps[4] = (twice == 0) ? y : (x + 1);
				env->ps[5] = (twice == 0) ? env->map[y][x + 1] : env->map[x + 1][y];
				scale(env);
				rotate(env);
				project(env, &drw);
				draw_line(env, &drw);
				x++;
			}
			y++;
		}
		twice++;
	}
}
