/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:14:07 by eduribei          #+#    #+#             */
/*   Updated: 2024/06/20 23:50:36 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stddef.h>  // Ensure this is included first for size_t
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <bits/posix1_lim.h>


// Check if BUFFER_SIZE is already defined during compilation
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4 // Default buffer size if not defined externally
# endif

// Function declarations
char    *get_next_line(int fd);
char	*ft_strdup(char *s);
size_t  ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
size_t ft_strlcpy(char *dest, const char *src, size_t size);

#endif // HEADER_H
