#ifndef LISTHEAP_GLOBAL_H
#define LISTHEAP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LISTHEAP_LIBRARY)
#define LISTHEAP_EXPORT Q_DECL_EXPORT
#else
#define LISTHEAP_EXPORT Q_DECL_IMPORT
#endif

#endif // LISTHEAP_GLOBAL_H
