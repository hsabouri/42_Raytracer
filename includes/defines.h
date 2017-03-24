/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:24:22 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/20 13:15:44 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H
# include "key_define.h"
# define PI 3.141592653
# define EPSILON 0.000001
# define DEPTH_MAX 3
# define HEIGHT 800
# define LENGTH 800

/* Error codes */

# define MALLOC_FAILED 1
# define PARSING_ERROR 10
# define AMBIENT 0.15

/* Mlx and X-server defines */

# define KEYPRESSEVENT 2
# define KEYPRESSMASK (1L << 0)
# define BUTTONPRESS 4
# define BUTTONRELEASE 5

# define KEYRELEASEEVENT 3
# define KEYRELEASEMASK (1L << 1)
# define POINTERMOTIONMASK (1L<<6)
# define MOTIONNOTIFY 6
# define DESTROYNOTIFY 17
# define STRUCTURENOTIFYMASK (1L<<17)
# define BUTTONPRESSMASK (1L<<2)
# define BUTTONRELEASEMASK (1L<<3)


/* Mouse enum and defines */

typedef enum	e_status
{
	ACTION,
	IDLE,
	HOVER
}				t_status;

/* enum for camera
 * movement and rotations
 */

typedef enum	e_dir
{
	FRONT,
	BACK,
	RIGHT,
	LEFT,
	DOWN,
	UP
}				t_dir;

/* enum for
 * camera control
 */

typedef enum	e_mode
{
	MOVEMENT,
	ROTATION
}				t_mode;

/* t_type is an enum for
 * type of object
 *
 * Backslah should always be the
 * Last Element in the array
 */

typedef enum	e_type
{
	SPHERE,
	PLANE,
	CONE,
	CYLINDER,
	POLYGON,
	MESH,
	BACKSLASH
}				t_type;

typedef enum	e_ltype
{
	SPOT,
	OMNI,
	NOLIGHT
}				t_ltype;

/* filter is the enum
 * for applied filters
 */

typedef enum	e_filt
{
	NONE = 0,
	NB = 456451,
	SEPIA = 456452,
	RED = 456453,
	GREEN = 456454,
	BLUE = 456455,
	NEG = 456456
}				t_filt;

typedef enum	e_ttype
{
	NOTEX,
	IMAGE,
	BRICKS,
	CHECKER,
	NOISE,
	WOOD,
	MARBLE
}				t_ttype;

#endif
