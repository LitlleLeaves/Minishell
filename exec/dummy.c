#include "exec.h"

t_token	*create_token(char *value, t_token_type type)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	if (value)
		token->value = strdup(value);
	else
		token->value = NULL;
	token->type = type;
	token->next = NULL;
	return (token);
}

//dummy function to generate differnt lists to test before parsig is done
t_token	*ft_get_head()
{
	// Token array for easier initialization
    struct {
        char *value;
        t_token_type type;
        int fd;
    } token_data[] = {
        {"infile", REDIR_IN},
        {"grep 1", WORD},
        {NULL, PIPE},
        {"grep 2", WORD},
        {NULL, PIPE},
        {"wc -l", WORD},
        {"outfile", REDIR_OUT_TRUNCT},
    };
    
    int count = sizeof(token_data) / sizeof(token_data[0]);
    t_token *head = NULL;
    t_token *current = NULL;
    
    for (int i = 0; i < count; i++) {
        t_token *new = create_token(token_data[i].value, 
                                     token_data[i].type);
        if (!head) {
            head = new;
            current = head;
        } else {
            current->next = new;
            current = new;
        }
    }
	return (head);
}