#Makefile
CXX=g++
CXXFLAGS    = -std=gnu++11 -Wall -O2
LDFLAGS     = -lSDL
#LIBS        = None
INSTALLPATH = /home/hiroto/bin/
INCLUDE     = -I include
TARGET      = sdl_game
OBJDIR      = ./obj
ifeq "$(strip $(OBJDIR))" ""
	OBJDIR = .
endif
SOURCES     = $(wildcard *.cpp)
OBJECTS     = $(addprefix $(OBJDIR)/,$(SOURCES:.cpp=.o))
DEPENDS     = $(OBJECTS:.o=.d)


$(TARGET):$(OBJECTS) $(LIBS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: %.cpp
	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
		$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

.PHONY: clean
clean:
	$(RM) -f $(OBJECTS) $(DEPENDS) $(TARGET)
	@rmdir --ignore-fail-on-non-empty `readlink -f $(OBJDIR)`
	$(RM) -f $(INSTALLPATH)$(TARGET)

install: 
	     cp $(TARGET) $(INSTALLPATH)$(TARGET)

-include $(DEPENDS)	
