#include <stdio.h>
#include <math.h>

int MenorComplementar(int M[100][100], int N)
{
	if (N==1)
	{
		return M[0][0];
	}
	int i, j, k, M2[N][100][100], Lp[100], det=0, M3[100][100];
	for(i = 0; i<N; i++)
	{
		for(j = 1; j<N; j++)
		{
			for(k = 0; k<N-1; k++)
			{
				if(k<i)
					M2[i][j][k]=M[j][k];

				if(k>=i)
					M2[i][j][k]=M[j][k+1];
			}
		}
	}
	

	for(i = 0; i<N; i++)
	{
		for(j = 0; j<N-1; j++)
		{
			for(k = 0; k<N-1; k++)
			{
				M3[j][k] = M2[i][j+1][k];
			}
		}
		Lp[i]= M[0][i]*MenorComplementar(M3,N-1)*pow((-1),i);
	}
	for(i = 0; i<N; i++)
	{
		det+=Lp[i];
	}
	return det;
}


int main ()
{
	int N, i, j, det, M[100][100];
	scanf("%d", &N);
	for(i = 0; i<N; i++)
	{
		for(j = 0; j<N; j++)
		{
			scanf("%d", &M[i][j]);
		}
	}
	
	det = MenorComplementar(M, N);
	printf("%d", det);
	
	return 0;
}
