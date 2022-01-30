/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:43:22 by whan              #+#    #+#             */
/*   Updated: 2022/01/30 00:56:09 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void
	error(char *message)
{
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	*ft_free_array(void **pointer, int size)
{
	int		index;

	index = 0;
	while (index < size && pointer[index])
	{
		ft_free(pointer[index]);
		index += 1;
	}
	ft_free(pointer);
	return ((void *) 0);
}

void	*ft_free(void *pointer)
{
	free(pointer);
	return ((void *) 0);
}
