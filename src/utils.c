/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:44:12 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/27 14:42:34 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	white_space(char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
		count++;
	}
	return (count);
}

int	ft_atoi(char *str)
{
	long long int	result;
	long long int	resultcpy;
	int				sign;
	int				i;

	result = 0;
	sign = 1;
	i = 0 + white_space(str);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		resultcpy = result;
		result = ((result * 10) + (str[i] - 48) * sign);
		if (result < resultcpy && sign == 1)
			return (-1);
		if (result > resultcpy && sign == -1)
			return (0);
		i++;
	}
	return ((int)result);
}

int get_current_milliseconds(void) 
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}