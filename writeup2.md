# fun + bomb

## Summary

1. Mount the ISO and explore the files
2. Solve the "fun" challenge (lmezard)
3. Solve the "bomb" challenge (laurie)
4. Solve the "turtle" challenge (thor)
5. Solve the "exploit_me" challenge (zaz)


### Mounting the ISO and exploring the files

We have an ISO file, we can't modify it but we can read it.  
First, we will mount the ISO file:
```
udisksctl loop-setup -f ~/Downloads/BornToSecHackMe-v1.1.iso
```
And then open the squashfs, which is basically an archive of the files:
```
unsquashfs -d /tmp/b2r-sqfs /media/aguiot--/BornToSec/casper/filesystem.squashfs
cd /tmp/b2r-sqfs
```

There is a lot of homes for multiple users, with some interesting files.
```
aguiot--@e1r1p6:/tmp/b2r-sqfs$ tree -FC ./home
./home/
├── ft_root/
│   ├── Desktop/
│   └── mail/
│       ├── INBOX.Drafts*
│       ├── INBOX.Sent*
│       └── INBOX.Trash*
├── laurie/
│   ├── bomb*
│   └── README*
├── laurie@borntosec.net/
│   └── mail/
│       ├── INBOX.Drafts*
│       ├── INBOX.Sent*
│       └── INBOX.Trash*
├── lmezard/
│   ├── fun*
│   └── README*
├── LOOKATME/
│   └── password*
├── thor/
│   ├── README*
│   └── turtle*
└── zaz/
    ├── exploit_me*
    └── mail/
        ├── INBOX.Drafts*
        ├── INBOX.Sent*
        └── INBOX.Trash*

11 directories, 17 files
```


### LOOKATME

In the `LOOKATME` folder, we have a `password` file. It gives the password of the `lmezard` user. We can use it to login on the VM TTY, and also FTP (found via nmap).  
```
lmezard:G!@M6f4Eatau{sF"
```

![tty login](./images/writeup2.tty.png)


### lmezard (fun)

Check the [laurie folder](./thor/) in this repository.


### laurie (bomb)

Check the [laurie folder](./thor/) in this repository.


### thor (turtle)

Check the [thor folder](./thor/) in this repository.


### zaz (exploit_me)

Check the [zaz folder](./thor/) in this repository.
