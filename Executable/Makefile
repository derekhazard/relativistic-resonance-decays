######################

CXX           = g++
LD            = g++

#############################

os = $(shell uname -s)

INSTALL_DIR=/opt/local
GSL=$(INSTALL_DIR)

ifeq ($(os),Linux)
CXXFLAGS      = -O -Wall
else
CXXFLAGS      = -O -fPIC -pipe -Wall
endif

CXXFLAGSGSL = $(CXXFLAGS)
CXXFLAGSGSL += -I$(GSL)/include
CXXFLAGSROOT = -I$(ROOTSYS)/include/root

ifeq ($(os),Linux)
LDFLAGS       = -O -g
LDFLAGSS      = -g --shared
else
LDFLAGS       = -O -Xlinker -bind_at_load -flat_namespace
LDFLAGSS      = -dynamiclib -flat_namespace -undefined suppress
LDFLAGSSS     = -bundle
endif

ROOTLIBS      = $(shell root-config --libs)

LIBSROOT       = $(ROOTLIBS)
LIBSGSL	       = $(LIBS)
LIBSGSL       += -L$(GSL)/lib -lgsl -lgslcblas


resonanceDecay :
	g++ $(CXXFLAGSGSL) $(CXXFLAGSROOT) -c src/resonanceDecay.C
	g++ $(LDFLAGS) resonanceDecay.o $(LIBSGSL) $(LIBSROOT) -L../Lib/ -lEvent -o bin/resonanceDecay
	rm resonanceDecay.o

clean :
	rm -f *.o *.root
	@echo "All cleaned-up :-)"

# DO NOT DELETE
