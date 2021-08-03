# Linux Bash Script 

A Bash script is a plain text file which contains a series of commands. These commands are a mixture of commands we would normally type ouselves on the command line (such as ls or cp for example).

## Bash

Bash is a command language interpreter. It is widely available on various operating systems and is a default command interpreter on most GNU/Linux systems. The name is an acronym for the ‘Bourne-Again SHell’.

## Shell

Shell is a macro processor which allows for an interactive or non-interactive command execution.

## Scripting

Scripting allows for an automatic commands execution that would otherwise be executed interactively one-by-one.

### For running bash script

bash filename with .sh extension
example

```sh
bash test.sh
```

### Operators
```sh
-le <=
-lt <
-ge >=
-gt >
-eq =
-ne !=
-a &&
-0 ||
```
### If Condition

```sh
if<condition>; then
//statement
else
//statement
fi
```

### Condition

- In bash shell  
```sh
[$a -l+ $b]
```
- In kornshell 
```sh
 (($a < $b))
 ```

### Using kornshell

```sh
echo "enter your age"
read age
if (($age >= 18));  then
echo "you are eligible to vote"
else
 echo "you are not eliginle to vote"
fi
```

### Using bash condition

```sh
echo "enter your age"
read age
if [ $age -ge 18 ];  then
echo " you are eligible to vote "
else
 echo " you are not eliginle to vote "
fi
```
