#include <stdio.h>
#include "abonentstruct.h"

void AbonentDisplayInfo(struct abonent* user_array, int index) {
	struct abonent user = *(user_array + index);

	printf(  "\n\n\n%d.", index);
	printf(    " Name: %s", user.name);
	printf("\n Last name: %s", user.last_name);
	printf("\n Phone number: %s", user.number);

	return;
}