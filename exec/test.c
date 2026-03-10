#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int fd_in = open("a", O_RDONLY);
	if (fd_in == -1)
	{
			printf("%s: %s\n", "a", strerror(errno));
	}
}
