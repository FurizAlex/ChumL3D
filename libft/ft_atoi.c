/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:03:33 by alechin           #+#    #+#             */
/*   Updated: 2024/11/29 12:10:16 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Name

atoi

Synopsis

#include <stdlib.h>

int atoi(const char *nptr);

Description

The atoi() function converts the initial portion of the string 
pointed to by nptr to int. The behavior is the same as

Return Value

The converted value
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
int	main()
{
	char	*str = "12345";
	char	*a2str = " -6789";
	char	*a3str = "42abc";
	int	num = ft_atoi(str);
	int	a2num = ft_atoi(a2str);
	int	a3num = ft_atoi(a3str);

	printf("first str: %s to int: %d\n", str, num);
	printf("second str: %s to int: %d\n", a2str, a2num);
	printf("third str: %s to int: %d\n", a3str, a3num);
	return (0);
}*/
