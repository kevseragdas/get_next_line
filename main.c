#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*k;
	int		fd1;
	int		fd2;
	int		fd3;

	// int		i;
	// i = 9;
	fd1 = open("test1", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	fd3 = open("test3", O_RDONLY);
	// while (i)
	// {
	// 	k = get_next_line(fd1);
	// 	printf("%s", k);
	// 	k = get_next_line(fd2);
	// 	printf("%s", k);
	// 	k = get_next_line(fd3);
	// 	printf("%s", k);
	// 	i--;
	// }
	// close(fd1);
	// close(fd2);
	// close(fd3);
	// return (0);
	while (1)
	{
		k = get_next_line(fd1);
		printf("fd1: %s", k);
		free(k);
		k = get_next_line(fd2);
		printf("fd2: %s", k);
		free(k);
		k = get_next_line(fd3);
		printf("fd3: %s", k);
		free(k);
	}
}
