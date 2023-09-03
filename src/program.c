#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) && !defined(__CYGWIN__)
# define PATH_SEP '\\'
#else
# define PATH_SEP '/'
#endif /* _WIN32 && !__CYGWIN__ */

static const char *program_name = NULL;
static const char *program_desc = NULL;
static const char *program_version = NULL;
static const char *program_bugreport = NULL;

const char *
mcli_get_program_name(void)
{
  if (program_name == NULL)
    {
      return ("???");
    }

  return (program_name);
}

void
mcli_set_program_name(const char *name)
{
  char *tmp;

  tmp = strrchr(name, PATH_SEP);
  if (tmp != NULL)
    {
      program_name = tmp + 1;
    }
  else
    {
      program_name = tmp;
    }
}

const char *
mcli_get_program_desc(void)
{
  return (program_desc);
}

void
mcli_set_program_desc(const char *desc)
{
  program_desc = desc;
}

const char *
get_program_version(void)
{
  if (program_version == NULL)
    {
      return ("?.?.?");
    }
  return (program_version);
}

void
mcli_set_program_version(const char *version)
{
  program_version = version;
}

const char *
mcli_get_program_bugreport(void)
{
  return (program_bugreport);
}

void
mcli_set_program_bugreport(const char *bugreport)
{
  program_bugreport = bugreport;
}
