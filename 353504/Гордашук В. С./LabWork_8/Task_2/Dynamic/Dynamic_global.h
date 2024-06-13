#ifndef DYNAMIC_GLOBAL_H
#define DYNAMIC_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DYNAMIC_LIBRARY)
#define DYNAMIC_EXPORT Q_DECL_EXPORT
#else
#define DYNAMIC_EXPORT Q_DECL_IMPORT
#endif

#endif // DYNAMIC_GLOBAL_H
