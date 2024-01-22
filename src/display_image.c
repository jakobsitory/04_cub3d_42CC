/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:05:29 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/22 15:16:19 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

// TODOS
// - free xpm
// - memory safe rays part
// - malloc protections
// - properly exit if any error
// - properly name and organize structs and variables

int	get_pixel_color(t_ray_result ray, int y)
{
	float	rel_y;
	int		column;
	int		row;
	char	*color_hex_string;
	int		color_hex;

	if (is_whole_number(ray.x))
		rel_y = ray.y - (int)ray.y;
	else if (is_whole_number(ray.y))
		rel_y = ray.x - (int)ray.x;
	else
		rel_y = 0;
	column = ray.xpm->columns * rel_y;
	row = ((float)(y - ray.start_y) / ray.line_height) * 10;
	color_hex_string = get_hex_from_char(ray.xpm->lines[row][column], ray.xpm);
	color_hex = hex_to_int(color_hex_string);
	return (color_hex);
}

void	display_image(void *mlx, void *win, t_ray_result *rays, t_window *window)
{
	int	i;
	int	x;
	int	y;
	int	color;

	i = 0;
	x = 0;
	while (i < window->fov_degrees)
	{
		ft_printf("start_y %f end_y %f\n", rays[i].start_y, rays[i].end_y);
		while (x < window->px_per_ray)
		{
			y = rays[i].start_y;
			while (y < rays[i].end_y)
			{
				color = get_pixel_color(rays[i], y);
				mlx_pixel_put(mlx, win, i * window->px_per_ray + x, y, color);
				y++;
			}
			y = 0;
			x++;
		}
		x = 0;
		i++;
	}
}

/* void	display_image(void *mlx, void *win, t_ray_result *rays, t_window *window)
{
	int	i;
	int	x;
	int	y;
	int	color;

	i = 0;
	x = 0;
	while (i < window->fov_degrees)
	{
		while (x < window->px_per_ray)
		{
			y = rays[i].start_y;
			while (y < rays[i].end_y)
			{				// go over 1/10 of y

				color = get_pixel_color(rays[i], y);
				mlx_pixel_put(mlx, win, i * window->px_per_ray + x, y, color);
				y++;
			}
			y = 0;
			x++;
		}
		x = 0;
		i++;
	}
} */


void	assign_textures(t_ray_result rays[], int no_rays, int i)
{
	while (i < no_rays)
	{
		if (rays[i].degree <= 90 || rays[i].degree >= 270)
		{
			if (is_whole_number(rays[i].y))
				rays[i].texture_path = ft_strdup(NORTH_TEXTURE);
		}
		if (rays[i].degree <= 180 && rays[i].degree >= 0)
		{
			if (is_whole_number(rays[i].x))
				rays[i].texture_path = ft_strdup(EAST_TEXTURE);
		}
		if (rays[i].degree <= 270 && rays[i].degree >= 90)
		{
			if (is_whole_number(rays[i].y))
				rays[i].texture_path = ft_strdup(SOUTH_TEXTURE);
		}
		if (rays[i].degree <= 360 && rays[i].degree >= 180)
		{
			if (is_whole_number(rays[i].x))
				rays[i].texture_path = ft_strdup(WEST_TEXTURE);
		}
		i++;
	}
}

void	fix_fisheye(t_ray_result rays[], int no_rays)
{
	int		i;
	float	player_angle_rad;
	float	ray_angle_rad;
	float	diff_angle;

	player_angle_rad = 45 * PI / 180.0;
	i = -1;
	while (i++ < no_rays) 
	{
		ray_angle_rad = rays[i].degree * PI / 180.0;
		diff_angle = ray_angle_rad - player_angle_rad;
		while (diff_angle < -PI)
			diff_angle += 2 * PI;
		while (diff_angle > PI)
			diff_angle -= 2 * PI;
		rays[i].distance = rays[i].distance * cos(diff_angle);
	}
}

