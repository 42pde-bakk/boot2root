#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <sys/socket.h>
#include <signal.h>
#include <netdb.h>

int completed_4 = 0; // weak
int bomb_id = 0; // weak
char lab_id[8] = "generic"; // weak
char array_123[16] = {
	105, 115, 114, 118, 101, 97, 119, 104, 111, 98, 112, 110, 117, 116, 102, 103
};
// "isrveawhobpnutfg"
// python3 -c 'print([chr(x) for x in array_123])'

void *node1, *node2, *node3, *node4, *node5, *node6;
unsigned int n1[8] = { 36, 134525716, 134525704, 0, 0, 0, 0, 0 };
int num_input_strings = 0;
int _CTOR_LIST__ = -1;
int _ctype_b;
FILE *infile;
char *byte_804B67F;
char input_strings[240];
char s[1360];
char scratch[80];

int main(int argc, const char **argv)
{
	char *line;
	char *v4;
	char *v5;
	char *v6;
	char *v7;
	char *v8;

	if (argc == 1) {
		infile = (FILE *)stdin;
	}
	else
	{
		if (argc != 2) {
			printf("Usage: %s [<input_file>]\n", *argv);
			exit(8);
		}
		infile = fopen(argv[1], "r");
		if (!infile) {
			printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
			exit(8);
		}
	}
	initialize_bomb();
	printf("Welcome this is my little bomb !!!! You have 6 stages with\n");
	printf("only one life good luck !! Have a nice day!\n");
	line = (char *)read_line();
	phase_1(line);
	phase_defused();
	printf("Phase 1 defused. How about the next one?\n");
	v4 = (char *)read_line();
	phase_2(v4);
	phase_defused();
	printf("That's number 2.  Keep going!\n");
	v5 = (char *)read_line();
	phase_3(v5);
	phase_defused();
	printf("Halfway there!\n");
	v6 = (char *)read_line();
	phase_4(v6);
	phase_defused();
	printf("So you got that one.  Try this one.\n");
	v7 = (char *)read_line();
	phase_5(v7);
	phase_defused();
	printf("Good work!  On to the next...\n");
	v8 = (char *)read_line();
	phase_6(v8);
	phase_defused();
	return 0;
}

int phase_1(char *a1)
{
	int result;

	result = strings_not_equal(a1, "Public speaking is very easy.");
	if (result)
		explode_bomb();
	return result;
}

int phase_2(char *s)
{
	int i;
	int result;
	int v3[6];

	read_six_numbers(s, (int)v3);
	if (v3[0] != 1)
		explode_bomb();
	for (i = 1; i <= 5; ++i) {
		result = v3[i - 1] * (i + 1);
		if (v3[i] != result)
			explode_bomb();
	}
	return result;
}

int phase_3(char *s)
{
	int result;
	char v2;
	int v3;
	char v4;
	int v5;

	if (sscanf(s, "%d %c %d", &v3, &v4, &v5) < 3)
		explode_bomb();
	result = v3;
	switch (v3)
	{
		case 0:
			v2 = 'q';
			if (v5 != 777)
				explode_bomb();
			return result;
		case 1:
			v2 = 'b';
			if (v5 != 214)
				explode_bomb();
			return result;
		case 2:
			v2 = 'b';
			if (v5 != 755)
				explode_bomb();
			return result;
		case 3:
			v2 = 'k';
			if (v5 != 251)
				explode_bomb();
			return result;
		case 4:
			v2 = 'o';
			if (v5 != 160)
				explode_bomb();
			return result;
		case 5:
			v2 = 't';
			if (v5 != 458)
				explode_bomb();
			return result;
		case 6:
			v2 = 'v';
			if (v5 != 780)
				explode_bomb();
			return result;
		case 7:
			v2 = '98';
			if (v5 != 524)
				explode_bomb();
			return result;
		default:
			explode_bomb();
	}
	if (v2 != v4)
		explode_bomb();
	return result;
}

int func4(int a1)
{
	int v1;

	if (a1 <= 1)
		return 1;
	v1 = func4(a1 - 1);
	return v1 + func4(a1 - 2);
}

