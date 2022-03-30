#include "../cub.h"
#include <sys/types.h>

u_int32_t	exponentiation(u_int32_t num, size_t stepen)
{
	u_int32_t tmp;

	// printf("num = %d, stepen = %zu\n", num, stepen);
	if (stepen == 0)
		return (1);
	if (stepen == 1)
		return (num);
	tmp = num;
	while (--stepen >= 1)
		num *= tmp;
	return (num);
}