#include "number.h"

void Number::resetPos()
{
	for (int i = 0; i < 3; i++)
		pos[i].set(-1, -1);
}

int Number::calcNumOfDigits()
{
	int tempNum = num;
	int count = 0;

	if (tempNum == 0)
		return 1;

	while (tempNum > 0) {
		tempNum /= 10;
		count++;
	}
	return count;
}
