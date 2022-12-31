# Laurie
## Bomb

### Phase 1
```c
int phase_1(char *a1) {
	int result;

	result = strings_not_equal(a1, "Public speaking is very easy.");
	if (result)
		explode_bomb();
	return result;
}
```
All we have to do here is pass the string comparison by providing the string you see above.


### Phase 2
```c
int phase_2(char *s) {
	int result;
	int v3[6];

	read_six_numbers(s, (int)v3);
	if (v3[0] != 1)
		explode_bomb();
	for (int i = 1; i <= 5; ++i) {
		result = v3[i - 1] * (i + 1);
		if (v3[i] != result)
			explode_bomb();
	}
	return result;
}
```
We provide six numbers and and each (except the first which needs to be 1) has to be equal to the previous value multiplied by its index+1
So, we get:
1
1 * (1 + 1) = 2
2 * (2 + 1) = 6
6 * (3 + 1) = 24
24 * (4 + 1) = 120
120 * (5 + 1) = 720
`1 2 6 24 120 720`


### Phase 3
```c
int phase_3(char *s) {
	int result,
		v3,
		v5;
	char	v2,
			v4;

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
			v2 = 'b';
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
```
Here we have to provide 2 ints and a char,
the first int has to be in between 0 and 6, the second int has to pass the if-statement in the switch-case, and the char has to be same as v2 set inside the switch-case.

The README provides the hint that the letter should be a 'b', which leaves:
`1 b 214`
`2 b 755`
`7 b 524`
as valid solutions.


### Phase 4
```c
int func4(int arg) {
	if (arg <= 1)
		return 1;
	return (func4(arg - 1) + func4(arg - 2));
}

int phase_4(char *s) {
	int result;
	int v2;

	if (sscanf(s, "%d", &v2) != 1 || v2 <= 0)
		explode_bomb();
	result = func4(v2);
	if (result != 55)
		explode_bomb();
	return result;
}
```
There is a recursive function (func4) which returns 1 if (a <= 1), or otherwise `func4(arg - 1) + func4(arg - 2)`.

We need to provide a 1-digit above-zero integer whose result is 55.
`func4(0) => 1`
`func4(1) => 1`
`func4(2) => 2`
`func4(3) => 3`
`func4(4) => 5`
`func4(5) => 8`
`func4(6) => 13`
`func4(7) => 21`
`func4(8) => 34`
`func4(9) => 55`
Our answer is `9`.


### Phase 5:
```c
char array_123[16] = {
	'i', 's', 'r', 'v', 'e', 'a', 'w', 'h', 'o', 'b', 'p', 'n', 'u', 't', 'f', 'g'
}; // python3 -c 'print([chr(x) for x in array_123])'
int phase_5(char *a1) {
	int result;
	char v3[8];

	if (strlen(a1) != 6)
		explode_bomb();
	for (int i = 0; i <= 5; ++i)
		v3[i] = array_123[a1[i] & 0xF];
	v3[6] = 0;
	result = strings_not_equal(v3, "giants");
	if (result)
		explode_bomb();
	return result;
}
```
We provide a string of size 6 where the last 4 bits of each character's ASCII value is being used as the index to array_123 which is our new alphabet for today. The new letters generated have to spell out `"giants"`.
```py
import string
for i in range(16):
	vals = [c for c in string.ascii_lowercase if ord(c) & 0xF == i]
	print(f'{i} can be created by &-ing these values with 0xF:', vals)
```
Let's only consider giving lowercase characters.
The `g` (index=15) can be created by chars ['o']

The `i` (index=0) can be created by chars ['p']

The `a` (index=5) can be created by chars ['e', 'u']

The `n` (index=11) can be created by chars ['k']

The `t` (index=13) can be created by chars ['m']

The `s` (index=1) can be created by chars ['a', 'q']

So we have multiple possibilities
`opekma`
`opekmq`
`opukma`
`opukmq`
### Phase 6

We need to provide 6 numbers which all have to be between 1 and 6 and without duplicates.
Phase_6 uses these ints as index of an array and checks whether the items in the array are sorted in descending order (`if (*v9 < **(v9 + 8)) explode_bomb();`). The bomb blows up if this is not the case
Using gdb we can find the values:
```shell
(gdb) p node1
$3 = 253
(gdb) p node2
$4 = 725
(gdb) p nod3
No symbol "nod3" in current context.
(gdb) p node3
$5 = 301
(gdb) p node4
$6 = 997
(gdb) p node5
$7 = 212
(gdb) p node6
$8 = 432
```
So sorted, the indices would be 4 (997), 2 (725), 6 (432), 3 (301), 1 (253), 5 (212).
` 4 2 6 3 1 5`

Putting all the pieces together, we get:
"`Congratulations! You've defused the bomb!`"
But nothing happens. I haven't yet found how to access the secret_phase in the executable.

But if we create the password(s) by appending all the answers, we get and trying all combinations:
`Publicspeakingisveryeasy.126241207201b2149opekma426315`
`Publicspeakingisveryeasy.126241207201b2149opekmq426315`
`Publicspeakingisveryeasy.126241207201b2149opukma426315`
`Publicspeakingisveryeasy.126241207201b2149opukmq426315`

`Publicspeakingisveryeasy.126241207202b7559opekma426315`
`Publicspeakingisveryeasy.126241207202b7559opekmq426315`
`Publicspeakingisveryeasy.126241207202b7559opukma426315`
`Publicspeakingisveryeasy.126241207202b7559opukmq426315`

`Publicspeakingisveryeasy.126241207207b5249opekma426315`
`Publicspeakingisveryeasy.126241207207b5249opekmq426315`
`Publicspeakingisveryeasy.126241207207b5249opukma426315`
`Publicspeakingisveryeasy.126241207207b5249opukmq426315`

