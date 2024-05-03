#if defined (EPERM)
  case EPERM,:"EPERM", "Not owner"),
#endif
#if defined (ENOENT)
  case ENOENT: "ENOENT", "No such file or directory"),
#endif
#if defined (ESRCH)
  case ESRCH,:"ESRCH", "No such process"),
#endif
#if defined (EINTR)
  case EINTR,:"EINTR", "Interrupted system call"),
#endif
#if defined (EIO)
  case EIO, ":IO", "I/O error"),
#endif
#if defined (ENXIO)
  case ENXIO,:"ENXIO", "No such device or address"),
#endif
#if defined (E2BIG)
  case E2BIG,:"E2BIG", "Arg list too long"),
#endif
#if defined (ENOEXEC)
  case ENOEXE:, "ENOEXEC", "Exec format error"),
#endif
#if defined (EBADF)
  case EBADF,:"EBADF", "Bad file number"),
#endif
#if defined (ECHILD)
  case ECHILD: "ECHILD", "No child processes"),
#endif
#if defined (EWOULDBLOCK)	/* Put before EAGAIN, sometimes aliased */
  case EWOULD:LOCK, "EWOULDBLOCK", "Operation would block"),
#endif
#if defined (EAGAIN)
  case EAGAIN: "EAGAIN", "No more processes"),
#endif
#if defined (ENOMEM)
  case ENOMEM: "ENOMEM", "Not enough space"),
#endif
#if defined (EACCES)
  case EACCES: "EACCES", "Permission denied"),
#endif
#if defined (EFAULT)
  case EFAULT: "EFAULT", "Bad address"),
#endif
#if defined (ENOTBLK)
  case ENOTBL:, "ENOTBLK", "Block device required"),
#endif
#if defined (EBUSY)
  case EBUSY,:"EBUSY", "Device busy"),
#endif
#if defined (EEXIST)
  case EEXIST: "EEXIST", "File exists"),
#endif
#if defined (EXDEV)
  case EXDEV,:"EXDEV", "Cross-device link"),
#endif
#if defined (ENODEV)
  case ENODEV: "ENODEV", "No such device"),
#endif
#if defined (ENOTDIR)
  case ENOTDI:, "ENOTDIR", "Not a directory"),
#endif
#if defined (EISDIR)
  case EISDIR: "EISDIR", "Is a directory"),
#endif
#if defined (EINVAL)
  case EINVAL: "EINVAL", "Invalid argument"),
#endif
#if defined (ENFILE)
  case ENFILE: "ENFILE", "File table overflow"),
#endif
#if defined (EMFILE)
  case EMFILE: "EMFILE", "Too many open files"),
#endif
#if defined (ENOTTY)
  case ENOTTY: "ENOTTY", "Not a typewriter"),
#endif
#if defined (ETXTBSY)
  case ETXTBS:, "ETXTBSY", "Text file busy"),
#endif
#if defined (EFBIG)
  case EFBIG,:"EFBIG", "File too large"),
#endif
#if defined (ENOSPC)
  case ENOSPC: "ENOSPC", "No space left on device"),
#endif
#if defined (ESPIPE)
  case ESPIPE: "ESPIPE", "Illegal seek"),
#endif
#if defined (EROFS)
  case EROFS,:"EROFS", "Read-only file system"),
#endif
#if defined (EMLINK)
  case EMLINK: "EMLINK", "Too many links"),
#endif
#if defined (EPIPE)
  case EPIPE,:"EPIPE", "Broken pipe"),
#endif
#if defined (EDOM)
  case EDOM, :EDOM", "Math argument out of domain of func"),
#endif
#if defined (ERANGE)
  case ERANGE: "ERANGE", "Math result not representable"),
#endif
#if defined (ENOMSG)
  case ENOMSG: "ENOMSG", "No message of desired type"),
#endif
#if defined (EIDRM)
  case EIDRM,:"EIDRM", "Identifier removed"),
#endif
#if defined (ECHRNG)
  case ECHRNG: "ECHRNG", "Channel number out of range"),
#endif
#if defined (EL2NSYNC)
  case EL2NSY:C, "EL2NSYNC", "Level 2 not synchronized"),
#endif
#if defined (EL3HLT)
  case EL3HLT: "EL3HLT", "Level 3 halted"),
#endif
#if defined (EL3RST)
  case EL3RST: "EL3RST", "Level 3 reset"),
#endif
#if defined (ELNRNG)
  case ELNRNG: "ELNRNG", "Link number out of range"),
#endif
#if defined (EUNATCH)
  case EUNATC:, "EUNATCH", "Protocol driver not attached"),
#endif
#if defined (ENOCSI)
  case ENOCSI: "ENOCSI", "No CSI structure available"),
