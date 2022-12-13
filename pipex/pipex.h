#ifndef _PIPEX_H
#define _PIPEX_H

#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
