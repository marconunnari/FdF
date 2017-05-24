/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:28:28 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/23 22:28:37 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_handler(int keycode, void *param)
{
	(void)param;
	ft_printf("key event %d\n", keycode);
	if (keycode == 53 || keycode == 65307)
		exit(0);
	return (0);
}
