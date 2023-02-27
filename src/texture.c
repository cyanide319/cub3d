/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:31:45 by slord             #+#    #+#             */
/*   Updated: 2023/02/27 16:49:30 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
/*
void	img_init(t_data *data)
{
	

	
	data->text_n.pointer = mlx_xpm_file_to_image(data->immlx_pointer,
			"./images/pouliche.xpm", &img_height, &img_width);
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
texture_h  \ wall_h = lincremation de pixel dans la texture.
	si lincrematation est plus petit que 1, on floor. donc on va utiliser le meme pixel plusieurs fois
	*/
