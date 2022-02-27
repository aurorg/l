int sum( int n )
{
	int s;
	if(n<=0) return 0;
	else s=n+sum(n-1);
	return s;
}
