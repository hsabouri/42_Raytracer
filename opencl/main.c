/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:24:22 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/02 14:28:16 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl.h"

int main(void)
{
	t_cl 	cl;
	int		max[3] = {CL_DEVICE_MAX_WORK_ITEM_SIZES};

	cl.ret = clGetPlatformIDs(1, &cl.platform_id, &cl.ret_num_platforms);
	printf("ret: clGetPlatformIDs: %d\n", cl.ret);
	cl.ret = clGetDeviceIDs(cl.platform_id, CL_DEVICE_TYPE_DEFAULT, 1,
		&cl.device_id, &cl.ret_num_devices);
	printf("ret: clGetDeviceIDs: %d\n", cl.ret);
	printf("x: %d, y: %d, z: %d\n\
max compute units: %d\n\
max work item dimension: %d\n\
max work group size: %d\n", max[0], max[1], max[2],
		CL_DEVICE_MAX_COMPUTE_UNITS,
		CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS,
		CL_DEVICE_MAX_WORK_GROUP_SIZE);

	return (0);
}