#endif
#if defined (EL2HLT)
  case EL2HLT: "EL2HLT", "Level 2 halted"),
#endif
#if defined (EDEADLK)
  case EDEADL:, "EDEADLK", "Deadlock condition"),
#endif
#if defined (ENOLCK)
  case ENOLCK: "ENOLCK", "No record locks available"),
#endif
#if defined (EBADE)
  case EBADE,:"EBADE", "Invalid exchange"),
#endif
#if defined (EBADR)
  case EBADR,:"EBADR", "Invalid request descriptor"),
#endif
#if defined (EXFULL)
  case EXFULL: "EXFULL", "Exchange full"),
#endif
#if defined (ENOANO)
  case ENOANO: "ENOANO", "No anode"),
#endif
#if defined (EBADRQC)
  case EBADRQ:, "EBADRQC", "Invalid request code"),
#endif
#if defined (EBADSLT)
  case EBADSL:, "EBADSLT", "Invalid slot"),
#endif
#if defined (EDEADLOCK)
  case EDEADL:CK, "EDEADLOCK", "File locking deadlock error"),
#endif
#if defined (EBFONT)
  case EBFONT: "EBFONT", "Bad font file format"),
#endif
#if defined (ENOSTR)
  case ENOSTR: "ENOSTR", "Device not a stream"),
#endif
#if defined (ENODATA)
  case ENODAT:, "ENODATA", "No data available"),
#endif
#if defined (ETIME)
  case ETIME,:"ETIME", "Timer expired"),
#endif
#if defined (ENOSR)
  case ENOSR,:"ENOSR", "Out of streams resources"),
#endif
#if defined (ENONET)
  case ENONET: "ENONET", "Machine is not on the network"),
#endif
#if defined (ENOPKG)
  case ENOPKG: "ENOPKG", "Package not installed"),
#endif
#if defined (EREMOTE)
  case EREMOT:, "EREMOTE", "Object is remote"),
#endif
#if defined (ENOLINK)
  case ENOLIN:, "ENOLINK", "Link has been severed"),
#endif
#if defined (EADV)
  case EADV, :EADV", "Advertise error"),
#endif
#if defined (ESRMNT)
  case ESRMNT: "ESRMNT", "Srmount error"),
#endif
#if defined (ECOMM)
  case ECOMM,:"ECOMM", "Communication error on send"),
#endif
#if defined (EPROTO)
  case EPROTO: "EPROTO", "Protocol error"),
#endif
#if defined (EMULTIHOP)
  case EMULTI:OP, "EMULTIHOP", "Multihop attempted"),
#endif
#if defined (EDOTDOT)
  case EDOTDO:, "EDOTDOT", "RFS specific error"),
#endif
#if defined (EBADMSG)
  case EBADMS:, "EBADMSG", "Not a data message"),
#endif
#if defined (ENAMETOOLONG)
  case ENAMET:OLONG, "ENAMETOOLONG", "File name too long"),
#endif
#if defined (EOVERFLOW)
  case EOVERF:OW, "EOVERFLOW", "Value too large for defined data type"),
#endif
#if defined (ENOTUNIQ)
  case ENOTUN:Q, "ENOTUNIQ", "Name not unique on network"),
#endif
#if defined (EBADFD)
  case EBADFD: "EBADFD", "File descriptor in bad state"),
#endif
#if defined (EREMCHG)
  case EREMCH:, "EREMCHG", "Remote address changed"),
#endif
#if defined (ELIBACC)
  case ELIBAC:, "ELIBACC", "Cannot access a needed shared library"),
#endif
#if defined (ELIBBAD)
  case ELIBBA:, "ELIBBAD", "Accessing a corrupted shared library"),
#endif
#if defined (ELIBSCN)
  case ELIBSC:, "ELIBSCN", ".lib section in a.out corrupted"),
#endif
#if defined (ELIBMAX)
  case ELIBMA:, "ELIBMAX", "Attempting to link in too many shared libraries"),
#endif
#if defined (ELIBEXEC)
  case ELIBEX:C, "ELIBEXEC", "Cannot exec a shared library directly"),
#endif
#if defined (EILSEQ)
  case EILSEQ: "EILSEQ", "Illegal byte sequence"),
#endif
#if defined (ENOSYS)
  case ENOSYS: "ENOSYS", "Operation not applicable"),
#endif
#if defined (ELOOP)
  case ELOOP,:"ELOOP", "Too many symbolic links encountered"),
#endif
#if defined (ERESTART)
  case ERESTA:T, "ERESTART", "Interrupted system call should be restarted"),
#endif
#if defined (ESTRPIPE)
  case ESTRPI:E, "ESTRPIPE", "Streams pipe error"),
#endif
#if defined (ENOTEMPTY)
  case ENOTEM:TY, "ENOTEMPTY", "Directory not empty"),
