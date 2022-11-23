# P4-ImplClases
## Requirements

  * g++ v9.4.0 or newer
  * Make


## Compilation

The code can be compiled with the provided makefile using the standard `make`
command.


## Sample Execution & Output

If run without command line arguments, using

```
./precisionEstimate
```

the following usage message will be displayed.

```
Usage: ./precisionEstimate numExecs
```

If run using 

```
./precisionEstimate 100000000
```

output *simliar* to

```
   0 secs | 1.19209e-07
   1 secs | 2.22045e-16
  17 secs | 1.92593e-34
```

will  be displayed. Note that the precision estimates will vary by
architecture/system.