int phase_4(char *s)
{
	int result;
	int v2;

	if (sscanf(s, "%d", &v2) != 1 || v2 <= 0)
		explode_bomb();
	result = func4(v2);
	if (result != 55)
		explode_bomb();
	return result;
}

int phase_5(char *a1)
{
	int i;
	int result;
	char v3[8];

	if (strlen(a1) != 6)
		explode_bomb();
	for (i = 0; i <= 5; ++i)
		v3[i] = array_123[a1[i] & 0xF];
	v3[6] = 0;
	result = strings_not_equal(v3, "giants");
	if (result)
		explode_bomb();
	return result;
}

int phase_6(char *s)
{
	uint32_t *v4;
	int result;
	int v13[6];
	int v14[6];

	read_six_numbers(s, (int)v14);
	for (int i = 0; i <= 5; ++i) {
		if ((unsigned int)(v14[i] - 1) > 5)
			explode_bomb();
		for (int j = i + 1; j <= 5; ++j) {
			if (v14[i] == v14[j])
				explode_bomb();
		}
	}
	for (int k = 0; k <= 5; ++k) {
		v4 = &node1;
		for (int m = 1; m < v14[k]; ++m)
			v4 = (uint32_t *)v4[2];
		v13[k] = (int)v4;
	}
	int v6 = v13[0];
	int v12 = v13[0];
	int v8;
	for (int n = 1; n <= 5; ++n) {
		v8 = v13[n];
		*(uint32_t *)(v6 + 8) = v8;
		v6 = v8;
	}
	*(uint32_t *)(v8 + 8) = 0;
	int v9 = v12;
	for (int ii = 0; ii <= 4; ++ii) {
		result = *(uint32_t *)v9;
		if (*(uint32_t *)v9 < **(uint32_t **)(v9 + 8))
			explode_bomb();
		v9 = *(uint32_t *)(v9 + 8);
	}
	return result;
}

int fun7(uint32_t* *a1, int a2)
{
	if (!a1)
		return -1;
	if (a2 < *a1)
		return 2 * fun7(a1[1], a2);
	if (a2 == *a1)
		return 0;
	return 2 * fun7(a1[2], a2) + 1;
}

void secret_phase()
{
	const char *line;
	int v1;

	line = (const char *)read_line();
	v1 = __strtol_internal(line, 0, 10, 0);
	if ((unsigned int)(v1 - 1) > 0x3E8)
		explode_bomb();
	if (fun7(n1, v1) != 7)
		explode_bomb();
	printf("Wow! You've defused the secret stage!\n");
	phase_defused();
}

void	sig_handler(int a1)
{
	printf("So you think you can stop the bomb with ctrl-c, do you?\n");
	sleep(3);
	printf("Well...");
	fflush(stdout);
	sleep(1);
	printf("OK. :-)\n");
	exit(16);
}

void invalid_phase(const char *a1) {
	printf("Invalid phase%s\n", a1);
	exit(8);
}

int read_six_numbers(char *s, int a2) {
	int result;

	result = sscanf(s, "%d %d %d %d %d %d", a2, a2 + 4, a2 + 8, a2 + 12, a2 + 16, a2 + 20);
	if (result <= 5)
		explode_bomb();
	return result;
}

int strings_not_equal(char *a1, char *a2) {
	return (strcmp(a1, a2) != 0);
}

int open_clientfd(char *name, __int16_t a2)
{
	int v2;
	struct hostent *v3;
	struct sockaddr s;

	v2 = socket(2, 1, 0);
	if (v2 < 0)
	{
		printf("Bad host (1).\n");
		exit(8);
	}
	v3 = gethostbyname(name);
	if (!v3)
	{
		printf("Bad host (2).\n");
		exit(8);
	}
	bzero(&s, 0x10u);
	s.sa_family = 2;
	bcopy(*(const void **)v3->h_addr_list, &s.sa_data[2], v3->h_length);
	*(__uint16_t *)s.sa_data = __ROR2__(a2, 8);
	if (connect(v2, &s, 0x10u) < 0)
	{
		printf("Bad host (3).\n");
		exit(8);
	}
	return v2;
}

