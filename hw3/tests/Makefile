CXXFLAGS = -g -pedantic -Wall -Wextra -Werror -I../ -std=c++17 -fsanitize=address

SRCS_HPP = ../Format.hpp ../Functional.hpp ../TypeInfo.hpp
TESTS_CPP = fmt-invalid.cpp fmt-invalid2.cpp fmt-invalid3.cpp fmt-multipleargs.cpp fmt-noargs.cpp fmt-percent \
			fmt-singlearg.cpp fn-fold.cpp fn-unzip.cpp fn-zip.cpp ti-arrays.cpp ti-const.cpp ti-lval_ref.cpp \
			ti-nested.cpp ti-pointers.cpp ti-primitives.cpp ti-rval_ref.cpp ti-volatile.cpp
TESTS = $(TESTS_CPP:.cpp=)
OUTPUT = $(TESTS:=-output.txt)

.PHONY: all
all: $(TESTS)

$(TESTS): %: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(TESTS): $(SRCS_HPP)

.PHONY: output
output: $(OUTPUT)

$(OUTPUT): %-output.txt: %
	./$< > $@

.PHONY: clean
clean:
	rm -f $(TESTS) $(OUTPUT)
	
