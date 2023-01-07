/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:49:38 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/01/04 08:30:51 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_child(char **cmd, int *pipefd, t_list *data, char *path)
{
	close(pipefd[0]);
	dup2(data->fd[0], 0);
	dup2(pipefd[1], 1);
	close(data->fd[0]);
	execve(path, cmd, data->envp);
	return (1);
}

int	exec_s_d_quotes_c(int pipefd[2], t_list *data, char **path, char *cmd)
{
	char	*str1;
	char	**fcmd1;
	char	*cmd1[3];
	int		i;

	str1 = s_d_quotes(cmd);
	fcmd1 = ft_split(cmd, ' ');
	cmd1[0] = fcmd1[0];
	cmd1[1] = str1;
	cmd1[2] = NULL;
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd1[0]);
		if (access(path[i], F_OK | X_OK) != -1)
		{
			return (exec_child(cmd1, pipefd, data, path[i]));
		}
		i++;
	}
	free_all(fcmd1);
	return (0);
}

void	exec_path_c(int pipefd[2], t_list *data, char *cmd)
{
	char	*cmd1[2];
	int		check;

	check = 0;
	cmd1[0] = cmd;
	cmd1[1] = NULL;
	if (access(cmd, F_OK | X_OK) == 0)
		exec_child(cmd1, pipefd, data, cmd);
	else
	{
		perror(cmd);
		exit(126);
	}
}

int	exec_nor_cmd_c(char *cmd, char **path, t_list *data, int pipefd[2])
{
	int		i;
	char	*cmd1[3];
	char	**fcmd1;
	int		check;

	i = 0;
	check = 0;
	fcmd1 = ft_split(cmd, ' ');
	while (fcmd1[i])
	{
		cmd1[i] = fcmd1[i];
		i++;
	}
	cmd1[i] = NULL;
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], *fcmd1);
		check = exec_nor_cmd_cc(path[i], data, pipefd, cmd1);
		i++;
	}
	free_all(fcmd1);
	return (check);
}

int	exec_nor_cmd_cc(char *path, t_list *data, int *pipefd, char *cmd1[3])
{
	if (access(path, F_OK | X_OK) != -1)
	{
		dup2(data->fd[0], 0);
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		execve(path, cmd1, data->envp);
	}
	return (0);
}
