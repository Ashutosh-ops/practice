#include <stdio.h>
int main(int argc, const char **argv)
{
	int height,n,q,i;
	scanf("%d%d%d", &height,&n,&q);
	int h_i[n],s_i[n],e_i[n];
	for(i=0;i<n;i++){
		scanf("%d%d%d",&h_i[i],&s_i[i],&e_i[i]);
	}
	for(int j=0;j<q;j++)
	{
		int w,k;
		scanf("%d%d",&w,&k);
		int count=0;
		for(i=0;i<n;i++) //O(n) Time_complexity
		{
			if(k>=s_i[i] && k<=e_i[i] && w>h_i[i])
			{
				  count++;
			}
			else if(k>=s_i[i] && k<=e_i[i])
			{
				printf("NO\n");
			       break;
			}
			// (y>=s[i] && y<=e[i] && x>h[i])? (flag++) : (y>=s[i] && y<=e[i])? (printf("NO\n")) : (printf("NO\n"));
			else if(k<=height)
			{
				count++;
			}
			else
			{
				printf("NO\n");
				break;
			}
		}
		if (count==n)
		{
			printf("YES\n");
		}
	}
	return 0;
} 