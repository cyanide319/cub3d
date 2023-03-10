/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:31:45 by slord             #+#    #+#             */
/*   Updated: 2023/03/08 13:25:54 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	img_init(t_data *data)
{
	data->text_n.pointer = mlx_xpm_file_to_image(data->mlx,
			data->map->wall_no, &data->text_n.width, &data->text_n.height);
	data->text_s.pointer = mlx_xpm_file_to_image(data->mlx,
			data->map->wall_so, &data->text_s.width, &data->text_s.height);
	data->text_w.pointer = mlx_xpm_file_to_image(data->mlx,
			data->map->wall_we, &data->text_w.width, &data->text_w.height);
	data->text_e.pointer = mlx_xpm_file_to_image(data->mlx,
			data->map->wall_ea, &data->text_e.width, &data->text_e.height);
	if (data->text_n.pointer == NULL || data->text_s.pointer == NULL
		|| data->text_w.pointer == NULL || data->text_e.pointer == NULL)
		return (-1);
	data->text_n.screen_data = mlx_get_data_addr(data->text_n.pointer,
			&data->text_n.bpp, &data->text_n.size_line, &data->text_n.endian);
	data->text_s.screen_data = mlx_get_data_addr(data->text_s.pointer,
			&data->text_s.bpp, &data->text_s.size_line, &data->text_s.endian);
	data->text_e.screen_data = mlx_get_data_addr(data->text_e.pointer,
			&data->text_e.bpp, &data->text_e.size_line, &data->text_e.endian);
	data->text_w.screen_data = mlx_get_data_addr(data->text_w.pointer,
			&data->text_w.bpp, &data->text_w.size_line, &data->text_w.endian);
	return (0);
}

int	calculate_texture_pixel(t_data *data, t_ray *ray, int vertical)
{
	if (vertical)
	{
		return ((ray->x - (int)floor(ray->x)) * data->text_n.width);
	}
	else
		return ((ray->y - (int)floor(ray->y)) * data->text_n.width);
}

double	calculate_incre(int wall_h, int texture_h)
{
	double	texture_increment;

	texture_increment = (double)texture_h / (double)wall_h;
	return (texture_increment);
}

void	draw_line(t_data *data, t_ray *ray, double j, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->img.screen_data[ray->position * 4 + 4 * WIN_WIDTH * y + i]
			= ray->texture.screen_data[(int)floor(j) * 4 * ray->texture.width
			+ (ray->text_c * 4) + i];
		i++;
	}
}

void	draw_texture(t_data *data, t_ray *ray, int texture)
{
	double	incre;
	int		y;
	double	j;

	incre = calculate_incre(ray->wall_h, ray->texture.height);
	ray->text_c = floor((int)((int) ray->texture.width
				* (ray->x + ray->y)) % ray->texture.width);
	if (texture == 0 || texture == 3)
		ray->text_c = ray->texture.width - ray->text_c;
	j = 0;
	if (ray->wall_h > WIN_HEIGHT)
		j += incre * (ray->wall_h / 2 - (WIN_HEIGHT / 2));
	if (ray->wall_h > WIN_HEIGHT)
			ray->wall_h = WIN_HEIGHT;
	y = (WIN_HEIGHT / 2) - (ray->wall_h / 2);
	while (ray->wall_h > 0)
	{
		draw_line(data, ray, j, y);
		ray->wall_h--;
		y++;
		j = incre + j;
	}
}
