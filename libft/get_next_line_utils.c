/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:07:00 by mimarque          #+#    #+#             */
/*   Updated: 2022/06/18 08:26:14 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Duplicate string s1 from index start utill index end.
	Memory for the new string is obtained with malloc, and can be freed with free.
*/
char	*ft_strldup(char *s1, int start, int end)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(end - start + 1);
	if (!ptr)
		return (NULL);
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = 0;
	return (ptr);
}

/*
	Allocates (with malloc) and returns a new string,
	result of the concatenation of s1 and s2
	S1 is freed
*/
char	*ft_strjoinfree(char *s1, char *s2)
{
	int		i;
	char	*str;
	char	*hld;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	size = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	hld = s1;
	if (s1)
		while (*s1)
			str[i++] = *s1++;
	if (s2)
		while (*s2)
			str[i++] = *s2++;
	str[i] = '\0';
	if (hld)
		free(hld);
	return (str);
}
