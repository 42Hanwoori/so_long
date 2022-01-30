/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:42:26 by whan              #+#    #+#             */
/*   Updated: 2022/01/30 00:57:33 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_file_extension(char **arguments)
{
	if (ft_strncmp(".ber", arguments[1] + (ft_strlen(arguments[1]) - 4), 4))
		error("invalid file extension");
}

static void	check_number_of_arguments(int number_of_arguments)
{
	if (number_of_arguments != 2)
		error("invalid number of arguments");
}

void		check_arguments(int number_of_arguments, char **arguments)
{
	check_number_of_arguments(number_of_arguments);
	check_file_extension(arguments);
}
