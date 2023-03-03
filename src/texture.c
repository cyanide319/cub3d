/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:31:45 by slord             #+#    #+#             */
/*   Updated: 2023/03/02 18:53:26 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	img_init(t_data *data)
{
	data->text_n.pointer = mlx_xpm_file_to_image(data->text_n.pointer,
			data->map->wall_no, &data->text_n.width, &data->text_n.height);
	data->text_s.pointer = mlx_xpm_file_to_image(data->text_s.pointer,
			data->map->wall_so, &data->text_s.width, &data->text_s.height);
	data->text_w.pointer = mlx_xpm_file_to_image(data->text_w.pointer,
			data->map->wall_we, &data->text_w.width, &data->text_w.height);
	data->text_e.pointer = mlx_xpm_file_to_image(data->text_e.pointer,
			data->map->wall_ea, &data->text_e.width, &data->text_e.height);
}

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
