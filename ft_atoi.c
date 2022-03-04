/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:37:34 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/01/03 15:21:36 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_getnbr(char *str, int sign)
{
	int		index;
	int		res;

	res = 0;
	index = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10;
		res = res + (str[index] - 48);
		index++;
	}
	if (index > 19 && sign == -1)
		return (0);
	if (index > 19 && sign == 1)
		return (-1);
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int	index;
	int	sign;

	index = 0;
	sign = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	return (ft_getnbr((char *)str + index, sign));
}
