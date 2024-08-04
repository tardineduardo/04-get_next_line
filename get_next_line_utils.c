/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:48:29 by eduribei          #+#    #+#             */
/*   Updated: 2024/06/20 23:51:01 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strdup(const char *s)
{
	int		a;
	int		len;
	char	*dest;

	len = ft_strlen((char *)s);
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	a = 0;
	while (a < len + 1)
	{
		dest[a] = s[a];
		a++;
	}
	return (dest);
}

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t  copy_len;
    size_t  src_len;
    size_t  i;

    src_len = ft_strlen((char *)src);
    if (size > 0)
    {
        if (src_len == 0)
            copy_len = 0;
        else if (src_len >= size)
            copy_len = size - 1;
        else
            copy_len = src_len;
        
        i = 0;
        while (i < copy_len)
        {
            dest[i] = src[i];
            i++;
        }
        dest[copy_len] = '\0';
    }
    return (src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	ns_len;
	size_t	s1_len;
	size_t	s2_len;
	char	*newstring;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	ns_len = s1_len + s2_len;
	newstring = malloc((ns_len + 1) * sizeof(char));
	if (newstring == (NULL))
		return (NULL);
    ft_strlcpy(newstring, s1, s1_len + 1);
    ft_strlcpy(newstring + s1_len, s2, s2_len + 1);
	newstring[ns_len] = 0;
	return (newstring);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	while (*str != '\0' || a == '\0')
	{
		if (*str == a)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