/* t_ray_result	*prepare_rays(t_ray_result rays[], t_window *window)
{
	int	i;

	fix_fisheye(rays, window->fov_degrees);
	i = -1;
	while (i++ < window->fov_degrees - 1)
		rays[i].line_height = (25 * 900) / rays[i].distance;
	i = -1;
	while (i++ < window->fov_degrees - 1)
		rays[i].start_y = window->center_y - rays[i].line_height / 2;
	i = -1;
	while (i++ < window->fov_degrees - 1)
		rays[i].end_y = window->center_y + rays[i].line_height / 2;
	i = -1;
	assign_textures(rays, window->fov_degrees, 0);
	while (i++ < window->fov_degrees - 1)
		rays[i].xpm = parse_xpm(rays[i].texture_path);
	return (rays); */
}

int	main(void)
{
	void			*mlx;
	void			*win;
	t_window		*window;
	t_ray_result	*rays;

	window = init_window();
	rays = init_rays();
	rays = prepare_rays(rays, window);
	mlx = mlx_init();
	win = mlx_new_window(mlx, window->width_px, window->height_px, "window");
	display_image(mlx, win, rays, window);
	mlx_loop(mlx);
	return (0);
}


void	get_texture(t_ray_result *ray)
{
	if (ray->degree <= 90 || ray->degree >= 270)
	{
		if (is_whole_number(ray->y))
			ray->texture_path = ft_strdup(NORTH_TEXTURE);
	}
	else if (ray->degree <= 180 && ray->degree >= 0)
	{
		if (is_whole_number(ray->x))
			ray->texture_path = ft_strdup(EAST_TEXTURE);
	}
	else if (ray->degree <= 270 && ray->degree >= 90)
	{
		if (is_whole_number(ray->y))
			ray->texture_path = ft_strdup(SOUTH_TEXTURE);
	}
	else if (ray->degree <= 360 && ray->degree >= 180)
	{
		if (is_whole_number(ray->x))
			ray->texture_path = ft_strdup(WEST_TEXTURE);
	}
}

t_window *init_window(void)
{
	t_window	*window = malloc(sizeof(t_window));

	window->fov_degrees = 90; // for now substitute for number of rays
	window->height_px = 480;
	window->width_px = 720;
	window->center_x = window->width_px / 2;
	window->center_y = window->height_px / 2;
	window->px_per_ray = window->width_px / window->fov_degrees;
	return (window);
}

