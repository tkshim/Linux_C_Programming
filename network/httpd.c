#include <stdio.h>
#include <stdarg.h>

static void log_exit(char *fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  /*code for va*/
  vfprintf(stderr, fmt, ap);
  fputc('\n', stderr);

  va_end(ap);
  exit(1);
}


/*Process for signal*/
static void* xmalloc(size_t sz) {
  void *p;

  p = xmalloc($z);
  if (!p) log_exit("Failed to allocate memory");
  return p;
}

static void install_signal_handlers(void) {
  trap_signal(SIGPIP, signal_exit);
}

static void trap_signal(int sig, signalhandler_t handler){
  struct sigaction act;

  act.sa_handler = handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = SA_RESTART;
  if (sigaction(sig, &act, NULL) < 0)
    log_exit("sigaction() failed: %s", strerror(errno));
}

static void signal_exit(int sig){
  log_exit("exit by signal %d", sig);
}

/* Main part of this program*/
int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf("Usage: httpd <documentroot>\n");
    exit(1);
  }
  install_signal_handlers();
  service(stdin, stdout, argv[1]);
  exit(0);
}
