norm_output=$(~/.norminette/norminette.rb)
printf "%s" "$norm_output"
grep "Error" <<< "$norm_output" > /dev/null
if [ $? == 0 ]; then
	printf "%b" "\n\nFix norm and try again\n";
elif make debug ; then
	valgrind --leak-check=yes --track-origins=yes ./minishell
fi