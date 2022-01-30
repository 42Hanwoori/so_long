/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:11:06 by whan              #+#    #+#             */
/*   Updated: 2022/01/31 01:39:37 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(void *pointer)
{
	free(pointer);
	return ((void *) 0);
}

void	*ft_free_array(void **pointer, t_i32 size)
{
	t_i32	index;

	index = 0;
	while (index < size && pointer[index])
	{
		ft_free(pointer[index]);
		index += 1;
	}
	ft_free(pointer);
	return ((void *) 0);
}
