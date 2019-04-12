void RMQ_init()
{
	for(int i = 1; i <= n; i++)
	{
		d_min[i][0] = a[i]; // 2^0 = 1
		d_max[i][0] = a[i];
	}
	for(int j = 1; (1<<j) <= n; j++) // 2^j <= n
	{
		for(int i = 1; i+(1<<j)-1 <= n; i++) // i+2^j-1 <= n
		{
			d_min[i][j] = min(d_min[i][j-1], d_min[i+(1<<(j-1))][j-1]);
			d_max[i][j] = max(d_max[i][j-1], d_max[i+(1<<(j-1))][j-1]);
		}
	}	
}
 
int RMQ_Min(int L, int R)
{
	int k = 0;
	while((1<<(k+1)) <= R-L+1) k++; // 如果 2^(k+1) <= R-L+1,那么k 还可以加 1 
	return min(d_min[L][k], d_min[R-(1<<k)+1][k]);
}
 
int RMQ_Max(int L, int R)
{
	int k = 0;
	while((1<<(k+1)) <= R-L+1) k++; // 如果 2^(k+1) <= R-L+1,那么k 还可以加 1 
	return max(d_max[L][k], d_max[R-(1<<k)+1][k]);
}
