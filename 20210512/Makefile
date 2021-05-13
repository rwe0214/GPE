SRCDIR = solutions
BINDIR = bin
OUTDIR = output
TESTDIR = testdata
TESTOUT = testoutput
CC = g++
CFLAGS = -std=c++11 

SRCS = $(wildcard $(SRCDIR)/*.cpp)
EXECS = $(patsubst $(SRCDIR)%.cpp, %, $(SRCS))
ALL_TEST = $(patsubst $(SRCDIR)/%.cpp, %.test, $(SRCS))

all: $(BINDIR) $(OUTDIR) $(EXECS)
.PHONY: all

$(BINDIR):
	@mkdir $(BINDIR)

$(OUTDIR):
	@mkdir $(OUTDIR)

$(EXECS): %: $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) -o $(BINDIR)$@ $<

clean:
	@rm -rf $(BINDIR)
	@rm -rf $(OUTDIR)

%.test:
	@echo "Checking $@"
	@./$(BINDIR)/$* < $(TESTDIR)/$*.testdata > $(OUTDIR)/$*.output
	@diff -q $(TESTOUT)/$*.output $(OUTDIR)/$*.output || \
	(echo "$@ failed" && exit 1)

test: $(ALL_TEST)
	@echo "Success, all tests passed."

format:
	clang-format -i $(SRCS)
