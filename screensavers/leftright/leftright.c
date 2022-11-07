#include <unistd.h>
#include <time.h>

void msleep(int millisecond)
{
	int i = 0;

	while (i++ < millisecond * 20)
		usleep(50);
}

int main(void)
{
	int x = 0;

	write(1, "O", 1);
	while (1)
	{
		while (++x < 100)
		{
			msleep(9);
			write(1, "\b O", 3);
		}
		while (--x > 0)
		{
			msleep(9);
			write(1, "\b \b\bO", 5);
		}
	}
	return (0);
}