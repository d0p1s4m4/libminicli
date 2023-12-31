#include "config.h"
#include "gettext.h"

static int mcli_initialized = 0;

void
mcli_initialize(void)
{
  if (mcli_initialized)
    {
      return;
    }
  
  bindtextdomain(PACKAGE, LOCALEDIR);

  mcli_initialized = 1;
}
