# lab2
> Решение лабораторной работы №2
### Задание 1.
```
mkdir lab2
cd lab2
wget http://db4.sbras.ru/elbib/crusoe.txt
grep -o 'Friday' crusoe.txt
grep -o 'Friday' crusoe.txt | wc -l
sed -i 's/Friday/Saturday/g' crusoe.txt
rm crusoe.txt
```
### Задание 2.
```
echo -e '1 2\n2 2\n3 7' > task2
awk '{sum1+=$0;sum2+=$2} END {print sum1, sum2}' task2
rm task2
```
### Задание 3.
```
echo -e '1 300\n2 3\n10' > task3
awk 'BEGIN {i=0}{if (NF > i){{i=NF}{str=$0}}} END {print str}' task3
echo -e '200\n1 1 1 1\n10 10 10' > task3
awk 'BEGIN {i=0}{if (NF > i){{i=NF}{str=$0}}} END {print str}' task3
rm task3
cd
rmdir lab2
```
