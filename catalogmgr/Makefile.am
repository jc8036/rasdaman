# -*-Makefile-*- (for Emacs)
# This file is part of rasdaman community.
#
# Rasdaman community is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Rasdaman community is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with rasdaman community.  If not, see <http://www.gnu.org/licenses/>.
#
# Copyright 2003, 2004, 2005, 2006, 2007, 2008, 2009 Peter Baumann /
# rasdaman GmbH.
#
# For more information please see <http://www.rasdaman.org>
# or contact Peter Baumann via <baumann@rasdaman.com>.
# 
# MAKEFILE FOR:  
#   catalogmgr
# 
# COMMENTS: 
# 
##################################################################


RMANBASE=@abs_top_srcdir@
BASEDBCXXFLAGS=@BASEDBCXXFLAGS@
BASEDBLDFLAGS=@BASEDBLDFLAGS@

AM_CXXFLAGS= $(BASEDBCXXFLAGS)
AM_LDFLAGS= $(BASEDBLDFLAGS)    

# object files to put in library
lib_LIBRARIES=libcatalogmgr.a
libcatalogmgr_a_SOURCES=ops.cc typefactory.cc algebraops.cc ops.hh \
                        typefactory.hh algebraops.hh autogen_ops.hh
EXTRA_libcatalogmgr_a_SOURCES = autogen_ops.cc

