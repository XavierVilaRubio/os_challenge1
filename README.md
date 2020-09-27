# OS2021: Challenge #1: Linux Kernel

## 1. Working with System Calls in C

### Question 1
#### What is more expensive a *System call* or a *Procedure call* concerning **time**?
The hypothesis is that the *Procedure call* will be more expensive because they throw a system call.

### Question 2
#### How much more expensive is a *System call* or a *Procedure call* respect the other?

### Question 3
#### Design an experiment to test and proof which call is more time expensive. Write a simple test program in C to compare the cost of a simple procedure call to a simple system call (i.e getpid()).
tio joquese que pereza, que està tot al *working_with_system_calls_in_c.c* i ara em fa mandra comentar-ho

---

## 2. Compiling and running the kernel

### Question 4
#### Explain the process to enter and check into the new kernel version.
Once the new kernel has been compiled we need to update Grub configuration.
To do this we used `sudo vim /etc/default/grub` and commented the `GRUB_HIDDEN_TIMEOUT` line and set the `GRUB_TIMEOUT` to -1, this way the boot manager will wait until we pick wich kernel do we want to boot in.
Now, when we boot we get this Grub menu, and if we go to 'Advanced options for Ubuntu'

![Screenshot of the grub menu](assets/grub_screenshot.png)

We can see both kernels, the original (4.15.0) and the local-compiled (4.7.1)

![Screenshot of the installed and bootable kernels](assets/grub_screenshot_1.png)

### Question 5
#### Research the roles of files in /boot/?
* vmlinuz-* \
This file it's the compressed Linux kernel, and it's (tècnicament, perque no és executable, cosa que no acabo d'entendre) bootable.

* initrd.img \
This file is a scheme for loading a temporary root file system into memory, which is used on the boot.

* grub \
This folder contains all the files needed for the GUI Grub menu.

* config* \
This file contains the kernel configuration.
