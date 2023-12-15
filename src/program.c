/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2023, d0p1
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <stdlib.h>
#include <string.h>
#include "config.h"
#ifdef HAVE_LIBGEN_H
# include <libgen.h>
#endif /* HAVE_LIBGEN_H */

#if defined(__WIN32__) && !defined(__CYGWIN__)
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

#ifdef HAVE_LIBGEN_H
  tmp = (char *)name;
  program_name = basename(tmp);
#else
  tmp = strrchr(name, PATH_SEP);
  if (tmp != NULL)
    {
      program_name = tmp + 1;
    }
  else
    {
      program_name = tmp;
    }
#endif /* !HAVE_LIBGEN_H */
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
mcli_get_program_version(void)
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
