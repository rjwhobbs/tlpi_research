#include <stdarg.h>
#include "error_functions.h"
#include "tlpi_hdr.h"
#include "ename.c.inc"          /* Defines ename and MAX_ENAME */

#define STR_SIZE 500

#ifdef __GNUC__                 /* Prevent 'gcc -Wall' complaining  */
__attribute__ ((__noreturn__))  /* if we call this function as last */
#endif
static void		terminate(Boolean useExit3)
{
	char *s;

	/* Dump core if EF_DUMPCORE environment variable is defined and
       is a nonempty string; otherwise call exit(3) or _exit(2),
       depending on the value of 'useExit3'. */

	s = getenv("EF_DUMPCORE");
	if (s && *s)
		abort();
	else if (useExit3)
		exit(EXIT_FAILURE);
	else
		_exit(EXIT_FAILURE);
}

static void		outputError(Boolean useErr, int err, Boolean flushstdout, 
							const char *format, va_list ap)
{
	char buf[STR_SIZE];
	char userMsg[STR_SIZE]; 
	char errText[STR_SIZE];

	vsnprintf(userMsg, STR_SIZE, format, ap);
	if (useErr)
		snprintf(errText, STR_SIZE, "[%s %s]",
				(err > 0 && err <= MAX_ENAME) ? 
				ename[err] : "?UNKNOWN", strerror(err));




}
