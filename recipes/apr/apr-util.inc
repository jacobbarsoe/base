DESCRIPTION = "software libraries providing a predictable and consistent interface to underlying platform-specific implementations"
HOMEPAGE = "apr.apache.org"

COMPATIBLE_HOST_ARCHS = ".*linux .*darwin"

inherit autotools make-vpath pkgconfig library binconfig c

SRC_URI = "http://apache.mirrors.spacedump.net/apr/apr-util-${PV}.tar.bz2"

DEPENDS += "libapr-1 libexpat ${DEPENDS_LIBC}"
DEPENDS_LIBC = "libdl libcrypt"
DEPENDS_LIBC:HOST_LIBC_mingw = ""
DEPENDS_${PN} += "libapr-1 libexpat ${DEPENDS_LIBC}"
RDEPENDS_${PN} += "libapr-1 libexpat ${DEPENDS_LIBC}"

EXTRA_OECONF = "--with-apr=${HOST_SYSROOT}${bindir}/apr-1-config \
	--with-expat=${HOST_SYSROOT}${libdir}/.. \
        --without-odbc --without-pgsql --without-sqlite2 --without-sqlite3 \
"

do_configure[postfuncs] = "do_configure_apr"

do_configure_apr() {
	sed -e "s#\(--sysroot=\).* .*#\1${HOST_SYSROOT}#" \
	    -e "s#apr_builddir=#apr_builddir=${HOST_SYSROOT}#" \
	    -e "s#apr_builders=#apr_builders=${HOST_SYSROOT}#" \
	    -e "s#top_builddir=#top_builddir=${HOST_SYSROOT}#" \
	    -i ${B}/build/rules.mk
}

LIBRARY_NAME = "libaprutil-1"
LIBRARY_VERSION = "0"

FILES_${PN}-dev += "${libdir}/aprutil.exp"
