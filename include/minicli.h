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

void mcli_initialize(void);

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

extern const char *mcli_value;

# ifdef __cplusplus
}
# endif /* __cplusplus */

#endif /* !MINICLI_H */
