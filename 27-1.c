int f( int n )
{
	int t;
	if(n==0) return 0;
	else if(n==1) return 1;
	else t=f(n-2)+f(n-1);
	return t;
}
