typedef struct		s_list
{
	struct s_list	*next;
	void		*data;
}			t_list;

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}
