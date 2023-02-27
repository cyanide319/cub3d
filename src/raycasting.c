/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:38:11 by slord             #+#    #+#             */
/*   Updated: 2023/02/27 18:17:03 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	texture_selection(t_ray *ray)
{
	int			x;
	int			y;
	static int	texture = 0;
	//static pour eviter le changement de couleur au bout des murs.

	x = (int) floor(ray->x - ray->cos);
	y = (int) floor(ray->y - ray->sin);

	if (x < floor(ray->x) && y == floor(ray->y))
		texture = 3;
	else if (x > floor(ray->x) && y == floor(ray->y))
		texture = 2;
	else if (y < floor(ray->y) && x == floor(ray->x))
		texture = 1;
	else if (y > floor(ray->y) && x == floor(ray->x))
		texture = 0;
	return (texture);
}
void	clear_img_array(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH * 4)
	{
		data->screen_data[i] = 0;
		i++;
	}
}

void	draw_ray(t_ray *ray, t_data *data)
{
	int	i;
	int	x;
	int	y;
	int texture;

	i = 0;
	x = ray->position;
	texture = texture_selection(ray);
	
	if (ray->wall_h > WIN_HEIGHT)
		ray->wall_h = WIN_HEIGHT;
	y = (WIN_HEIGHT / 2) - (ray->wall_h / 2);
	//fonction pour calculer lincrementation de la texure
	while (ray->wall_h > 0)
	{
		if (texture == 0)
		//ouest
			data->img.screen_data[x * 4 + 4 * WIN_WIDTH * y] = 100;
		if (texture == 1)
		//sud draw_text(ray, data, texture);
			data->img.screen_data[x * 4 + 4 * WIN_WIDTH * y + 1] = 100;
		if (texture == 2)
		//est
			data->img.screen_data[x * 4 + 4 * WIN_WIDTH * y+2] = 100;
		if (texture == 3)
		//nord
			data->img.screen_data[x * 4 + 4 * WIN_WIDTH * y+1] = 55;
			
		y++;
		ray->wall_h--;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img.pointer, 0, 0);
}

void	ray_size(t_ray *ray, t_data *data)
{
	ray->distance = sqrt(pow(data->player_x - ray->x, 2) + \
	pow(data->player_y - ray->y, 2));
	ray->distance = ray->distance * cos(ray->angle * (PI / 180) - \
	data->dir_x * (PI / 180));
	ray->wall_h = floor((WIN_HEIGHT / 2) / ray->distance);
	draw_ray(ray, data);
}

void	raycasting(t_data *data)
{
	int		i;
	t_ray	ray;

	i = 0;
	ray.angle = data->dir_x - (VISION / 2);
	while (i < WIN_WIDTH)
	{
		ray.position = i;
		ray.x = data->player_x;
		ray.y = data->player_y;
		ray.cos = cos(ray.angle * (PI / 180)) / (double) 500;
		ray.sin = sin(ray.angle * (PI / 180)) / (double) 500;
		while (data->map->map[(int)floor(ray.y)][(int) floor(ray.x)] && data->map->map[(int)floor(ray.y)][(int) floor(ray.x)] == '0')
		{
			ray.x += ray.cos;
			ray.y += ray.sin;
		}
		ray_size(&ray, data);
		ray.angle += (double) VISION / WIN_WIDTH;
		i++;
	}
}
