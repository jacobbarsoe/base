# -*- mode:python; -*-
DESCRIPTION = "ifplugd is a Linux daemon which will automatically configure \
	your ethernet device when a cable is plugged in and automatically \
	unconfigure it if the cable is pulled."
HOMEPAGE = "http://0pointer.de/lennart/projects/ifplugd/"

RECIPE_TYPES = "machine"
COMPATIBLE_HOST_ARCHS = ".*linux"

inherit c++ autotools pkgconfig sysvinit

SRC_URI = "http://0pointer.de/lennart/projects/ifplugd/ifplugd-${PV}.tar.gz"

DEPENDS = "libdaemon"

EXTRA_OECONF = "--disable-lynx"

RECIPE_FLAGS += "ifplugd_sysvinit_start ifplugd_sysvinit_stop"
SYSVINIT_SCRIPT_ifplugd = "ifplugd"
DEFAULT_USE_ifplugd_sysvinit_start = "25"
DEFAULT_USE_ifplugd_sysvinit_stop  = "20"

PACKAGES =+ "${PN}-conf"

FILES_${PN}-conf = "${sysconfdir}/ifplugd/" 

RDEPENDS_${PN} = "libdaemon ${PN}-conf"
