# Bootloader exploit

This first exploit is simple. We will boot the VM and interrupt the boot sequence to get a bootloader menu or prompt. Usually there is a GRUB menu, in this VM we can only get the prompt.  
It's a known method, often used to reset a lost root password, or get access to a computer without knowing the password. Physical access => Vulnerable.  
The only way to protect from physical attacks is to crypt the disk/partitions, which is not the case here.  

The process is simple: Boot the VM, and while booting, press the `Shift` key. If we had a GRUB menu, we would have pressed `e` (for Edit).
We get a `boot: ` prompt:

![tty login](./images/writeup2.tty.png)

We can use the `live` command to boot on the live image (default one). We can add some parameters, like when editing Kernel Parameters in GRUB menu.  
The classical parameters are `rw` for read-write and `init=/bin/bash` to start a shell, as root.  
We can see on the screen that we indeed get a root shell.
