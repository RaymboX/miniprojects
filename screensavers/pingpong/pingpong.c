#include <unistd.h>
#include <time.h>

int main(int argc, char **argv, char **envp)
{
	sleep(1);
	write(1, &argv[0][2], 4);
	write(1, " ", 1);
	if (argv[0][3] == 'i')
		argv[0][3] = 'o';
	else
		argv[0][3] = 'i';
	execve(argv[0], argv, envp);
	return (0);
}
