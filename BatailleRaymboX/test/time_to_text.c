#include <time.h>
#include <unistd.h>
#include <stdio.h>

void	write_int(int number, int nbchar);

int	main()
{
	time_t	now;
	struct	tm *tm;

	now = time(0);
	if ((tm = localtime(&now)) == NULL)
	{
		printf("Error extracting time stuff\n");
		return (1);
	}

	printf("%04d-%02d-%02d %02d:%02d:%02d\n", tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
	write_int((int)tm->tm_year+1900, 4);
	write(1, "-", 1);
	write_int((int)tm->tm_mon+1, 2);	
	write(1, "-", 1);
	write_int((int)tm->tm_mday, 2);	
	write(1, " ", 1);
	write_int((int)tm->tm_hour, 2);	
	write(1, ":", 1);
	write_int((int)tm->tm_min, 2);	
	write(1, ":", 1);
	write_int((int)tm->tm_sec, 2);	
	write(1, "\n", 1);
	return (0);
}

void	write_int(int number, int nbchar)
{
	char	c;
	
	if (nbchar != 0)
	{
		c = number % 10 + '0';
		number /= 10;
		write_int(number, --nbchar);
		write(1, &c, 1);
	}
}
