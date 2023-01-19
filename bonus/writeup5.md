# Bash history of the root user

Remember how in writeup2.md we mounted the .iso file and inspected its contents?

If we check out the `root/.bash_history` file we can see the entire history of commands run by the superuser.

On line 402 of this file we can find:
```shell
adduser zaz
646da671ca01bb5d84dbb5fb2238dc8e
```
Is that a password to the zaz user? Yes, it seems that root accidentally typed the password twice.

With this information, we can get root by just skipping straight to the zaz user and buffer overflowing `exploit_me`.
