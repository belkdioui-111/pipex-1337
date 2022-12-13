#include "pipex.h"

// fun to split path from env variable



char **get_path(char **envp)
{
    int i;
    char **path;

    i=0;
    while(envp[i] != NULL)
    {
        if(ft_strncmp("PATH", envp[i], 4) == 0)
        {
            break;
        }
        i++;
    }
    envp[i]=ft_strtrim(envp[i],"PATH=");
    return(path=ft_split(envp[i],':'));
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    char **path;
    char **fcmd1;
    char **fcmd2;
    int i;
    char *cmd1[3];
    char *cmd2[3];
    int pid;
    int pipefd[2];
    int check=0;
    
    if(argc < 5)
        exit(EXIT_FAILURE);
            int fd1=open(argv[1], O_CREAT | O_RDONLY, 0644);
            if (fd1 == -1)
                perror(ft_strjoin("pipex: ", argv[1]));
            int fd2=open(argv[4],O_CREAT | O_WRONLY| O_TRUNC , 0644);
            if(fd2 == -1)
                exit(EXIT_FAILURE);
            path=get_path(envp);
            pipe(pipefd);
            pid=fork();
            if(pid == 0)
            {
                i=0;
                fcmd1=ft_split(argv[2], ' ');
                while(fcmd1[i])
                {
                    cmd1[i] = fcmd1[i];
                    i++;
                }
                cmd1[i]=NULL;
                i=0;
                while(path[i])
                {
                    path[i] = ft_strjoin(path[i],"/");
                    path[i] = ft_strjoin(path[i],*fcmd1);
                    if(access(path[i],F_OK) != -1)
                    {
                        if(access(path[i],X_OK) != -1)
                        {
                            if (fd1 == -1)
                                break ;
                            dup2(fd1,0);
                            dup2(pipefd[1],1);
                            close(pipefd[0]);
                            check=1;
                            execve(path[i],cmd1,NULL);
    
                        }      
                    }
                    i++;
                }
                if(check != 1)
                {
                    exit(127);
                }
            }
            else if(pid > 0)
            {
                wait(NULL);
                i=0;
                fcmd2=ft_split(argv[3], ' ');
                while(fcmd2[i])
                {
                    cmd2[i] = fcmd2[i];
                    i++;
                }
                cmd2[i]=NULL;
                printf("%s",*fcmd2);
                i=0;
                while(path[i])
                {
                    path[i] = ft_strjoin(path[i],"/");
                    path[i] = ft_strjoin(path[i],*fcmd2);
                    if(access(path[i],F_OK) != -1)
                    {
                        if(access(path[i],X_OK) != -1)
                        {
                            close(pipefd[1]);
                            dup2(fd2,1);
                            dup2(pipefd[0],0);
                            
                            check=1;
                            execve(path[i],cmd2,NULL);
                        }      
                }
                    i++;
                }
                if(check != 1)
                {
                    exit(127);
                }
                
            }
    exit(127);
}