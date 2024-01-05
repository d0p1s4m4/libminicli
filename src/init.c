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

#ifdef ENABLE_NLS
  bindtextdomain(PACKAGE, LOCALEDIR);
#endif

  mcli_initialized = 1;
}
