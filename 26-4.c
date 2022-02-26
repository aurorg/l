double calc_pow( double x, int n )
{
	double t;
	if(n==1) return x;
	else t=x*calc_pow(x,n-1);
	return t;
}
