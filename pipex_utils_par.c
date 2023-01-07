/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_par.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:35:24 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/01/04 08:20:34 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_par(char **cmd, int *pipefd, t_list *data, char *path)
{
	close(pipefd[1]);
	dup2(data->fd[1], 1);
	dup2(pipefd[0], 0);
	close(data->fd[1]);
	execve(path, cmd, data->envp);
	return (1);
}

int	exec_s_d_quotes_p(int pipefd[2], t_list *data, char **path, char *cmd)
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
			return (exec_par(cmd1, pipefd, data, path[i]));
		}
		i++;
	}
	free_all(fcmd1);
	return (0);
}

void	exec_path_p(int pipefd[2], t_list *data, char *cmd)
{
	char	*cmd1[2];
	int		check;

	check = 0;
	cmd1[0] = cmd;
	cmd1[1] = NULL;
	if (access(cmd, F_OK | X_OK) == 0)
		exec_par(cmd1, pipefd, data, cmd);
	else
	{
		perror(cmd);
		exit(126);
	}
}

int	exec_nor_cmd_p(char *cmd, char **path, t_list *data, int pipefd[2])
{
	char	**fcmd2;
	char	*cmd2[3];
	int		i;
	int		check;

	i = 0;
	check = 0;
	fcmd2 = ft_split(cmd, ' ');
	while (fcmd2[i])
	{
		cmd2[i] = fcmd2[i];
		i++;
	}
	cmd2[i] = NULL;
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], *fcmd2);
		check = exec_nor_cmd_pp(path[i], data, pipefd, cmd2);
		i++;
	}
	free_all(fcmd2);
	return (check);
}

int	exec_nor_cmd_pp(char *path, t_list *data, int *pipefd, char *cmd[3])
{
	int	check;

	check = 0;
	if (access(path, F_OK | X_OK) != -1)
	{
		dup2(data->fd[1], 1);
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		check = 1;
		execve(path, cmd, data->envp);
	}
	return (check);
}
