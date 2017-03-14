/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:24:22 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/02 14:28:16 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_cl	feed_cl_kernels(t_cl cl)
{
	c_log("Creating OpenCL kernels...");
	//create kernels here and add them into s_kernels definiton (struct.h)
	cl.kernels.example = clCreateKernel(cl.program, "img_init", &cl.ret);
	c_log("Kernels created successfully!");
	return (cl);
}

static t_cl	init_cl_program(t_cl cl)
{
	int		fd;
	char	*source_str;
	char	*flags;
	size_t	source_size;

	flags = ft_strdup("-I includes -I lib/libvec/includes");
		source_str = ft_strnew(MAX_SOURCE_SIZE);
	c_log("Compiling OpenCL kernels...");
	fd = c_open_file("./kernels/kernels.cl");
	source_size = read(fd, source_str, MAX_SOURCE_SIZE);
	close(fd);
	cl.program = clCreateProgramWithSource(cl.context, 1,\
		(const char **)&source_str, (const size_t *)&source_size, &cl.ret);
	cl.ret = clBuildProgram(cl.program, 1, &cl.device_id, flags, NULL, NULL);
	if (cl.ret == 0)
		c_log("Compiled successfully!");
	else
		c_error("Kernel compilation error! Check cl.h for more informations.", cl.ret);
	cl = feed_cl_kernels(cl);
	free(source_str);
	return (cl);
}

t_cl		init_cl(void)
{
	t_cl cl;

	cl.ret = clGetPlatformIDs(1, &cl.platform_id, &cl.ret_num_platforms);
	cl.ret = clGetDeviceIDs(cl.platform_id, CL_DEVICE_TYPE_DEFAULT, 1,\
		&cl.device_id, &cl.ret_num_devices);
	cl.context = clCreateContext(NULL, 1, &cl.device_id, NULL, NULL, &cl.ret);
	cl.command_queue = clCreateCommandQueue(cl.context, cl.device_id, 0, &cl.ret);
	cl = init_cl_program(cl);
	return (cl);
}