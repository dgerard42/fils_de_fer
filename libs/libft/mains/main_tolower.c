/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:00:40 by dgerard           #+#    #+#             */
/*   Updated: 2017/03/09 19:43:55 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	int inputs[9] = {
		'\t', 'd',
		98, 2147483648,
		'9', 'Z', ' ', 'A', 105 
	};

	int i = 0;
	printf("TESTS:\n");
	while (i < 9)
	{
		int a = tolower(inputs[i]);
		int b = ft_tolower(inputs[i]);
		char *test = a == b ? "\x1B[32mPASS" : "\x1B[31mFAIL";
		printf("%2d: %12d - %12d - %12d - %s\x1B[0m\n", i, inputs[i], a, b, test);
		i++;
	}
	return (0);
}
