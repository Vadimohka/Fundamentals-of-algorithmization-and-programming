#include <errno.h>

const char *getErrnoMsg(int errn) {
  switch (errn) {
#ifdef EPERM
  case EPERM:
    return "Not owner";
#endif
#ifdef ENOENT
  case ENOENT:
    return "No such file or directory";
#endif
#ifdef ESRCH
  case ESRCH:
    return "No such process";
#endif
#ifdef EINTR
  case EINTR:
    return "Interrupted system call";
#endif
#ifdef EIO
  case EIO:
    return "I/O error";
#endif
#ifdef ENXIO
  case ENXIO:
    return "No such device or address";
#endif
#ifdef E2BIG
  case E2BIG:
    return "Arg list too long";
#endif
#ifdef ENOEXEC
  case ENOEXEC:
    return "Exec format error";
#endif
#ifdef EBADF
  case EBADF:
    return "Bad file number";
#endif
#ifdef ECHILD
  case ECHILD:
    return "No child processes";
#endif
#ifdef EWOULDBLOCK
  case EWOULDBLOCK:
    return "Operation would block";
#endif
// #ifdef EAGAIN
//   case EAGAIN:
//     return "No more processes";
// #endif
#ifdef ENOMEM
  case ENOMEM:
    return "Not enough space";
#endif
#ifdef EACCES
  case EACCES:
    return "Permission denied";
#endif
#ifdef EFAULT
  case EFAULT:
    return "Bad address";
#endif
#ifdef ENOTBLK
  case ENOTBLK:
    return "Block device required";
#endif
#ifdef EBUSY
  case EBUSY:
    return "Device busy";
#endif
#ifdef EEXIST
  case EEXIST:
    return "File exists";
#endif
#ifdef EXDEV
  case EXDEV:
    return "Cross-device link";
#endif
#ifdef ENODEV
  case ENODEV:
    return "No such device";
#endif
#ifdef ENOTDIR
  case ENOTDIR:
    return "Not a directory";
#endif
#ifdef EISDIR
  case EISDIR:
    return "Is a directory";
#endif
#ifdef EINVAL
  case EINVAL:
    return "Invalid argument";
#endif
#ifdef ENFILE
  case ENFILE:
    return "File table overflow";
#endif
#ifdef EMFILE
  case EMFILE:
    return "Too many open files";
#endif
#ifdef ENOTTY
  case ENOTTY:
    return "Not a typewriter";
#endif
#ifdef ETXTBSY
  case ETXTBSY:
    return "Text file busy";
#endif
#ifdef EFBIG
  case EFBIG:
    return "File too large";
#endif
#ifdef ENOSPC
  case ENOSPC:
    return "No space left on device";
#endif
#ifdef ESPIPE
  case ESPIPE:
    return "Illegal seek";
#endif
#ifdef EROFS
  case EROFS:
    return "Read-only file system";
#endif
#ifdef EMLINK
  case EMLINK:
    return "Too many links";
#endif
#ifdef EPIPE
  case EPIPE:
    return "Broken pipe";
#endif
#ifdef EDOM
  case EDOM:
    return "Math argument out of domain of func";
#endif
#ifdef ERANGE
  case ERANGE:
    return "Math result not representable";
#endif
#ifdef ENOMSG
  case ENOMSG:
    return "No message of desired type";
#endif
#ifdef EIDRM
  case EIDRM:
    return "Identifier removed";
#endif
#ifdef ECHRNG
  case ECHRNG:
    return "Channel number out of range";
#endif
#ifdef EL2NSYNC
  case EL2NSYNC:
    return "Level 2 not synchronized";
#endif
#ifdef EL3HLT
  case EL3HLT:
    return "Level 3 halted";
#endif
#ifdef EL3RST
  case EL3RST:
    return "Level 3 reset";
#endif
#ifdef ELNRNG
  case ELNRNG:
    return "Link number out of range";
#endif
#ifdef EUNATCH
  case EUNATCH:
    return "Protocol driver not attached";
#endif
#ifdef ENOCSI
  case ENOCSI:
    return "No CSI structure available";
#endif
#ifdef EL2HLT
  case EL2HLT:
    return "Level 2 halted";
#endif
#ifdef EDEADLK
  case EDEADLK:
    return "Deadlock condition";
#endif
#ifdef ENOLCK
  case ENOLCK:
    return "No record locks available";
#endif
#ifdef EBADE
  case EBADE:
    return "Invalid exchange";
#endif
#ifdef EBADR
  case EBADR:
    return "Invalid request descriptor";
#endif
#ifdef EXFULL
  case EXFULL:
    return "Exchange full";
#endif
#ifdef ENOANO
  case ENOANO:
    return "No anode";
#endif
#ifdef EBADRQC
  case EBADRQC:
    return "Invalid request code";
#endif
#ifdef EBADSLT
  case EBADSLT:
    return "Invalid slot";
#endif
// #ifdef EDEADLOCK
//   case EDEADLOCK:
//     return "File locking deadlock error";
// #endif
#ifdef EBFONT
  case EBFONT:
    return "Bad font file format";
#endif
#ifdef ENOSTR
  case ENOSTR:
    return "Device not a stream";
#endif
#ifdef ENODATA
  case ENODATA:
    return "No data available";
#endif
#ifdef ETIME
  case ETIME:
    return "Timer expired";
#endif
#ifdef ENOSR
  case ENOSR:
    return "Out of streams resources";
#endif
#ifdef ENONET
  case ENONET:
    return "Machine is not on the network";
#endif
#ifdef ENOPKG
  case ENOPKG:
    return "Package not installed";
#endif
#ifdef EREMOTE
  case EREMOTE:
    return "Object is remote";
#endif
#ifdef ENOLINK
  case ENOLINK:
    return "Link has been severed";
#endif
#ifdef EADV
  case EADV:
    return "Advertise error";
#endif
#ifdef ESRMNT
  case ESRMNT:
    return "Srmount error";
#endif
#ifdef ECOMM
  case ECOMM:
    return "Communication error on send";
#endif
#ifdef EPROTO
  case EPROTO:
    return "Protocol error";
#endif
#ifdef EMULTIHOP
  case EMULTIHOP:
    return "Multihop attempted";
#endif
#ifdef EDOTDOT
  case EDOTDOT:
    return "RFS specific error";
#endif
#ifdef EBADMSG
  case EBADMSG:
    return "Not a data message";
#endif
#ifdef ENAMETOOLONG
  case ENAMETOOLONG:
    return "File name too long";
#endif
#ifdef EOVERFLOW
  case EOVERFLOW:
    return "Value too large for defined data type";
#endif
#ifdef ENOTUNIQ
  case ENOTUNIQ:
    return "Name not unique on network";
#endif
#ifdef EBADFD
  case EBADFD:
    return "File descriptor in bad state";
#endif
#ifdef EREMCHG
  case EREMCHG:
    return "Remote address changed";
#endif
#ifdef ELIBACC
  case ELIBACC:
    return "Cannot access a needed shared library";
#endif
#ifdef ELIBBAD
  case ELIBBAD:
    return "Accessing a corrupted shared library";
#endif
#ifdef ELIBSCN
  case ELIBSCN:
    return ".lib section in a.out corrupted";
#endif
#ifdef ELIBMAX
  case ELIBMAX:
    return "Attempting to link in too many shared libraries";
#endif
#ifdef ELIBEXEC
  case ELIBEXEC:
    return "Cannot exec a shared library directly";
#endif
#ifdef EILSEQ
  case EILSEQ:
    return "Illegal byte sequence";
#endif
#ifdef ENOSYS
  case ENOSYS:
    return "Operation not applicable";
#endif
#ifdef ELOOP
  case ELOOP:
    return "Too many symbolic links encountered";
#endif
#ifdef ERESTART
  case ERESTART:
    return "Interrupted system call should be restarted";
#endif
#ifdef ESTRPIPE
  case ESTRPIPE:
    return "Streams pipe error";
#endif
#ifdef ENOTEMPTY
  case ENOTEMPTY:
    return "Directory not empty";
#endif
#ifdef EUSERS
  case EUSERS:
    return "Too many users";
#endif
#ifdef ENOTSOCK
  case ENOTSOCK:
    return "Socket operation on non-socket";
#endif
#ifdef EDESTADDRREQ
  case EDESTADDRREQ:
    return "Destination address required";
#endif
#ifdef EMSGSIZE
  case EMSGSIZE:
    return "Message too long";
#endif
#ifdef EPROTOTYPE
  case EPROTOTYPE:
    return "Protocol wrong type for socket";
#endif
#ifdef ENOPROTOOPT
  case ENOPROTOOPT:
    return "Protocol not available";
#endif
#ifdef EPROTONOSUPPORT
  case EPROTONOSUPPORT:
    return "Protocol not supported";
#endif
#ifdef ESOCKTNOSUPPORT
  case ESOCKTNOSUPPORT:
    return "Socket type not supported";
#endif
#ifdef EOPNOTSUPP
  case EOPNOTSUPP:
    return "Operation not supported on transport endpoint";
#endif
#ifdef EPFNOSUPPORT
  case EPFNOSUPPORT:
    return "Protocol family not supported";
#endif
#ifdef EAFNOSUPPORT
  case EAFNOSUPPORT:
    return "Address family not supported by protocol";
#endif
#ifdef EADDRINUSE
  case EADDRINUSE:
    return "Address already in use";
#endif
#ifdef EADDRNOTAVAIL
  case EADDRNOTAVAIL:
    return "Cannot assign requested address";
#endif
#ifdef ENETDOWN
  case ENETDOWN:
    return "Network is down";
#endif
#ifdef ENETUNREACH
  case ENETUNREACH:
    return "Network is unreachable";
#endif
#ifdef ENETRESET
  case ENETRESET:
    return "Network dropped connection because of reset";
#endif
#ifdef ECONNABORTED
  case ECONNABORTED:
    return "Software caused connection abort";
#endif
#ifdef ECONNRESET
  case ECONNRESET:
    return "Connection reset by peer";
#endif
#ifdef ENOBUFS
  case ENOBUFS:
    return "No buffer space available";
#endif
#ifdef EISCONN
  case EISCONN:
    return "Transport endpoint is already connected";
#endif
#ifdef ENOTCONN
  case ENOTCONN:
    return "Transport endpoint is not connected";
#endif
#ifdef ESHUTDOWN
  case ESHUTDOWN:
    return "Cannot send after transport endpoint shutdown";
#endif
#ifdef ETOOMANYREFS
  case ETOOMANYREFS:
    return "Too many references: cannot splice";
#endif
#ifdef ETIMEDOUT
  case ETIMEDOUT:
    return "Connection timed out";
#endif
#ifdef ECONNREFUSED
  case ECONNREFUSED:
    return "Connection refused";
#endif
#ifdef EHOSTDOWN
  case EHOSTDOWN:
    return "Host is down";
#endif
#ifdef EHOSTUNREACH
  case EHOSTUNREACH:
    return "No route to host";
#endif
#ifdef EALREADY
  case EALREADY:
    return "Operation already in progress";
#endif
#ifdef EINPROGRESS
  case EINPROGRESS:
    return "Operation now in progress";
#endif
#ifdef ESTALE
  case ESTALE:
    return "Stale NFS file handle";
#endif
#ifdef EUCLEAN
  case EUCLEAN:
    return "Structure needs cleaning";
#endif
#ifdef ENOTNAM
  case ENOTNAM:
    return "Not a XENIX named type file";
#endif
#ifdef ENAVAIL
  case ENAVAIL:
    return "No XENIX semaphores available";
#endif
#ifdef EISNAM
  case EISNAM:
    return "Is a named type file";
#endif
#ifdef EREMOTEIO
  case EREMOTEIO:
    return "Remote I/O error";
#endif
  default:
    return "";
  }
}