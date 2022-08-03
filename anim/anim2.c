#include <unistd.h>
#include <stdio.h>
#include <conio.h>

void	ft_screen_refresh(int row, int col, int rowscreen);
int main()
{
	char buf = 'e';
	int row = 20;
	int col = 20;
	int rowscreen = 40;
	
	buf = 'e';
	while (buf != 'q')
	{
		buf = 'e';
		if (kbhit())
			buf = getch();
		switch (buf)
		{
			case 'w':
				row -= 1;
				break;
			case 's':
				row += 1;
				break;
			case 'a':
				col -= 1;
				break;
			case 'd':
				col += 1;
				break;
		}
		ft_screen_refresh(row, col, rowscreen);
	}
}

void	ft_screen_refresh(int row, int col, int rowscreen)
{
	int i = 0;

	while (i++ != row)
		write (1, "\n", 1);
	i = 0;
	while (i++ != col)
		write(1, " ", 1);
	write(1, "X", 1);
       	i = 0;
	while (i++ != rowscreen - row)
		write (1, "\n", 1);
}

