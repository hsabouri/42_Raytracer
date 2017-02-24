/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:24:22 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/24 11:46:40 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H
# define PI 3.141592653
# define EPSILON 0.000001
# define DEPTH_MAX 3
# define HEIGHT 1024
# define LENGTH 1024
# define KEY_ES 53
# define KEY_AUP 126
# define KEY_ADN 125
# define KEY_ALF 123
# define KEY_ART 124
# define KEY_PL 69
# define KEY_MN	78
# define KEY_R	15
# define KEY_S	1

/* Error codes */

# define MALLOC_FAILED 1

# define AMBIENT 0.15

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

#endif
