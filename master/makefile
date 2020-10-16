obj = ../obj
inc = ../inc
src = ../src
cc = clang++
CFLAGS = -std=c++11

object = ${obj}/common.o ${obj}/master.o masternode.o
target = masternode

${target}:${object}
	${cc} -g -o $@ ${object}
${obj}/%.o:${src}/%.cc
	${cc} -g -c $< -o $@ -I ${inc}
masternode.o:masternode.cc
	${cc} -g -c masternode.cc -o masternode.o -I ${inc}
.PHONY:clean
clean:
	-rm $(target)
