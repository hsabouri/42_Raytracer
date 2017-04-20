/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:31:15 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/20 15:07:32 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H
# include <rt.h>

t_compnt		hover_def(struct s_compnt compnt);

t_compnt		action_r(struct s_compnt compnt, t_env *env);
t_compnt		hover_r(struct s_compnt compnt, t_env *env);
t_compnt		idle_r(struct s_compnt compnt, t_env *env);

t_compnt		action_c(struct s_compnt compnt, t_env *env);
t_compnt		hover_c(struct s_compnt compnt, t_env *env);
t_compnt		idle_c(struct s_compnt compnt, t_env *env);

t_compnt		action_a(struct s_compnt compnt, t_env *env);
t_compnt		idle_a(struct s_compnt compnt, t_env *env);

t_compnt		action_del(struct s_compnt compnt, t_env *env);
t_compnt		idle_del(struct s_compnt compnt, t_env *env);

t_compnt		action_col(struct s_compnt compnt, t_env *env);
t_compnt		hover_col(struct s_compnt compnt, t_env *env);
t_compnt		idle_col(struct s_compnt compnt, t_env *env);

#endif
