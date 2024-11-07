#include<stdio.h>
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t sln = 0;
	size_t dln = 0;
	size_t i = 0;
	size_t k = 0;
	while(src[sln])
		sln++;
	while(dst[dln])
		dln++;
	if(size <= dln)
		return sln + size;
	k = dln;
	while(src[i] && i < size - dln - 1)
	{
		dst[k] = src[i];
		i++;
		k++;	       
	}

	dst[k] = '\0';
	return sln + dln;
}
