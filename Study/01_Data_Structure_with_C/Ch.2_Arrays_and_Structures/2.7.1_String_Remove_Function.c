void stringremove(char* s, int i, int j) 
{
	char string[MAX_SIZE], * temp = string;
	memset(string, 0, sizeof(string));

	if (i<0 || i > strlen(s)) {
		fprintf(stderr, "position is out of bounds\n");
		exit(1);
	}
	if (!strlen(s)) {
		printf("there is nothing to remove\n");
	}
	else if (j > 0) {
		strncpy(temp, s, i);
		strcat(temp, s + i + j);
		strcpy(s, temp);
	}
}
