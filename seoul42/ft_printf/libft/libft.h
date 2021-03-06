/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 15:01:35 by japark            #+#    #+#             */
/*   Updated: 2020/04/13 13:52:49 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


void		ft_bzero(void *ptr, size_t num);
void		*memcpy(void *destination, const void  *source, size_t num);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *ptr, int value, size_t num);
void		*ft_memccpy(void *dest, const void *src, int c, size_t num);
void		*ft_memchr(void *ptr, int c, size_t num);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
size_t		ft_strlen(const char *str);
size_t      ft_strlcat(char *ptr1, const char *ptr2, size_t num);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		*ft_calloc(size_t elt_count, size_t elt_size);
char		*ft_strdup(char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);
char		*ft_strtrim(char const *s1, char const *set);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif