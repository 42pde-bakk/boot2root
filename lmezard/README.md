### lmezard (fun)

In this first challenge, we have a file named `fun`. Running the command `file fun` says that it's a tar archive. We can open it with `tar xvf fun`.  
We then have a lot of `.pcap` files. This should be some PacketCapture files from Wireshark or tcpdump etc, but with `file x.pcap` we can see it's actually text files. Here is an example of the content:
```
aguiot--@e1r1p6:/tmp$ cat ft_fun/DFO1G.pcap 
	printf("Hahahaha Got you!!!\n");

//file19
```
Each file has some mangled C code, with a commented file numbed. Here is a little script to re-arrange it:

```shell
mkdir /tmp/fundir
cp fun /tmp/fundir
cd /tmp/fundir
tar xvf fun
cd ft_fun
mkdir ordered
find . -type f -name '*.pcap' -exec sh -c 'cp {} ordered/$(grep file {} | cut -c 7-)' \;
cd ordered
ls -1 | sort -n | xargs cat | sed -E 's#//file[0-9]+##g' > fun.c
gcc fun.c
./a.out
```
Which gives us this:
```shell
MY PASSWORD IS: Iheartpwnage
Now SHA-256 it and submit
```

```shell
echo -n 'Iheartpwnage' | sha256sum
330b845f32185747e4f8ca15d40ca59796035c89ea809fb5d30f4da83ecf45a4
```

From now on we can use ssh to user `laurie` with this password.

[[Go to next challenge (laurie)](../laurie/)] | [[Go back to writeup2.md](../writeup2.md)]]
