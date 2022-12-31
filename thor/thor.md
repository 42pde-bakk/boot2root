# Thor

We see a file with many instructions for a turtle to follow, let's use the python module PythonTurtle.
`pip3 install PythonTurtle`
Once we run our script, we see SLASH being written.

The last line of the turtle file gives us a hint to `digest` the message, so let's do that.
Using Message Digest (md5) we get the ssh key for zaz
```shell
thor@BornToSecHackMe:~$ echo -n "SLASH" | md5sum
646da671ca01bb5d84dbb5fb2238dc8e  -
```
