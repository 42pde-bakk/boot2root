# WIP

## Setting up:

TODO: explain iso mount, squashfs, etc

### "fun"

```
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

```
MY PASSWORD IS: Iheartpwnage
Now SHA-256 it and submit
```

```
echo -n 'Iheartpwnage' | sha256sum
```
