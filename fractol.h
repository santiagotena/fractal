/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:13:07 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/18 14:01:04 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

/* Parameters */
#define MAX_ITERATIONS 80
#define WIDTH 900
#define HEIGHT 900

/* Libraries */
//Std libraries
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>

//Custom libraries
# include "libraries/mlx/mlx.h"
# include "libraries/ft_printf/libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"

/* Structs */
//MLX (new)
typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

//Images (data)
typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

//Fractal parameters 
typedef struct	s_fractol
{
	char		*f_name;
	double		min_r;
	double 		max_r;
	double		min_i;
	double		max_i;
	double		kr;
	double		ki;
}				t_fractol;

/* Functions */
// Fractals
void	mandelbrot(t_fractol *f, t_img *img, int x, int y, double cr, double ci);
void	julia(t_fractol *f, t_img *img, int x, int y, double zr, double zi);

// Help
void	print_help(void);

// Draw fractals
void	draw_fractal(t_fractol *f, t_img *img);

void	init_mandel();
void	init_julia(char **argv);

//Utils
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
double	ft_atod(char *arr);



#endif
