t_token	**tokenize_input(char *str)
{
	t_token **head;
	t_token	*current;
	int		counter;
	int		start;

	head = current;
	counter = 0;
	while (str[counter] != '\0')
	{
		start = counter;
		current = classify_and_make(str + start);
		while ()
	}
}

t_token	*classify_and_make(char *line)
{
	char	*value;
	int		counter;
	int		start;
	t_token	*token;

	start = 0;
	counter = 0;
	if (check_delimeters(line[counter]) == 0) //command
	{
		while (check_delimeters(line[counter]) == 0)
			counter++;
		value = ft_substr(line, 0, counter);
		if (!value)
			return (printf("substr error"), NULL);
		token = make_new_token(-2, value, COMMAND);
		free(value);
	}
	else if (line[counter] == "|") //pipe
	{
		value = ft_strdup("|");
		if (!value)
			return (printf("strdup error"), NULL);
		token = make_new_token(-2, value, PIPE);
	}
 	else if (line[counter] == ">" && line[counter + 1] == ">") //append
	{
		while (line[counter] != ">" && line[counter] != " ")
		{
			start++;
			if (line[counter] == "'\0")
				return (printf("huh??"), NULL);
		}
		while (line[counter] != )
		token = make_new_token(value, "|", REDIR_OUT_APP);
	}
 	else if (line[counter] == "<" && line[counter + 1] == "<") // heredeoc
	{
		token = make_new_token();
		
	}
 	else if (line[counter] == ">") // truncate
	{
		token = make_new_token();
		
	}
 	else if (line[counter] == "<") // input
	{
		token = make_new_token();
		
	}
}

int		check_delimeters(char c)
{
	if (c == "|" && c == ">" && c == ">>" && c == ">" && c == "<<")
		return (1);
	return (0);
}

char	*get_line(void)
{
	char	*line;
	char	*temp;
	int		read_return;

	read_return = 0;
	temp = malloc(1024 * sizeof(char));
	if (!temp)
		return (printf("malloc fail"), 0);
	while (temp != NULL)
	{
		read_return	= read(0, line, 1024);
		if (read_return == -1)
			return (printf("read error"), NULL);
		line[read_return] = '\0';
		line = strjoin(line, temp);
		free(temp);
		if (!line)
			return (printf("join error"), 0);
	}
	return (line);
}

