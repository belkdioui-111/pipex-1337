/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:18:56 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/01/04 08:00:25 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<unistd.h>
# include<sys/wait.h>
# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>

typedef struct s_list
{
	int		fd[2];
	char	**envp;
}t_list;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*s_d_quotes(char *str);
char	**get_path(char **envp);
int		exec_child(char **cmd, int *pipefd, t_list *data, char *path);
int		exec_s_d_quotes_c(int pipefd[2], t_list *data, char **path, char *cmd);
void	exec_path_c(int pipefd[2], t_list *data, char *cmd);
int		exec_nor_cmd_c(char *cmd, char **path, t_list *data, int pipefd[2]);
int		exec_nor_cmd_cc(char *path, t_list *data, int *pipefd, char *cmd[3]);
int		exec_par(char **cmd, int *pipefd, t_list *data, char *path);
int		exec_s_d_quotes_p(int pipefd[2], t_list *data, char **path, char *cmd);
void	exec_path_p(int pipefd[2], t_list *data, char *cmd);
int		exec_nor_cmd_p(char *cmd, char **path, t_list *data, int pipefd[2]);
int		exec_nor_cmd_pp(char *path, t_list *data, int *pipefd, char *cmd[3]);
void	cmd_not_f(char *cmd);
void	free_all(char **str);

#endif