#ifndef QUILIB_GLOBAL_H
#define QUILIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QUILIB_LIBRARY)
#  define QUILIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QUILIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QUILIB_GLOBAL_H
