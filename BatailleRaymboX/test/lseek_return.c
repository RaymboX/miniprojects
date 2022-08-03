#include <unistd.h>
#include <fcntl.h>

void	write_int(int val);

int	main()
{
	int	fd, ret;
	int	buffer;
	int	offset = -1;

	fd = open("brc_saves", O_RDONLY);
	while (++offset <= lseek(fd, 0, SEEK_END))
	{
		ret = lseek(fd, offset, SEEK_SET);
		write_int(ret);
		write (1, ":", 1);
		read (fd, &buffer, 1);
		write (1, &buffer, 1);
		write (1, "/", 1);
	}
	close (fd);
}

void	write_int(int val)
{
	char	c;

	if (val > 0)
	{
		c = val % 10 + '0';
		val /= 10;
		write_int(val);
		write (1, &c, 1);
	}
}	
