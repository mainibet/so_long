/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:08:51 by albetanc          #+#    #+#             */
/*   Updated: 2025/01/22 13:01:18 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_str_utils(char *dst, const char *src, size_t dst_size, int flag)
{
	size_t	i;
	size_t	src_len;

	if (!src || ((flag == 0 && !dst) || (flag == 0 && dst_size == 0)))
		return (0);
	if (flag == 1)
	{
		i = 0;
		while (src[i])
			i++;
		return (i);
	}
	src_len = ft_str_utils(NULL, src, 0, 1);
	if (dst_size > 0)
	{
		i = 0;
		while (src[i] && i < dst_size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str || !c)
		return (NULL);
	while (*str)
	{
		if (*str == (char) c)
			return ((char *) str);
		str++;
	}
	if (*str == (char) c)
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	if (!src || !dst)
		return (0);
	src_len = ft_str_utils(NULL, src, 0, 1);
	dst_len = ft_str_utils(NULL, dst, 0, 1);
	i = 0;
	if (dst_size <= dst_len)
		return (dst_size + src_len);
	while (src[i] && i < (dst_size - dst_len -1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_str_utils(NULL, s1, 0, 1);
	len2 = ft_str_utils(NULL, s2, 0, 1);
	str = malloc ((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	if (!s1)
		ft_str_utils(str, s2, len2 + 1, 0);
	if (!s2)
		ft_str_utils(str, s1, len1 + 1, 0);
	ft_str_utils(str, s1, len1 + 1, 0);
	ft_strlcat(str, s2, len1 + len2 + 1);
	return (str);
}

char	*ft_process_str(char *join, char *c, int flag)
{
	size_t	start;
	size_t	len;
	char	*result;

	if (!join || !c)
		return (NULL);
	result = NULL;
	start = (c + 1) - join;
	if (flag == 0)
	{
		result = malloc((start + 1) * sizeof (char));
		if (!result)
			return (NULL);
		return ((ft_str_utils(result, join, start + 1, 0)), result);
	}
	if (flag == 1)
	{
		len = ft_str_utils(NULL, join + start, 0, 1);
		result = malloc ((len + 1) * sizeof (char));
		if (!result)
			return (free(result), NULL);
		ft_str_utils(result, join + start, len + 1, 0);
		return (result);
	}
	return (result);
}
