/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:34:04 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/01/04 08:05:22 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*s_d_quotes(char *str)
{
	int		i;
	int		len;
	char	*arg;

	i = 0;
	len = ft_strlen(str);
	while ((i < len) && ((str[i] != '\'') && (str[i]) != '\"'))
		i++;
	while ((len > 0) && ((str[len] != '\'') && (str[len]) != '\"'))
		len--;
	arg = ft_substr(str, i + 1, len - i - 1);
	return (arg);
}

char	**get_path(char **envp)
{
	int		i;
	char	**path;
	int		check;

	i = 0;
	check = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			check = 1;
			break ;
		}
		i++;
	}
	if (check == 0)
		envp[i] = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin";
	envp[i] = ft_strtrim(envp[i], "PATH=");
	return (path = ft_split(envp[i], ':'));
}

void	cmd_not_f(char *cmd)
{
	write(2, "pipex: ", 7);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	exit(127);
}

void	free_all(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
