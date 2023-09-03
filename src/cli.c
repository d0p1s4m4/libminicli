#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <minicli.h>

static const MCliArgument arg_help = {
  'h', "help", MCLI_NO_VALUE, "display this help and exit"
};

static const MCliArgument arg_version = {
  'V', "version", MCLI_NO_VALUE, "output version information"
};

static void
cli_emit_help(const MCliArgument *arg)
{
  if (arg->long_name)
    {
      printf("-%c, --%-12s %s\n", arg->short_name,
	     arg->long_name, arg->help_string);
    }
  else
    {
      printf("-%c                %s\n", arg->short_name, arg->help_string);
    }
}

void
mcli_usage(const MCliArgument *arguments, int status)
{
  int idx;

  if (status != EXIT_SUCCESS)
    {
      fprintf(stderr, "Try '%s --help' for more information.\n",
	      mcli_get_program_name());
    }
  else
    {
      printf("Usage: %s [OPTION...]\n", mcli_get_program_name());
      if (mcli_get_program_desc() != NULL)
	{
	  printf("%s\n\n", mcli_get_program_desc());
	}
      for (idx = 0; arguments[idx].help_string != NULL; idx++)
	{
	  cli_emit_help(&arguments[idx]);
	}
      cli_emit_help(&arg_help);
      cli_emit_help(&arg_version);
      if (mcli_get_program_bugreport())
	{
	  printf("\nReport bugs to <%s>\n", mcli_get_program_bugreport());
	}
    }

  exit(status);
}

void
mcli_version(void)
{
  printf("%s version %s\n", mcli_get_program_name(), mcli_get_program_version());
  exit(EXIT_SUCCESS);
}

static int
cli_match(const MCliArgument *arg, int a_s, const char *a_l)
{
  if (a_s < 0 && a_l == NULL)
    {
      return (0);
    }
  if (arg->short_name == a_s)
    {
      return (1);
    }

  if (a_l && arg->long_name)
    {
      if (strlen(a_l) > 2)
	{
	  return (strcmp(a_l + 2, arg->long_name) == 0);
	}
    }

  return (0);
}

int
mcli_get_argument(const MCliArgument *arguments, int argc, char **argv)
{
  static int ac = 1;
  int a_s;
  char *a_l;
  int idx;

  if (ac >= argc)
    {
      return (EOF);
    }

  a_s = -1;
  a_l = NULL;

  if (argv[ac][0] == '-')
    {
      if (argv[ac][1] == '-')
	{
	  a_l = argv[ac] + 2;
	}
      else
	{
	  a_s = argv[ac][1];
	}
    }
  ac++;

  if (cli_match(&arg_help, a_s, a_l))
    {
      mcli_usage(arguments, EXIT_SUCCESS);
    }
  if (cli_match(&arg_version, a_s, a_l))
    {
      mcli_version();
    }

  for (idx = 0; arguments[idx].help_string != NULL; idx++)
    {
      if (cli_match(&arguments[idx], a_s, a_l))
	{
	  return (arguments[idx].short_name);
	}
    }


  return (0);
}
