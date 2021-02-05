if make debug ; then
	valgrind --leak-check=yes --track-origins=yes ./minishell
fi
