#pragma once


struct abonent {
	char number[12];
	char name[12];
	char last_name[12];
};

struct directory {
	struct abonent users[100];
	unsigned int user_count;
};