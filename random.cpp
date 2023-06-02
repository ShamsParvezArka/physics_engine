#include <cstdlib>
#include <ctime>

float randf(float lower, float upper)
{
	float magic_number = (float) rand() / (float) RAND_MAX;
	if (magic_number*upper < lower)
		magic_number = magic_number*upper + (lower - magic_number);

	return magic_number*upper;
}
