// doit etre utiliser avec seulement des majuscules

#include <unistd.h>
#include <fcntl.h>

void	ft_put_offset(int offset_x);

void	ft_print_letter35(char *str, int offset_x)
{
	int	l;
	int	y;
	int	x;
	int	fd;
	int	fo; // file_offset
	int	buffer;

	fd = open("letter35", O_RDONLY);
	y = 0;
	while (y < 5) //pour les 5 row de la lettre
	{
		ft_put_offset(offset_x);
		l = 0;
		while (str[l]) // pour chaque lettre
		{
			fo = (str[l] - 'A') * 5 * 4 + 4 * y;
			lseek(fd, fo, SEEK_SET);
			x = -1;
			while (++x < 3)
			{
				read (fd, &buffer, 1);
				write (1, &buffer, 1);
			}
			write (1, "   ", 3);
			l++;
		}
		write (1, "\n", 1);
		y++;
	}
	close (fd);
}

void	ft_put_offset(int offset_x)
{
	int	x = -1;

	while (++x < offset_x)
		write (1, " ", 1);
}
