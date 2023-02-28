/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:31:45 by slord             #+#    #+#             */
/*   Updated: 2023/02/28 13:11:20 by tbeaudoi         ###   ########.fr       */
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
	//je dois d'abord déterminer si le rayon à frapper un mur vertical ou horizontal
	//si par exemple je frappe un mur horizontal à la positon 5.5, 2. je sais que je dois afficher la colonne du milieu car j'ai touché le mur au centre.
	if (vertical)
	{
		return (ray->x -int(floor(ray->x)) * data->img.n.width);
	}
	else
		return (ray->y -int(floor(ray-y)) * data->img.n.width);
}

int pixel incrementation(int wall_h, int texture_h)
{

	si lincrematation est plus petit que 1, on floor. donc on va utiliser le meme pixel plusieurs fois

int	 calculate_incre(t_ray *ray)
{
	ray->pixel.incre = text_n /data->ray->wall_h;
}
 void	draw_text(t_ray *ray, t_data *data, int texture)
 {
	int	incre;
	int	col;

	incre = calculate_incre(ray);
	col = calculate_texture_pixel(data, ray);
	while 
	
 }
	
