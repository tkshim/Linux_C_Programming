#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
  pid_t pid;

  /* when you make a mistake about argument*/
  if (argc != 3) {
    fprintf(stderr, "Usage: spawn <command> <arg>\n");
    exit(1);
  }

  pid = fork();
  if (pid < 0) {
    fprintf(stderr, "fork(2) failed.\n");
    exit(1);
  }

  if (pid ==0) {
    execl(argv[1], argv[1], argv[2], NULL);
    perror(argv[1]);
    exit(99);
  }
  else {
    int status;

    /*Wait until fork process is completed*/
    waitpid(pid, &status, 0);

    printf("Child Process (PID=%d) completed.\n", pid);
    /*Normal exit */
    if (WIFEXITED(status))
      printf("OK, status=%d\n", WEXITSTATUS(status));
    /*Signal exit*/
    else if (WIFSIGNALED(status))
      printf("signal, sig=%d\n", WTERMSIG(status));
    /*Other case*/
    else
      printf("abnormal exit\n");

    exit(0);
  }
}
