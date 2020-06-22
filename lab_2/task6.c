#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    //printf("hello world (pid:%d)\n", (int) getpid());
    int fd[2];
    if(pipe(fd) < 0){
        /* Если создать pipe не удалось, печатаем об этом сообщение
        и прекращаем работу */
        printf("Can\'t create pipe\n");
        exit(-1);
    }
    int rc_1 = fork();
    if (rc_1 < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc_1 == 0) {
        close(fd[0]); //Мы находимся в родительском процессе, который будет
                          // передавать информацию процессу-ребенку. В этом процессе
                          // выходной поток данных нам не понадобится, поэтому закрываем его
        char string[] = "Hello, world!";
        auto size = write(fd[1], string, 14);
        close(fd[1]); //Закрываем входной поток данных, на
        // этом родитель прекращает работу
    } else { //В этом процессе входной поток данных нам не понадобится, поэтому закрываем его.
        close(fd[1]);
        auto rc_2 = fork(); //создаем новый процесс
        if (rc_2 < 0) {
            // fork failed; exit
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (rc_2 == 0) {
            // child (new process)
            char resstring[14];
            auto size = read(fd[0], resstring, 14);
            printf("%s\n",resstring);
            close(fd[0]); //Закрываем входной поток и завершаем работу
        }

    }
    return 0;
}