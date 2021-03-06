Лабораторная работа № 2

`1.1` В основной программе переменной x присвоить значение 100, а затем вызвать fork(). Каково значение x в порождённом процессе?

В порожденном процессе значение переменной х будет так же 100, т. к. программа продолжается с момента вызова fork().

`1.2` Что происходит, когда основной и порожденный процесы меняют значение x?

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/2_1.png)
В каждом процессе своя переменная х, т.к. для потомка создается отдельное адресное пространство, поэтому изменение значения переменной в одном из процессов не будет влиять на ее значение в другом процессе.

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/2_2.png)

`2.` Порожденный процесс, созданный с помощью fork(), должен напечатать “hello”; основной - “goodbye”. Нужно обеспечить, чтобы порожденный процесс печатал первым без использования wait() в основном.

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/2_3.png)

Функция kill() отправляет процессору с id сигнал. В основном процессе используем функцию signal(), которая по номеру сигнала устанавливает обработчиком определенную функцию.

`3.` Сначала вызывается fork(), а затем какой-либо вариант exec() (execl(), execle(), execlp(), execv(), execvp(), и execvpe()) для вызова /bin/ls. Для чего предусмотрено столько много вариантов exec()?

Функция exec() (execute) загружает и запускает другую программу. Таким образом, новая программа полностью замещает текущий процесс. Новая программа начинает свое выполнение с функции main. Все файлы вызывающей программы остаются открытыми. Они также являются доступными новой программе. Используется шесть различных вариантов функций exec. 

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/2_4.png)

Вызов exec происходит таким образом, что переданная в качестве аргумента программа загружается в память вместо старой, которая вызвала exec. Старой программе больше не доступны сегменты памяти, которые перезаписаны новой программой. 

Суффиксы l, v, p, e в именах функций определяют формат и объем аргументов, а также каталоги, в которых нужно искать загружаемую программу: 

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/2_5.png)

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/2_6.png)

`4.` В основной программе использовать  wait() для того, чтобы дождаться завершения порожденного процесса? 

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/2_7.png)

Функция wait приостанавливает выполнение текущего процесса до тех пор, пока дочерний процесс не завершится, или до появления сигнала, который либо завершает текущий процесс, либо требует вызвать функцию-обработчик. Параметр pid может принимать несколько значений: 

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/2_8.png)

Так же есть функция waitpid:

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/2_9.png)

Функция waitpid приостанавливает выполнение текущего процесса до тех пор, пока дочерний процесс, указанный в параметре pid, не завершит выполнение, или пока не появится сигнал, который либо завершает текущий процесс либо требует вызвать функцию-обработчик.
Значение options создается путем логического сложения нескольких следующих констант: 

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/2_10.png)
Если status не равен NULL, то функции wait и waitpid сохраняют информацию о статусе в переменной, на которую указывает status. 

Что возвращает wait()?

Возвращает идентификатор дочернего процесса, который завершил выполнение, или ноль, если использовался WNOHANG и ни один дочерний процесс пока еще недоступен, или -1 в случае ошибки (в этом случае переменной errno присваивается соответствующее значение).  

Что произойдет, если использовать wait() в порожденном процессе?

Так как wait() ждет выполнение дочерних процессов, следовательно, вызов wait() в порожденном процессе ничего не даст.

Когда использование waitpid() целесообразно?

Использование waitpid() целесообразно, когда требуется дождаться выполнение конкретного процесса.

`5.` Программа порождает процесс и в нем закрывает стандартный вывод (STDOUT FILENO). Что произойдет, если осуществить вызов printf() для того, чтобы что-то вывести в основном и дочернем процессах?

Если в дочернем процессе закрыть стандартный вывод, то в этом процессе нельзя будет ничего вывести, но в основном процессе можно.

`6.` Разработать программу, которая создает два порожденных процесса и  соединяет стандартный вывод одного со стандартным вводом другого с использованием pipe().

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/2_11.png)

Параметр file_descriptor является указателем на массив из двух целых переменных. При нормальном завершении вызова в первый элемент массива – file_descriptor[0] – будет занесен файловый дескриптор, соответствующий выходному потоку данных pip’а и позволяющий выполнять только операцию чтения, а во второй элемент массива – file_descriptor[1] – будет занесен файловый дескриптор, соответствующий входному потоку данных и позволяющий выполнять только операцию записи.

Использование pipe в файле task6.c

