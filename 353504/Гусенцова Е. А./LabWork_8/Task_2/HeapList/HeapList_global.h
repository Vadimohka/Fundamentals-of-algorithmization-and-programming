#ifndef HEAPLIST_GLOBAL_H
#define HEAPLIST_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HEAPLIST_LIBRARY)
#define HEAPLIST_EXPORT Q_DECL_EXPORT
#else
#define HEAPLIST_EXPORT Q_DECL_IMPORT
#endif

#endif // HEAPLIST_GLOBAL_H
