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
// < infile grep . | < infile > outfile wc -l < infile2 > outfile2 | wc -l > outfile
typedef enum	e_token_type
{
    WORD,
    PIPE,
    REDIR_OUT_TRUNCT, 	// >
    REDIR_OUT_APPEND,	// >>
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




// 1111111111111111111111111111111
#endif