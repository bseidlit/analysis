AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include \
  -I`root-config --incdir`

lib_LTLIBRARIES = \
  libjetrhomedian.la

libjetrhomedian_la_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib \
  `fastjet-config --libs`

libjetrhomedian_la_LIBADD = \
  -lfun4all \
  -lg4dst \
  -lg4eval

libjetrhomedian_la_SOURCES = \
  PrintTowers.cc \
  JetRhoMedian.cc \
  RhoFluct.cc

pkginclude_HEADERS = \
  PrintTowers.h \
  JetRhoMedian.h \
  RhoFluct.h
 
################################################
# linking tests

noinst_PROGRAMS = testexternals

BUILT_SOURCES = \
  testexternals.cc

testexternals_SOURCES = \
  testexternals.cc

testexternals_LDADD = \
  libjetrhomedian.la

testexternals.cc:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

clean-local:
	rm -f $(BUILT_SOURCES)
