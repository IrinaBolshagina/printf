#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_print_s(char *str, t_arg *param)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (param->precision >= 0 && param->precision < strlen)
	{
		strlen = param->precision;
	}
	if (param->flag == '-')
	{
		ft_putstr(str, strlen, param);
		ft_put_width(strlen, param);
	}
	else
	{
		ft_put_width(strlen, param);
		ft_putstr(str, strlen, param);
	}
}

void	ft_print_c(char c, t_arg *param)
{
	if (param->flag == '-')
	{
		ft_putchar(c, param);
		ft_put_width(1, param);
	}
	else
	{
		ft_put_width(1, param);
		ft_putchar(c, param);
	}
}
