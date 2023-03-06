/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:38:11 by slord             #+#    #+#             */
/*   Updated: 2023/03/06 13:35:46 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	texture_selection(t_ray *ray)
{
	int			x;
	int			y;
	static int	texture = 0;

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
	int	texture;

	texture = texture_selection(ray);
	if (texture == 0)
		ray->texture = data->text_w;
	else if (texture == 1)
		ray->texture = data->text_s;
	else if (texture == 2)
	ray->texture = data->text_e;
	else if (texture == 3)
		ray->texture = data->text_n;
	draw_texture(data, ray, texture);
}

void	ray_size(t_ray *ray, t_data *data)
{
	ray->distance = sqrt(pow(data->player_x - ray->x, 2)
			+ pow(data->player_y - ray->y, 2));
	ray->distance = ray->distance * cos(ray->angle * (PI / 180)
			-data->dir_x * (PI / 180));
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
		while (data->map->map[(int)floor(ray.y)][(int) floor(ray.x)] 
			&& data->map->map[(int)floor(ray.y)][(int) floor(ray.x)] == '0')
		{
			ray.x += ray.cos;
			ray.y += ray.sin;
		}
		ray_size(&ray, data);
		ray.angle += (double) VISION / WIN_WIDTH;
		i++;
	}
}
