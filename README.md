# sort

[![Build Status](https://travis-ci.org/sinh3012/sort.svg?branch=master)](https://travis-ci.org/sinh3012/sort)

Внешняя сортировка

Сложность O(nlogn)

Алгоритм:

1)Открываем исходный файл

2)Читаем кусок файла размером с нашу память

3)Сортируем

4)Записывем во временный файл

5)Пункты 2-5 повторяются, пока не прочитаем весь исходный файл (Получим T временных файлов)

6)По два файла сливаем в один (сравниваем первые строки и записываем меньшую в выходной файл, пока оба файла не закончатся)
(Сливаем 1 и 2, 3 и 4, ... , T-1 и T.  Если T%2=1, то дополнительно сливаем полученный слиянием из 1 со 2 и T)

7)Удаляем исходные временные файлы

8)Повторяем 6-7 пункты, пока не получим один файл

9)Получен отсортированный исходный файл

name.txt сгенерированный файл для сортировки

sorted_test.txt правильно отсортированный файл

Тесты на тревисе пока не работают. В VS все работает. При сортировке на вход подаётся: name.txt memory, где memory это количество строк, которые может быть в памяти, а name.txt - файл для сортировки. На выходе получаем sorted.txt - результат сортировки.  Для проверки результата на вход подаётся: test sorted.text sorted_test.txt. Файлы сравниваются построчно и при несоответствии получаем ошибку.
