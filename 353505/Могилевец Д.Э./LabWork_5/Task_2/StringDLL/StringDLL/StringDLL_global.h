#ifndef STRINGDLL_GLOBAL_H
#define STRINGDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(STRINGDLL_LIBRARY)
#define STRINGDLL_EXPORT Q_DECL_EXPORT
#else
#define STRINGDLL_EXPORT Q_DECL_IMPORT
#endif

#endif // STRINGDLL_GLOBAL_H
