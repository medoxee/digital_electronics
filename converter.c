#include <stdio.h>
#include <stdlib.h>

/*
 * 		IN THE NAME OF ALLAH,
 * Developer: MOHAMED ARRAF
 * Description:
 * 	This program is a converter baseX to base2(until now)
 */
void	b10_to_bx(int	value, char	*base_2, char	*base_16, int	*b2_msd, int	*b16_msd)
{
	int	proceed_value; // holds the value of value var
	int	modulo;
	int	devision_result;
	int	i; // for while loops

	// b10_to_b2
	proceed_value = value;
	i = 0;
	while (proceed_value)
	{
		devision_result = proceed_value / 2;
		modulo = proceed_value % 2;
		base_2[i] = modulo + 48; // ASCII conversion
		proceed_value = devision_result;
		i++;
	}
	base_2[i + 1] = '\0'; // end of binary numbers
	*b2_msd = i - 1;
	// b10_to_b16
	proceed_value = value;
	i = 0;
	while (proceed_value)
	{
		devision_result = proceed_value / 16;
		modulo = proceed_value % 16;
		if (modulo > 9)
			base_16[i] = modulo + 55;
		else
			base_16[i] = modulo + 48;
		proceed_value = devision_result;
		i++;
	}
	base_16[i + 1];
	*b16_msd = i + 1;
}
/*
int	bx_to_b10(int	base, int	value)
{
	// value is already base 10
	if (base == 10)
		return value;
	if (base == 2)
	{
		
	}

}
*/
int	main(void)
{
	char	value[100];
	char	base_2[100];
	char	base_10[100];
	char	base_16[100];
	int	base;
	int	b2_msd; // Most Segnificant Digit
	int	b16_msd;

	printf("Enter Value Base(space seperated)\tExample: 1F 16\n>");
	scanf("%s %d", &value, &base);
	if (base == 10)
		b10_to_bx(atoi(value), base_2, base_16, &b2_msd, &b16_msd);
	// if (base == 2)
	// msd = b2_to_bx(base, value);
	printf("Base 2:\n");
	while (b2_msd >= 0)
	{
		printf("%c", base_2[b2_msd]);
		b2_msd--;
	}
	printf("\nBase 16:\n");
	while (b16_msd >= 0)
	{
		printf("%c", base_16[b16_msd]);
		b16_msd--;
	}
	printf("\n");
	return (0);
}
