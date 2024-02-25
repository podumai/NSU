# lab4
> Решение лабораторной работы №4
### Задание 1.
```
egrep -o '\bz\w*\b' crusoe.txt
egrep -o '\b\w{16}\b' crusoe.txt
egrep -o '\ba\w*c\b' crusoe.txt
egrep -o '\bab[^o]\w*\b' crusoe.txt
```
### Задание 2.
```
egrep '^[0-9]+$' patterns.txt
egrep '^[a-zA-Z]+$' patterns.txt
```
### Задание 3.
```
egrep '\b[ABEKMHOPCTYX][0-9]{3}[ABEKMHOPCTYX]{2}[0-9]{2,3}\b' patterns.txt
```
