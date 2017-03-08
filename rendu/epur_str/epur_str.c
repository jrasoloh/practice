
#include <unistd.h>

void        ft_putchar(char c)
{
    write(1, &c, 1);
}

int         ft_length(char *str)
{
    int     len;
    int     i;
    
    len = 0;
    i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] != ' ' && str[i] != '\t')
            && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
            len = i;
        i++;
    }
    return (len);
}

void        ft_epur(char *str)
{
    int     i;
    
    i = 0;
    while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
        i++;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\t')
            {
                ft_putchar(str[i]);
                if ((str[i + 1] == ' ' || str[i + 1] == '\t') && i < ft_length(str))
                    ft_putchar(' ');
            }
        i++;
    }
    ft_putchar('\n');
}

int         main(int argc, char **argv)
{
    if (argc != 2 || !argv[1])
    {
        ft_putchar('\n');
        return (1);
    }
    else
        ft_epur(argv[1]);
    return (0);
}