__sighandler_t initialize_bomb()
{
	return signal(2, (__sighandler_t)sig_handler);
}

int blank_line(char *a1)
{
	char *v1;
	int v2;

	v1 = a1;
	if (!*a1)
		return 1;
	while (1)
	{
		v2 = (char)*v1++;
		if ((*(char *)(_ctype_b + 2 * v2 + 1) & 0x20) == 0)
			break;
		if (!*v1)
			return 1;
	}
	return 0;
}

char *skip()
{
	char *v0;
	char *v1;

	do {
		v0 = fgets((char *)(80 * num_input_strings + 134526592), 80, infile);
		v1 = v0;
	} while (v0 && blank_line(v0));

	return v1;
}

int read_line()
{
	unsigned int v0;
	unsigned int v1;
	int v2;
	int result;

	if ( !skip() )
	{
		if (infile == stdin)
			goto LABEL_6;
		if (getenv("GRADE_BOMB"))
			exit(0);
		infile = stdin;
		if (!skip())
		{
		LABEL_6:
			printf("Error: Premature EOF on stdin\n");
			explode_bomb();
		}
	}
	v0 = strlen(&input_strings[80 * num_input_strings]) + 1;
	v1 = v0 - 1;
	if (v0 == 80)
	{
		printf("Error: Input line too long\n");
		explode_bomb();
	}
	v2 = 80 * num_input_strings;
	byte_804B67F[v1 + v2] = 0;
	result = v2 + 134526592;
	++num_input_strings;
	return result;
}

int send_msg(int a1)
{
	int v1;
	FILE *v2;
	FILE *v3;
	const char *v4;
	const char *v5;
	int v6;
	int v7;
	int result;
	char dest[80];

	v1 = dup(0);
	if (v1 == -1)
	{
		printf("ERROR: dup(0) error\n");
		exit(8);
	}
	if (close(0) == -1)
	{
		printf("ERROR: close error\n");
		exit(8);
	}
	v2 = tmpfile();
	v3 = v2;
	if (!v2)
	{
		printf("ERROR: tmpfile error\n");
		exit(8);
	}
	fprintf(v2, "Subject: Bomb notification\n");
	fprintf(v3, "\n");
	v4 = (const char *)cuserid(0);
	if (v4)
		strcpy(dest, v4);
	else
		strcpy(dest, "nobody");
	v5 = "exploded";
	if (a1)
		v5 = "defused";
	fprintf(v3, "bomb-header:%s:%d:%s:%s:%d\n", lab_id, bomb_id, dest, v5, num_input_strings);
	v6 = 0;
	if (num_input_strings > 0)
	{
		do
		{
			v7 = v6 + 1;
			fprintf(v3, "bomb-string:%s:%d:%s:%d:%s\n", lab_id, bomb_id, dest, v6 + 1, (const char *)(80 * v6 + 134526592));
			v6 = v7;
		} while ( v7 < num_input_strings );
	}
	rewind(v3);
	sprintf(scratch, "%s %s@%s", "/usr/sbin/sendmail -bm", "bomb", "bluegill.cmcl.cs.cmu.edu");
	if (system(scratch))
	{
		printf("ERROR: notification error\n");
		exit(8);
	}
	if (fclose(v3))
	{
		printf("ERROR: fclose(tmp) error\n");
		exit(8);
	}
	if (dup(v1))
	{
		printf("ERROR: dup(tmpstdin) error\n");
		exit(8);
	}
	result = close(v1);
	if (result)
	{
		printf("ERROR: close(tmpstdin)\n");
		exit(8);
	}
	return result;
}

void explode_bomb()
{
	printf("\nBOOM!!!\n");
	printf("The bomb has blown up.\n");
	exit(8);
}

void phase_defused()
{
	char v0;
	char v1[80];

	if (num_input_strings == 6)
	{
		if (sscanf(s, "%d %s", &v0, v1) == 2 && !strings_not_equal(v1, "austinpowers"))
		{
			printf("Curses, you've found the secret phase!\n");
			printf("But finding it and solving it are quite different...\n");
			secret_phase();
		}
		printf("Congratulations! You've defused the bomb!\n");
	}
}
