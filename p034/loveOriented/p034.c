#include <stdio.h>
#include <string.h>


int alphabet[26];
int alphabet2[26];

int main(void)
{
		char buf[1001];
		char buf2[1001];

		while(scanf("%s", buf) != -1)
		{
				int i,j;
				scanf("%s", buf2);

				i = 0;
				memset(alphabet, 0, sizeof(alphabet));
				while(buf[i] != 0)
				{
						alphabet[buf[i] - 97] += 1;
						i++;
				}
				i=0;
				memset(alphabet2, 0, sizeof(alphabet2));
				while(buf2[i] != 0)
				{
						alphabet2[buf2[i] - 97] += 1;
						i++;
				}
				for(i = 0; i < 26; i++){ 
						int num;
						if(alphabet[i] != 0 && alphabet2[i] != 0)
						{
								num = (alphabet[i] > alphabet2[i]) ? (alphabet2[i]) : (alphabet[i]);
								for(j = 0; j < num; j++)
										printf("%c", i + 97);
						}
				}
				printf("\n");
		}


		return 0;
}
