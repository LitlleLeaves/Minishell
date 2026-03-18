#ifndef	MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <termcap.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>

typedef enum	e_token_type
{
    COMMAND,
    PIPE,
    REDIR_OUT_TRUNC, 	// >
    REDIR_OUT_APP,		// >>
    REDIR_IN,			// <
    HEREDOC,			// <<

	ENVIRONMENT,
}				t_token_type;

typedef struct	s_token
{
    char            *value;
    t_token_type    type;
    struct s_token  *next;
	int				fd;
}				t_token;


//main
int		main_loop(void);

//read
char	*read_input(void);

//tokens
t_token	*make_new_token(int fd, char *value, t_token_type type);

//ft_helpers
char	*ft_substr(char *str);
int		ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif