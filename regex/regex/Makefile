TARGET=foo
#TARGET := $(addprefix bin/,$(TARGET))

#CXX = g++ -std=c++11
CXX = g++-5 -std=c++11
CFLAGS =-g -O0 -Wall -fpermissive -Wno-parentheses -Wno-sign-compare -Wno-unused-variable -Wpointer-sign -Wparentheses
LFLAGS =-L/usr/local/lib/ -lstdc++
#LFLAGS += -lpthread -lm -lcurses -lboost_system-mt -lboost_date_time-mt -lboost_regex-mt -lboost_thread-mt -lboost_chrono-mt

FILES+= $(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(FILES))

default all: $(TARGET)

clean:
	$(RM) $(TARGET) $(OBJS)
	find ./ -name *.o -exec rm -f {} \;

echo:
	@echo CFLAGS=$(CFLAGS)

.PHONY: default all clean depend

%o:%cpp
	$(CXX) -c $(CFLAGS) $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@ $(LFLAGS)