t_ray_result	*init_rays()
{
	t_ray_result* rays = malloc(90 * sizeof(t_ray_result));

	rays[0].degree = 0;
	rays[0].distance = 150.000000;
	rays[0].x = 105.000000;
	rays[0].y = 70.000000;
	rays[1].degree = 1;
	rays[1].distance = 150.013336;
	rays[1].x = 106.000000;
	rays[1].y = 70.000000;
	rays[2].degree = 2;
	rays[2].distance = 150.083313;
	rays[2].x = 108.000000;
	rays[2].y = 70.000000;
	rays[3].degree = 3;
	rays[3].distance = 150.163239;
	rays[3].x = 109.000000;
	rays[3].y = 70.000000;
	rays[4].degree = 4;
	rays[4].distance = 150.332962;
	rays[4].x = 112.000000;
	rays[4].y = 70.000000;
	rays[5].degree = 5;
	rays[5].distance = 86.838928;
	rays[5].x = 140.000000;
	rays[5].y = 224.000000;
	rays[6].degree = 6;
	rays[6].distance = 55.901699;
	rays[6].x = 140.000000;
	rays[6].y = 157.000000;
	rays[7].degree = 7;
	rays[7].distance = 105.588821;
	rays[7].x = 140.000000;
	rays[7].y = 109.000000;
	rays[8].degree = 8;
	rays[8].distance = 151.462860;
	rays[8].x = 119.000000;
	rays[8].y = 70.000000;
	rays[9].degree = 9;
	rays[9].distance = 151.753082;
	rays[9].x = 121.000000;
	rays[9].y = 70.000000;
	rays[10].degree = 10;
	rays[10].distance = 152.236664;
	rays[10].x = 123.000000;
	rays[10].y = 70.000000;
	rays[11].degree = 11;
	rays[11].distance = 152.777618;
	rays[11].x = 125.000000;
	rays[11].y = 70.000000;
	rays[12].degree = 12;
	rays[12].distance = 153.169846;
	rays[12].x = 126.000000;
	rays[12].y = 70.000000;
	rays[13].degree = 13;
	rays[13].distance = 153.805069;
	rays[13].x = 128.000000;
	rays[13].y = 70.000000;
	rays[14].degree = 14;
	rays[14].distance = 154.495956;
	rays[14].x = 130.000000;
	rays[14].y = 70.000000;
	rays[15].degree = 15;
	rays[15].distance = 155.241745;
	rays[15].x = 133.000000;
	rays[15].y = 70.000000;
	rays[16].degree = 16;
	rays[16].distance = 156.041656;
	rays[16].x = 135.000000;
	rays[16].y = 70.000000;
	rays[17].degree = 17;
	rays[17].distance = 156.604599;
	rays[17].x = 136.000000;
	rays[17].y = 70.000000;
	rays[18].degree = 18;
	rays[18].distance = 157.492859;
	rays[18].x = 138.000000;
	rays[18].y = 70.000000;
	rays[19].degree = 19;
	rays[19].distance = 154.324341;
	rays[19].x = 140.000000;
	rays[19].y = 72.000000;
	rays[20].degree = 20;
	rays[20].distance = 146.778748;
	rays[20].x = 140.000000;
	rays[20].y = 78.000000;
	rays[21].degree = 21;
	rays[21].distance = 140.217682;
	rays[21].x = 140.000000;
	rays[21].y = 83.000000;
	rays[22].degree = 22;
	rays[22].distance = 133.701157;
	rays[22].x = 140.000000;
	rays[22].y = 88.000000;
	rays[23].degree = 23;
	rays[23].distance = 128.156158;
	rays[23].x = 140.000000;
	rays[23].y = 92.000000;
	rays[24].degree = 24;
	rays[24].distance = 123.567795;
	rays[24].x = 140.000000;
	rays[24].y = 95.000000;
	rays[25].degree = 25;
	rays[25].distance = 119.012604;
	rays[25].x = 140.000000;
	rays[25].y = 99.000000;
	rays[26].degree = 26;
	rays[26].distance = 114.494545;
	rays[26].x = 140.000000;
	rays[26].y = 102.000000;
	rays[27].degree = 27;
	rays[27].distance = 110.909874;
	rays[27].x = 140.000000;
	rays[27].y = 105.000000;
	rays[28].degree = 28;
	rays[28].distance = 107.354553;
	rays[28].x = 140.000000;
	rays[28].y = 108.000000;
	rays[29].degree = 29;
	rays[29].distance = 103.831596;
	rays[29].x = 140.000000;
	rays[29].y = 111.000000;
	rays[30].degree = 30;
	rays[30].distance = 100.344406;
	rays[30].x = 140.000000;
	rays[30].y = 114.000000;
	rays[31].degree = 31;
	rays[31].distance = 97.754799;
	rays[31].x = 140.000000;
	rays[31].y = 116.000000;
	rays[32].degree = 32;
	rays[32].distance = 95.189285;
	rays[32].x = 140.000000;
	rays[32].y = 118.000000;
	rays[33].degree = 33;
	rays[33].distance = 91.809586;
	rays[33].x = 140.000000;
	rays[33].y = 121.000000;
	rays[34].degree = 34;
	rays[34].distance = 90.138779;
	rays[34].x = 140.000000;
	rays[34].y = 122.000000;
	rays[35].degree = 35;
	rays[35].distance = 87.658424;
	rays[35].x = 140.000000;
	rays[35].y = 124.000000;
	rays[36].degree = 36;
	rays[36].distance = 85.211502;
	rays[36].x = 140.000000;
	rays[36].y = 126.000000;
	rays[37].degree = 37;
	rays[37].distance = 83.600243;
	rays[37].x = 140.000000;
	rays[37].y = 128.000000;
	rays[38].degree = 38;
	rays[38].distance = 81.215759;
	rays[38].x = 140.000000;
	rays[38].y = 130.000000;
	rays[39].degree = 39;
	rays[39].distance = 79.649231;
	rays[39].x = 140.000000;
	rays[39].y = 131.000000;
	rays[40].degree = 40;
	rays[40].distance = 78.102493;
	rays[40].x = 140.000000;
	rays[40].y = 133.000000;
	rays[41].degree = 41;
	rays[41].distance = 76.576759;
	rays[41].x = 140.000000;
	rays[41].y = 134.000000;
	rays[42].degree = 42;
	rays[42].distance = 75.073296;
	rays[42].x = 140.000000;
	rays[42].y = 135.000000;
	rays[43].degree = 43;
	rays[43].distance = 73.593475;
	rays[43].x = 140.000000;
	rays[43].y = 137.000000;
	rays[44].degree = 44;
	rays[44].distance = 72.138756;
	rays[44].x = 140.000000;
	rays[44].y = 138.000000;
	rays[45].degree = 45;
	rays[45].distance = 70.710678;
	rays[45].x = 140.000000;
	rays[45].y = 140.000000;
	rays[46].degree = 46;
	rays[46].distance = 70.007141;
	rays[46].x = 140.000000;
	rays[46].y = 140.000000;
	rays[47].degree = 47;
	rays[47].distance = 68.622154;
	rays[47].x = 140.000000;
	rays[47].y = 142.000000;
	rays[48].degree = 48;
	rays[48].distance = 67.941154;
	rays[48].x = 140.000000;
	rays[48].y = 142.000000;
	rays[49].degree = 49;
	rays[49].distance = 66.603302;
	rays[49].x = 140.000000;
	rays[49].y = 144.000000;
	rays[50].degree = 50;
	rays[50].distance = 65.299309;
	rays[50].x = 140.000000;
	rays[50].y = 145.000000;
	rays[51].degree = 51;
	rays[51].distance = 64.660652;
	rays[51].x = 140.000000;
	rays[51].y = 146.000000;
	rays[52].degree = 52;
	rays[52].distance = 64.031242;
	rays[52].x = 140.000000;
	rays[52].y = 147.000000;
	rays[53].degree = 53;
	rays[53].distance = 62.801273;
	rays[53].x = 140.000000;
	rays[53].y = 148.000000;
	rays[54].degree = 54;
	rays[54].distance = 62.201286;
	rays[54].x = 140.000000;
	rays[54].y = 149.000000;
	rays[55].degree = 55;
	rays[55].distance = 61.611687;
	rays[55].x = 140.000000;
	rays[55].y = 149.000000;
	rays[56].degree = 56;
	rays[56].distance = 60.464867;
	rays[56].x = 140.000000;
	rays[56].y = 151.000000;
	rays[57].degree = 57;
	rays[57].distance = 59.908264;
	rays[57].x = 140.000000;
	rays[57].y = 151.000000;
	rays[58].degree = 58;
	rays[58].distance = 59.363289;
	rays[58].x = 140.000000;
	rays[58].y = 152.000000;
	rays[59].degree = 59;
	rays[59].distance = 58.830265;
	rays[59].x = 140.000000;
	rays[59].y = 153.000000;
	rays[60].degree = 60;
	rays[60].distance = 57.801384;
	rays[60].x = 140.000000;
	rays[60].y = 154.000000;
	rays[61].degree = 61;
	rays[61].distance = 57.306194;
	rays[61].x = 140.000000;
	rays[61].y = 155.000000;
	rays[62].degree = 62;
	rays[62].distance = 56.824291;
	rays[62].x = 140.000000;
	rays[62].y = 156.000000;
	rays[63].degree = 63;
	rays[63].distance = 56.356010;
	rays[63].x = 140.000000;
	rays[63].y = 156.000000;
	rays[64].degree = 64;
	rays[64].distance = 55.901699;
	rays[64].x = 140.000000;
	rays[64].y = 157.000000;
	rays[65].degree = 65;
	rays[65].distance = 55.461697;
	rays[65].x = 140.000000;
	rays[65].y = 158.000000;
	rays[66].degree = 66;
	rays[66].distance = 55.036350;
	rays[66].x = 140.000000;
	rays[66].y = 158.000000;
	rays[67].degree = 67;
	rays[67].distance = 54.625999;
	rays[67].x = 140.000000;
	rays[67].y = 159.000000;
	rays[68].degree = 68;
	rays[68].distance = 54.230988;
	rays[68].x = 140.000000;
	rays[68].y = 160.000000;
	rays[69].degree = 69;
	rays[69].distance = 53.851646;
	rays[69].x = 140.000000;
	rays[69].y = 161.000000;
	rays[70].degree = 70;
	rays[70].distance = 53.488316;
	rays[70].x = 140.000000;
	rays[70].y = 161.000000;
	rays[71].degree = 71;
	rays[71].distance = 53.141319;
	rays[71].x = 140.000000;
	rays[71].y = 162.000000;
	rays[72].degree = 72;
	rays[72].distance = 52.810986;
	rays[72].x = 140.000000;
	rays[72].y = 163.000000;
	rays[73].degree = 73;
	rays[73].distance = 52.497620;
	rays[73].x = 140.000000;
	rays[73].y = 163.000000;
	rays[74].degree = 74;
	rays[74].distance = 52.201534;
	rays[74].x = 140.000000;
	rays[74].y = 164.000000;
	rays[75].degree = 75;
	rays[75].distance = 51.923019;
	rays[75].x = 140.000000;
	rays[75].y = 165.000000;
	rays[76].degree = 76;
	rays[76].distance = 51.662365;
	rays[76].x = 140.000000;
	rays[76].y = 165.000000;
	rays[77].degree = 77;
	rays[77].distance = 51.419842;
	rays[77].x = 140.000000;
	rays[77].y = 166.000000;
	rays[78].degree = 78;
	rays[78].distance = 51.195702;
	rays[78].x = 140.000000;
	rays[78].y = 167.000000;
	rays[79].degree = 79;
	rays[79].distance = 50.990196;
	rays[79].x = 140.000000;
	rays[79].y = 168.000000;
	rays[80].degree = 80;
	rays[80].distance = 50.803543;
	rays[80].x = 140.000000;
	rays[80].y = 168.000000;
	rays[81].degree = 81;
	rays[81].distance = 50.635956;
	rays[81].x = 140.000000;
	rays[81].y = 169.000000;
	rays[82].degree = 82;
	rays[82].distance = 50.635956;
	rays[82].x = 140.000000;
	rays[82].y = 169.000000;
	rays[83].degree = 83;
	rays[83].distance = 50.487621;
	rays[83].x = 140.000000;
	rays[83].y = 170.000000;
	rays[84].degree = 84;
	rays[84].distance = 50.358715;
	rays[84].x = 140.000000;
	rays[84].y = 170.000000;
	rays[85].degree = 85;
	rays[85].distance = 50.249378;
	rays[85].x = 140.000000;
	rays[85].y = 171.000000;
	rays[86].degree = 86;
	rays[86].distance = 50.159744;
	rays[86].x = 140.000000;
	rays[86].y = 172.000000;
	rays[87].degree = 87;
	rays[87].distance = 50.089920;
	rays[87].x = 140.000000;
	rays[87].y = 172.000000;
	rays[88].degree = 88;
	rays[88].distance = 50.039986;
	rays[88].x = 140.000000;
	rays[88].y = 173.000000;
	rays[89].degree = 89;
	rays[89].distance = 50.009998;
	rays[89].x = 140.000000;
	rays[89].y = 174.000000;
	for (int i = 0; i < 90; i++)
	{
		rays[i].x = rays[i].x / 10;
		rays[i].y = rays[i].y / 10;
	}

	return (rays);
}