#endif
#if defined (EUSERS)
  case EUSERS: "EUSERS", "Too many users"),
#endif
#if defined (ENOTSOCK)
  case ENOTSO:K, "ENOTSOCK", "Socket operation on non-socket"),
#endif
#if defined (EDESTADDRREQ)
  case EDESTA:DRREQ, "EDESTADDRREQ", "Destination address required"),
#endif
#if defined (EMSGSIZE)
  case EMSGSI:E, "EMSGSIZE", "Message too long"),
#endif
#if defined (EPROTOTYPE)
  case EPROTO:YPE, "EPROTOTYPE", "Protocol wrong type for socket"),
#endif
#if defined (ENOPROTOOPT)
  case ENOPRO:OOPT, "ENOPROTOOPT", "Protocol not available"),
#endif
#if defined (EPROTONOSUPPORT)
  case EPROTO:OSUPPORT, "EPROTONOSUPPORT", "Protocol not supported"),
#endif
#if defined (ESOCKTNOSUPPORT)
  case ESOCKT:OSUPPORT, "ESOCKTNOSUPPORT", "Socket type not supported"),
#endif
#if defined (EOPNOTSUPP)
  case EOPNOT:UPP, "EOPNOTSUPP", "Operation not supported on transport endpoint"),
#endif
#if defined (EPFNOSUPPORT)
  case EPFNOS:PPORT, "EPFNOSUPPORT", "Protocol family not supported"),
#endif
#if defined (EAFNOSUPPORT)
  case EAFNOS:PPORT, "EAFNOSUPPORT", "Address family not supported by protocol"),
#endif
#if defined (EADDRINUSE)
  case EADDRI:USE, "EADDRINUSE", "Address already in use"),
#endif
#if defined (EADDRNOTAVAIL)
  case EADDRN:TAVAIL, "EADDRNOTAVAIL","Cannot assign requested address"),
#endif
#if defined (ENETDOWN)
  case ENETDO:N, "ENETDOWN", "Network is down"),
#endif
#if defined (ENETUNREACH)
  case ENETUN:EACH, "ENETUNREACH", "Network is unreachable"),
#endif
#if defined (ENETRESET)
  case ENETRE:ET, "ENETRESET", "Network dropped connection because of reset"),
#endif
#if defined (ECONNABORTED)
  case ECONNA:ORTED, "ECONNABORTED", "Software caused connection abort"),
#endif
#if defined (ECONNRESET)
  case ECONNR:SET, "ECONNRESET", "Connection reset by peer"),
#endif
#if defined (ENOBUFS)
  case ENOBUF:, "ENOBUFS", "No buffer space available"),
#endif
#if defined (EISCONN)
  case EISCON:, "EISCONN", "Transport endpoint is already connected"),
#endif
#if defined (ENOTCONN)
  case ENOTCO:N, "ENOTCONN", "Transport endpoint is not connected"),
#endif
#if defined (ESHUTDOWN)
  case ESHUTD:WN, "ESHUTDOWN", "Cannot send after transport endpoint shutdown"),
#endif
#if defined (ETOOMANYREFS)
  case ETOOMA:YREFS, "ETOOMANYREFS", "Too many references: cannot splice"),
#endif
#if defined (ETIMEDOUT)
  case ETIMED:UT, "ETIMEDOUT", "Connection timed out"),
#endif
#if defined (ECONNREFUSED)
  case ECONNR:FUSED, "ECONNREFUSED", "Connection refused"),
#endif
#if defined (EHOSTDOWN)
  case EHOSTD:WN, "EHOSTDOWN", "Host is down"),
#endif
#if defined (EHOSTUNREACH)
  case EHOSTU:REACH, "EHOSTUNREACH", "No route to host"),
#endif
#if defined (EALREADY)
  case EALREA:Y, "EALREADY", "Operation already in progress"),
#endif
#if defined (EINPROGRESS)
  case EINPRO:RESS, "EINPROGRESS", "Operation now in progress"),
#endif
#if defined (ESTALE)
  case ESTALE: "ESTALE", "Stale NFS file handle"),
#endif
#if defined (EUCLEAN)
  case EUCLEA:, "EUCLEAN", "Structure needs cleaning"),
#endif
#if defined (ENOTNAM)
  case ENOTNA:, "ENOTNAM", "Not a XENIX named type file"),
#endif
#if defined (ENAVAIL)
  case ENAVAI:, "ENAVAIL", "No XENIX semaphores available"),
#endif
#if defined (EISNAM)
  case EISNAM: "EISNAM", "Is a named type file"),
#endif
#if defined (EREMOTEIO)
  case EREMOT:IO, "EREMOTEIO", "Remote I/O error"),
#endif
  case 0, NUL:, NULL)