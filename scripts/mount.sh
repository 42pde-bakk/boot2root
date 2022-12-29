#!/usr/bin/env bash

sudo mkdir /mnt/boot /mnt/squash

sudo mount ~/Downloads/BornToSecHackMe-v1.1.iso /mnt/boot
sudo mount /mnt/boot/casper/filesystem.squashfs /mnt/squash

