#include <unistd.h>
#include <time.h>
#include <stdlib.h>

typedef struct s_vars
{
        int coord[2];
        int dir[2];
        int limit[2];
        char wall;
        char ball;
}               t_vars;


void set_vars(t_vars *v)
{
        v->coord[0] = 3;
        v->coord[1] = 5;
        v->dir[0] = -1;
        v->dir[1] = 1;
        v->limit[0] = 25;
        v->limit[1] = 30;
        v->wall = '#';
        v->ball = 'O';
}

void msleep(int millisecond)
{
        int i = -1;

        while (++i < millisecond * 20)
                usleep(50);
}

void set_dir(t_vars *v)
{
        int i;

        i = -1;
        while (++i < 2)
        {
                if (v->coord[i] + v->dir[i] <= 0)
                        v->dir[i] = 1;
                else if (v->coord[i] + v->dir[i] >= v->limit[i])
                        v->dir[i] = -1;
                v->coord[i] += v->dir[i];
        }
}

void draw(t_vars *v)
{
        int xy[2];

        system("clear");
        xy[1] = -1;
        while (++xy[1] <= v->limit[1])
        {
                xy[0] = -1;
                while (++xy[0] <= v->limit[0])
                {
                        if (xy[0] == 0 || xy[0] == v->limit[0]
                                || xy[1] == 0 || xy[1] == v->limit[1])
                                write(1, &v->wall, 1);
                        else if (xy[0] == v->coord[0] && xy[1] == v->coord[1])
                                write(1, &v->ball, 1);
                        else
                                write(1, " ", 1);
                }
                write(1, "\n", 1);
        }
}


int main(void)
{
        t_vars v;

        set_vars(&v);
        while (1)
        {
                draw(&v);
                set_dir(&v);
                msleep(20);
        }
}