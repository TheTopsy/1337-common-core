#include<stdio.h>
#include<string.h>
size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t l = 0;
	size_t i = 0;
	if(!src || !dst)
		return 0;
	while(src[l])
		l++;
	if(size == 0)
		return l;
	while(src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return l;
}