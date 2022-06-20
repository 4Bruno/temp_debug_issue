#include <stdio.h>
#include <unistd.h> // sysconf
#include <stdarg.h>

#define log(str, ...) log_(str "\n", ## __VA_ARGS__);
#define Assert(cond) if (!(cond)) { *(int *)0 = 0; };

static FILE * log_file;
void
log_(const char *format, ...)
{
  va_list args;
  va_start(args, format);

#if 1
  vprintf(format, args);
#else
  int bytes_written = fprintf(log_file,format, args);
  if (bytes_written < 0)
  {
    perror("Error calling fprintf(): ");
  }
  fflush(log_file);
#endif

  va_end(args);
}

int
main()
{
  const char * log_file_name = "./debug_printf.log";
  log_file = fopen(log_file_name, "w+");
  Assert(log_file != NULL);

  log("path is %s", log_file_name);

  fclose(log_file);
}
