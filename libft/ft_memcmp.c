#include<stdio.h>
#include<string.h>
int ft_memcmp(const void *vs1, const void *vs2, size_t n)
{
	size_t i = 0;
	unsigned char *s1 = (unsigned char *)vs1;
	unsigned char *s2 = (unsigned char *)vs2;

        while(n--)
        {
                if (s1[i] == s2[i] && s1[i] && s2[i])
                        i++;
                else
                        return (s1[i] - s2[i]);
        }
        return (0);

}
