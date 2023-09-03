#ifndef MINICLI_H
# define MINICLI_H

# ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

typedef enum
{
  MCLI_NO_VALUE,
  MCLI_REQUIRED_VALUE,
  MCLI_OPTIONAL_VALUE
} MCliValueInfo;

typedef struct
{
  int short_name;
  const char *long_name;
  MCliValueInfo has_value;
  const char *help_string;
} MCliArgument;

const char *mcli_get_program_name(void);
void mcli_set_program_name(const char *name);
const char *mcli_get_program_desc(void);
void mcli_set_program_desc(const char *desc);
const char *mcli_get_program_version(void);
void mcli_set_program_version(const char *version);
const char *mcli_get_program_bugreport(void);
void mcli_set_program_bugreport(const char *bugreport);

void mcli_usage(const MCliArgument *arguments, int status);
void mcli_version(void);
int mcli_get_argument(const MCliArgument *arguments, int argc, char **argv);

# ifdef __cplusplus
}
# endif /* __cplusplus */

#endif /* !MINICLI_H */
