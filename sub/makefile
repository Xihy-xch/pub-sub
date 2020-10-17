obj = ../obj
inc = ../inc
src = ../src
cc = g++
CFLAGS = -std=c++11

object = ${obj}/common.o  ${obj}/subNode.o sub.o
target = sub

${target}:${object}
	${cc} -g -o $@ ${object} 
${obj}/%.o:${src}/%.cc
	${cc} -g -c $< -o $@ -I ${inc}
sub.o:sub.cc
	${cc} -g -c sub.cc -o sub.o -I ${inc}
.PHONY:clean
clean:
	-rm $(target)
