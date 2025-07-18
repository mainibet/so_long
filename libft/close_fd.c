/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:53:41 by albetanc          #+#    #+#             */
/*   Updated: 2025/05/02 13:53:45 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	close_fd(int fd)
{
	if (close(fd) == -1)
	{
		perror ("error closing fd");
		return (1);
	}
	return (0);
}
