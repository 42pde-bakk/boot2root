### lmezard (fun)

Check the [laurie folder](./thor/) in this repository.


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

```shell
MY PASSWORD IS: Iheartpwnage
Now SHA-256 it and submit
```

```shell
echo -n 'Iheartpwnage' | sha256sum
330b845f32185747e4f8ca15d40ca59796035c89ea809fb5d30f4da83ecf45a4
```
