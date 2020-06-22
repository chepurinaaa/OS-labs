Лабораторная работ № 4

`1. `В программу aspace.c добавить malloc() и выяснить в каком направлении происходит добавление динамической памяти (к старшим адресам). Добавить локальную переменную и проверить то, что в стеке адреса задействуются в сторону убывания. Как найти адрес указателя? Что возвращается при оценивании p и &p? 

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2018-57-32.png)

Вывод:

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2018-57-41.png)

Добавим второй malloc(). Можем заметить, что адрес увеличился, потому что  динамическая память добавляется в сторону увеличения к старшим адресам

Т. к. локальные переменные содержатся в стеке, то их адрес будем уменьшаться.

Адрес указателя можно получить с помощью &.

`2.` Объяснить поведение фрагмента кода для переменных name и name1

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2019-16-12.png)

Вывод:

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2019-21-41.png)

Строковый литерал (name1 = "Anna") будет находиться в постоянном сегменте, который доступен только для чтения. Поэтому будет выдаваться ошибка доступа к памяти. Чтобы исправить ошибку, поменяем строку с объявлением переменной name1 на char name1[20]="Anna";

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2019-33-20.png)

Программа работает корректно.

`3.` Разработать программу null. c, которая создает указатель на целое и устанавливает его в NULL Затем она пытается получить значение переменной по указателю (dereference). Объяснить результат запуска откомпилированной программы.

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2019-39-54.png)

NULL в языках программирования Си и C++ — макрос, объявленный в заголовочном файле stddef.h (и других заголовочных файлах). Значением этого макроса является зависящая от реализации константа нулевого указателя. Нулевые указатели придуманы как удобный способ «отметить» указатели, которые заведомо не указывают на корректный адрес в памяти. Обращение по нулевому указателю является подтипом ошибки, вызывающей ошибку segmentation fault. 

`4.` Откомпилировать null.c с ключом -g, запустить dbg null и вызвать команду run. Объяснить реакцию отладчика. 

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2019-53-01.png)

Отладчик обнаружил ошибку segmentation fault.

`5.` Установить и использовать valgrind (memcheck) для анализа ситуации из 4: valgrind --leak-check=yes null (valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt null). Объяснить результат.

Valgrind - это средство поиска ошибок, связанных с утечкой памяти. 

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2020-08-10.png)

Видим, что в 7ой строке возникла ошибка, связанная с разыменовыванием указателя на NULL.

--log-file
    позволяет задать имя файла в который будет выводиться отчет о работе. В заданном имени могут использоваться специальные шаблоны, куда будут подставляться различные значения, например, идентификатор процесса (шаблон %p).

--quiet
    (или -q) подавляет вывод лишней информации, приводя к выводу только информации об ошибках.
    
--leak-check
    включает (значение yes, summary или full) или отключает (значение no) функцию обнаружения утечек памяти. Стоит отметить, что при использовании значения summary, memcheck выдает лишь краткую информацию об утечках памяти, тогда как при других значениях, кроме сводной информации, будет выдаваться еще и информация о месте, в котором происходит эта утечка памяти.

--show-leak-kinds=all 
    показать все виды утечек

--track-origins=<yes|no> [default: no] 
    Управляет отслеживанием Memcheck происхождения неинициализированных значений. По умолчанию это не так, что означает, что, хотя он может сказать вам, что неинициализированное значение используется опасным образом, он не может сказать вам, откуда пришло неинициализированное значение. Это часто затрудняет поиск основной проблемы.
    При значении yes Memcheck отслеживает происхождение всех неинициализированных значений. Затем, когда сообщается об ошибке неинициализированного значения, Memcheck попытается показать происхождение значения. Источник может быть одним из следующих четырех мест: блок кучи, распределение стека, запрос клиента или другие источники (например, вызов brk).
    
--verbose Дает дополнительную информацию о различных аспектах программы.

`6.` Написать простую программу, которая использует malloc(), но не освобождает память по завершению. Использовать gdb и valgrind для того, чтобы объяснить ошибку.

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2020-30-46.png)


![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2020-29-47.png)

Если испольщовать gdb, то утечку памяти можно не увидеть:

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2021-57-20.png)

`7.` Написать программу, которая создает массив целых data размера 100, используя malloc(). Установить data[100] в 0. Запустить программу и найти ошибку (если есть) с помощью valgrind.

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2022-15-45.png)

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2022-07-24.png)

Мы получили две ошибки:
Утечка памяти и обращение по чужому адресу(в строчке присвоения по сотому адресу массива значения)

`8.` Написать программу, которая создает массив целых (как в 7), освобождает его и пытается напечатать значение какого-либо элемента. Диагностировать ошибку с использованием valgrind.

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2022-14-58.png)

![alt text](file:///home/arina/Pictures/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20%D0%BE%D1%82%202020-06-21%2022-13-18.png)

Получаем ошибку обращения к участку освобожденной памяти




