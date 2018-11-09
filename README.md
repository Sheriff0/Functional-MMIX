# Functional-MMIX

The is an implementation of some of the operations in the instruction set of the virtual MMIX machine developed by Dr. Donald Knuth, with an F.P (Functional Programming) undertone.

All of the programs use another program called "bins.c" to print the bits after the operation. They refer to this program as "bins". So, to use any of the operations you need to first compile "bins.c" with the name "bins". 

# On UNIX
```console
$ gcc -o bins bins.c
```

# Compiling an operation
After compiling "bins.c", you must also compile an operation before running it.

```console
$ gcc -o mux MUX.c
```

# Running an operation
For all operations, the operands are passed as argument to the compiled code and follow the format "op0_op1". For instance, MUX takes three operands: Y,Z and the octabyte in the special mask register rM. You should run "mux" like :

```console
$ ./mux 567_7654_7656
```

# About the output
Passing any other argument after the expected operands of an operation prints the output as an unsigned integer instead of int bits. For example, running

```console
$ ./mux 67_85_1087
```

# Outputs 
```console
00000000
00000000
00000000
00000000
00000000
00000000
00000000
01000011
```

```console
$ ./mux 67_85_1087 anything
```

# Outputs
```console
$ 67
```


