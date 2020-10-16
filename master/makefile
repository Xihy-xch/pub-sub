obj = ../obj
inc = ../inc
cc = clang++
CFLAGS = -std=c++11

object = ${obj}/common.o ${obj}/master.o ${obj}/subnode.o masternode.o
target = masternode

${target}:${object}
	${cc} -g -o $@ ${object} -lpthread
masternode.o:masternode.cc
	${cc} -g -c masternode.cc -o masternode.o -I ${inc}
.PHONY:clean
clean:
	-rm $(target)
