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

void    *ft_calloc(size_t nmemb, size_t size)
{
    unsigned char   *ptr;
    size_t          total_size;

    if (nmemb == 0 || size == 0)
        return (malloc(0));
    if (nmemb > SIZE_MAX / size)
        return (NULL);
    total_size = nmemb * size;
    ptr = malloc(total_size);
    if (ptr == NULL)
    {
        return (NULL);
    }
    while (total_size--)
    {
        *ptr = 0;
        ptr++;
    }
    return ((void *)(ptr - nmemb * size));
}

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

char *ft_strjoin(char *s1, char *s2)
{
    size_t  ns_len;
    size_t  s1_len;
    size_t  s2_len;
    char    *newstring;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    ns_len = s1_len + s2_len;

    newstring = (char *)malloc((ns_len + 1) * sizeof(char));
    if (newstring == NULL)
        return (NULL);

    ft_strlcpy(newstring, s1, s1_len + 1);
    ft_strlcpy(newstring + s1_len, s2, s2_len + 1);
    free(s1);
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





























/*
char	*ft_strchr(char *str, int c)
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


void	ft_bzero(void *s, size_t n)
{
	size_t			a;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	a = 0;
	while (a < n)
	{
		*ptr = 0x00;
		ptr++;
		a++;
	}
}

char	*ft_strdup(char *s)
{
	int		a;
	int		len;
	char	*dest;

	len = ft_strlen((char *)s);
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	a = 0;
	while (a < len)
	{
		dest[a] = s[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
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
	memmove(newstring, (char *)s1, s1_len);
	memmove(&newstring[s1_len], (char *)s2, s2_len);
	newstring[ns_len] = '\0';
	return (newstring);
}


void *ft_memmove(void *dest, void *src, size_t n)
{
    unsigned char *source = (unsigned char *)src;
    unsigned char *destiny = (unsigned char *)dest;
    unsigned char *temp;
    size_t i;

    if (dest == src)
        return dest;

    temp = malloc(n * sizeof(unsigned char));
    if (temp == NULL) // Check if malloc failed
        return NULL;

    // Copy from source to temp
    for (i = 0; i < n; i++)
    {
        temp[i] = source[i];
    }

    // Copy from temp to destiny
    for (i = 0; i < n; i++)
    {
        destiny[i] = temp[i];
    }

    free(temp);
    return dest;
}




size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	copy_len;
	size_t	src_len;
	size_t	a;

	src_len = ft_strlen((char *)src);
	if (size > 0)
	{
		if (src_len == 0)
			copy_len = 0;
		else if (src_len >= size)
			copy_len = size - 1;
		else
			copy_len = src_len;
		a = 0;
		while (a < copy_len)
		{
			dest[a] = src[a];
			a++;
		}
		dest[copy_len] = '\0';char	*ft_strchr(const char *str, int c)
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
	}
	return (src_len);
}

*/