# Модуль 3. Строки.
### Задание 1.
```
Дан текст. Необходимо определить максимальное количество последовательных пробельных символов в нём.
```
### Задание 2.
```
Дан текст. Необходимо определить максимальное количество последовательных одинаковых символов в нём.
```
### Задание 3.
```
Дан текст. Определить, сколько различных букв латинского алфавита в нем.
```
### Задание 4.
```
Определите какой символ встречается ровно три раза в тексте. Гарантируется, что символ с такой частотой встречаемости только один.
```
### Задание 5.
```
Даны три строки. Выведите на экран только те символы, которые есть лишь в одной из этих трёх строк.
```
### Задание 6.
```
Дано предложение. Напечатать его в обратном порядке слов.
```
### Задание 7.
```
Дано предложение. Найти длину его самого короткого слова.
```
### Задание 8.
```
Дано предложение. Напечатать все его слова в порядке неубывания их длин.
```
### Задание 9.
```
Дано предложение. В нем только два слова одинаковые. Найти эти слова.
```
### Задание 10.
```
Дано предложение. Выведите на экран те слова, которые отличны от первого слова и в слове нет повторяющихся букв.
```
### Задание 11.
```
Петя и Вася играют в игру "Города". Первым называет город Петя. Каждый следующий, называемый город должен начинаться на ту букву,
на которую окончился предыдущий. Программа получает на вход строку, состоящую из слов (городов), разделенных пробелами, которые
называли игроки. В результате работы, программа должна определять имя победителя. Игрок выигрывает, если он назвал слово последним.
Однако, игрок проигрывает, если он первым нарушил правила игры.
```
### Задание 12.
```
Как известно, имя в языке Python может содержать только латинские символы, цифры и знак подчеркивания "_". При этом, имя не может
начинаться с цифры и не может быть ключевым словом. Напишите программу, которая проверяет введенную строку, может ли она быть
именем в языке Python.
```
### Задание 13.
```
Дима часто пользуется общественным транспортом и всегда проверяет номер билета, является ли он "счастливым". Счастливым считается
билет, имеющий в номере четное количество цифр. Причем, сумма цифр первой половины номера равна сумме цифр второй половины.
Программа на вход получает последовательность номеров билетов. Ввод номеров должен завершить тогда, когда будет введен
"счастливый билет". Программа должна вывести его порядковый номер. Счет начинается с 1.
```
### Задание 14.
```
В телевизионной игре "Поле чудес", игрок отгадывает слово. Напишите программу, которая спрашивает у ведущего подсказку и загаданное
слово. Далее, программа удаляет информацию с экрана, выполняя вывод 25 пустых строк. После этого, выводится подсказка и слово,
где вместо букв, выводятся символы "*". Игрок должен с десяти попыток отгадать слово по буквам. После каждого хода выводится слово,
где неназванные буквы закрыты символом "*". Отгаданные буквы выводятся на тех местах, где они расположены. Каждый ход
сопровождается вопросом "Буква или слово (0 - буква, 1 - слово)?". В случае, если слово отгадано верно, выводится сообщение
"Победа!". Если слово названо неверно, или закончились попытки, выводится сообщение "Проигрыш!".

Пример работы программы:
Ведущий вводит две строки: подсказку и загаданное слово.
Дикое животное.
тигр
Программа выводит 25 пустых строк и таким образом "скрывает" то, что написал ведущий.
Игрок пытается отгадать слово:
Дикое животное.
****
Буква или слово (0 - буква, 1 - слово)?0
а
****
Буква или слово (0 - буква, 1 - слово)?0
р
***р
Буква или слово (0 - буква, 1 - слово)?0
и
*и*р
Буква или слово (0 - буква, 1 - слово)?1
тигр
Победа!
```
### Задание 15.
```
Напишите программу, позволяющую организовать игру "Быки и коровы" с десятью попытками отгадать слово. Программа должна спрашивать
у ведущего четырехзначное целое число с неповторяющимися цифрами. Далее, программа удаляет информацию с экрана, выполняя вывод 25
пустых строк. После этого, игрок пытается отгадать загаданное число. После каждой попытки, программа сообщает количество
"быков" и "коров". Быки - цифры совпавшие с загаданным числом и при этом находящиеся на тех же позициях. В случае, если число
отгадано верно, выводится сообщение "Победа!". Если закончились попытки, выводится сообщение "Проигрыш!".

Пример работы программы:
Ведущий вводит число.
9305
Программа выводит 25 пустых строк и таким образом "скрывает" то, что написал ведущий.
Игрок пытается отгадать число:
1234
Быков: 0 Коров: 1
5678
Быков: 0 Коров: 1
9012
Быков: 1 Коров: 1
9087
Быков: 1 Коров: 1
1087
Быков: 0 Коров: 1
9205
Быков: 3 Коров: 0
9305
Быков: 4 Коров: 0
Победа!
```
## Список заданий
- [&#128994;] Задание 1.
- [&#128994;] Задание 2.
- [&#128994;] Задание 3.
- [&#128994;] Задание 4.
- [&#128994;] Задание 5.
- [&#128994;] Задание 6.
- [&#128994;] Задание 7.
- [&#128994;] Задание 8.
- [&#128994;] Задание 9.
- [&#128994;] Задание 10.
- [&#128994;] Задание 11.
- [&#128994;] Задание 12.
- [&#128994;] Задание 13.
- [&#128994;] Задание 14.
- [&#128994;] Задание 15.
