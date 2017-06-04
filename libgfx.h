/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 12:33:49 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/28 18:32:01 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H

typedef struct	s_coords
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			rise;
	int			run;
}				t_coords;

typedef	struct	s_env
{
	void		*mlx;
	void		*window;
	void		*image;
	int			win_len;
	int			win_hi;
	int			color;
}				t_env;

#endif