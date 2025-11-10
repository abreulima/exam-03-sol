int min_to_remove(char *s)
{
	int open;
	int close;
	
	open = 0;
	close = 0;
	for(int i = 0; s[i]; i++)
	{
	
		if (s[i] == '(')
			open++;
		
		if (s[i] == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
	}
	return (open + close);
}


void solve(int index, int to_remove, int removed, char *s)
{

	if (removed > to_remove)
		return;
	
	if (s[index] == '\0')
	{
		if (removed == to_remove && min_to_remove(s) == 0)
			puts(s);
		return ;
	}	

	if (s[index] == '(' || s[index] == ')')
	{
		char temp = s[index];
		s[index] = ' ';
		solve(index + 1, to_remove, removed + 1, s);
		s[index] = temp;
	}
	solve(index + 1, to_remove, removed, s);
}

int main()
{

	char s[100] = "( ( ) ( ( ) (";
	if (min_to_remove(s) == 0)
	{
		puts(s);
		return 0;
	}
	solve(0, min_to_remove(s), 0, s);
	return 0;


}

