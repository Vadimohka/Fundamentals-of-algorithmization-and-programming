#ifndef STRING_GLOBAL_H
#define STRING_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(STRING_LIBRARY)
#define STRING_EXPORT Q_DECL_EXPORT
#else
#define STRING_EXPORT Q_DECL_IMPORT
#endif

#endif // STRING_GLOBAL_H
