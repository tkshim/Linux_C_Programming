# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

int main (int argc, char *argv[]){
  int i;

  if (argc != 3) {
    fprintf(stderr, "Usage: mv <source> <destination>\n");
    exit(1);
  }

  for (i = 1; i < argc; i++) {
    if (rename(argv[1], argv[2]) < 0) {
      perror(argv[0]);
      exit(1);
    }
  }

  exit(0);
}
