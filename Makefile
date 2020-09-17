dict1: dict1.o makeNode.o readfile.o bst.o print.o readsearchkey.o
	gcc -Wall -o dict1 dict1.o makeNode.o readfile.o bst.o print.o readsearchkey.o -g
	
dict2: dict2.o makeNode.o readfile.o bst.o print.o readsearchid.o
	gcc -Wall -o dict2 dict2.o makeNode.o readfile.o bst.o print.o readsearchid.o -g


dict2.o: dict2.c dict2.h
	gcc -Wall dict2.c -c -g -o dict2.o

dict1.o: dict1.c dict1.h
	gcc -Wall dict1.c -c -g -o dict1.o

readsearchid.o: readsearchid.c readsearchid.h
	gcc -Wall readsearchid.c -c -g -o readsearchid.o

readsearchkey.o: readsearchkey.c readsearchkey.h
	gcc -Wall readsearchkey.c -c -g -o readsearchkey.o

bst.o: bst.c bst.h
	gcc -Wall bst.c -c -g -o bst.o

makeNode.o: makeNode.c makeNode.h
	gcc -Wall makeNode.c -c -g -o makeNode.o
	
readfile.o: readfile.c readfile.h
	gcc -Wall readfile.c -c -g -o readfile.o
    
print.o: print.c print.h
	gcc -Wall print.c -c -g -o print.o