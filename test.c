#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDWR);
	if (fd >= 0)
		write(fd, "hello\n", 6);
	else
		write(1, "path not found\n", 15);
	return 0;
}
