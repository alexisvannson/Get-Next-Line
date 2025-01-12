/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:50:28 by avannson          #+#    #+#             */
/*   Updated: 2025/01/12 12:50:18 by avannson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stddef.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

size_t  ft_strlen(const char *str);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_getline(char *stash);
char    *ft_keep(const char *str, int search_str);
char    *ft_strdup(const char *s1);

#endif
