######################

CXX           = g++
LD            = g++

#############################

os = $(shell uname -s)


ifeq ($(os),Linux)
CXXFLAGS      = -I$(ROOTSYS)/include/root
else
CXXFLAGS      = -O -fPIC -pipe -Wall -dynamiclib -I$(ROOTSYS)/include/root
endif

ifeq ($(os),Linux)
LDFLAGS       = -g
LDFLAGSS      = -g --shared
else
LDFLAGS       = -O -Xlinker -bind_at_load -flat_namespace
LDFLAGSS      = -dynamiclib -flat_namespace -undefined suppress
LDFLAGSSS     = -bundle
endif

ROOTLIBS      = $(shell root-config --libs)
LIBS          =  $(ROOTLIBS)

HDRS          = track.h event.h
SRCS          = track.C event.C dictEvent.C 

OBJS          = $(SRCS:.C=.o)

SLIB          = libEvent.so

$(SLIB):     $(OBJS)
	@echo "Linking $(PROGRAM) for "$(os)
	@echo $(LD) $(LDFLAGSS) $(OBJS) $(LIBS) -o $(SLIB)	
	@$(LD) $(LDFLAGSS) $(OBJS) $(LIBS) -o $(SLIB)
#@$(LD) $(LDFLAGS) $(OBJS) $(LIBS) -o $(PROGRAM)
	@echo "done"

##########################################################

track.o: track.h

dictEvent.C: $(HDRS)
	@echo "Generating dictionary ..."
	@$(ROOTSYS)/bin/rootcint -f dictEvent.C -c $(HDRS)

.C.o:
	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f *.o dict*.* $(SLIB)
	@echo "All cleaned-up :-)"
