Лабораторная работа №9

`1.` Установить (make) набор программ (см. Makefile) из архива  (см. также http://www.ostep.org).

`2.` С помощью helgrind (valgrind --tool=helgrind main-race) в программе main-race.c проанализировать ошибки в коде, связанные с несинхронизованностью потоков команд, работающих с общими данными (data race), и попытаться их устранить.

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/9_1_1.png)

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/9_1_2.png)

Очень распространенная ошибка, при работе с потоками - race condition. Возникает, когда оба потока пытаются одновременно пытаются обратиться к общим данным. Чтобы избежать такой ошибки, нужно воспользоваться мьютексами. Обернуть участок кода, в котором происходит доступ к общим данным.

`3.` В программе main-deadlock.c имеется ошибка, называемая мёртвая блокировка (deadlock, ситуация, при которой один поток (поток A), ждет ресурса, удерживаемого другим потоком (потоком B), и при этом удерживает ресурс, который нужен потоку B. Поскольку потоки A и B блокированы в ожидании ресурсов, удерживаемых другим потоком, выполнения не происходит). Использовать helgrind и проинтерпретировать отчет. 

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/9_2_1.png)

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/9_2_2.png)

В результате выполнения программы возникла ошибка deadlock. Такая ошибка возникает, когда первый поток ждет завершения второго, а второй-завершения первого.

`4.` Также использовать helgrind для main-deadlock-global.c и проанализировать отчет, сравнить с предыдущим.

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/9_3_1.png)

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/9_3_2.png)

Здесь Helgrind не показывает задействованные блокировки, иногда потому, что эта информация недоступна, но также во избежание затопления информацией. Поэтому в данном случе он ошибается.

`5.` В программе main-signal.c переменная (done) используется для того, чтобы обозначить состояние, когда дочерний процесс закончил работу и родительский может продолжить. Проанализировать эффективность и результат работы helgrind на этой программе.

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/9_4_1.png)

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/9_4_2.png)

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/9_4_3.png)

Основной поток ждет, когда выполнится созданный поток, в данном случае race condition нет, однако helgrind ее показывает, что происходит доступ к общим данным.

`6.` Теперь рассмотреть main-signal-cv.c, которая использует условную переменную (condition variable). Сравнить с предыдущей. Проанализировать main-signal-cv с использованием helgrind.

![alt text](https://github.com/chepurinaaa/OS-labs/blob/master/pic/9_5.png)

В данном случае helgrind не показывает ошибок. Код потокобезопасен.



