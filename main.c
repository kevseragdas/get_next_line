#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*k;
	int		fd1;
	
	fd1 = open("test1", O_RDONLY);
	(k = get_next_line(fd1));
	printf("fd1: %s", k);		
	free(k);


	close(fd1);
}
