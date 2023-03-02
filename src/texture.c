/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:31:45 by slord             #+#    #+#             */
/*   Updated: 2023/03/02 18:53:26 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//fonction qui determine quel colonne de la texture on affiche.
int	calculate_texture_pixel(t_data *data, t_ray *ray, int vertical) 
{
	if (vertical)
	{
		return (ray->x - (int)floor(ray->x) * data->img.width);
	}
	else
		return (ray->y - (int)floor(ray->y) * data->img.width);
}

int  calculate_incre(int wall_h, int texture_h)
{
	int texture_increment;
	
	// si lincrematation est plus petit que 1, on floor. donc on va utiliser le meme pixel plusieurs fois
	texture_increment = texture_h / wall_h;
	return (texture_increment);
}

void	draw_texture(t_data *data, t_ray *ray)
 {
	int	incre;
	int	col;
	int	y;
	int	x;
	int	i;

	x = ray->position;
	y = (WIN_HEIGHT / 2) - (ray->wall_h / 2);
	i = 0;
	incre = calculate_incre(ray->wall_h, ray->texture.height);
	col = calculate_texture_pixel(data, ray, 1);
	while (ray->wall_h > 0)
	{
		//POSITION DU PIXEL A CHANGER
		while (i< 4)
		{
			data->img.screen_data[x * 4 + 4 * WIN_WIDTH * y + i] = data->img.screen_data[col * 4 + 4 * WIN_WIDTH * incre + i];
			i++;
		}
		ray->wall_h--;
		y++;
		incre+=incre;
	}
 }
