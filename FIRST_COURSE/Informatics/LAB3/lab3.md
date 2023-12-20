# LAB3
> Решение лабораторной работы №3
### Задание 1.
```
#!/bin/bash
read a
for ((i=0;i<a;i++))
do
echo 'Hello'
done
```
### Задание 2.
```
#!/bin/bash
read a b
echo $(($a+$b))
```
### Задание 3.
```
#!/bin/bash
read a b c
if [[ "$c" = "add" ]]
then
echo $(($a+$b))
elif [[ "$c" = "sub" ]]
then
echo $(($a-$b))
elif [[ "$c" = "mul" ]]
then
echo $(($a*$b))
else
echo "bad input"
fi
```
### Задание 4.
```
export ARITHMETIC_OP
read a b c
if [[ -z "$c" ]]
then
c="$ARITHMETIC_OP"
fi
if [[ "$c" = "add" ]]
then
echo $(($a+$b))
elif [[ "$c" = "sub" ]]
then
echo $(($a-$b))
elif [[ "$c" = "mul" ]]
then
echo $(($a*$b))
else
echo "bad input"
fi
```
