obj = ../obj
inc = ../inc
src = ../src
cc = g++
CFLAGS = -std=c++11

object = ${obj}/common.o  ${obj}/masterNode.o master.o
target = master

${target}:${object}
	${cc} -g -o $@ ${object} 
${obj}/%.o:${src}/%.cc
	${cc} -g -c $< -o $@ -I ${inc}
master.o:master.cc
	${cc} -g -c master.cc -o master.o -I ${inc}
.PHONY:clean
clean:
	-rm $(target)
