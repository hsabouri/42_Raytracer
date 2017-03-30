/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:31:15 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/16 17:34:40 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H
# include <rt.h>

t_compnt		action_test(struct s_compnt compnt, t_env *env);
t_compnt		hover_test(struct s_compnt compnt, t_env *env);
t_compnt		idle_test(struct s_compnt compnt, t_env *env);

#endif