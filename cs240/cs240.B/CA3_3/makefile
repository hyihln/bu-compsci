
#CTRL + H : Replace all

all:	FBL

FBL:	CA3_1.o FBLPost.o FBLPostLL.o FBLUser.o FBLUserLL.o FBLComment.o FBLCommentLL.o
	g++  CA3_1.o FBLPost.o FBLPostLL.o FBLUser.o FBLUserLL.o FBLComment.o FBLCommentLL.o -o FBL

CA3_1.o:	CA3_1.cpp
	g++ -c CA3_1.cpp

FBLPost.o:	FBLPost.cpp 
	g++ -c FBLPost.cpp

FBLPostLL.o:	FBLPostLL.cpp 
	g++ -c FBLPostLL.cpp

FBLUser.o:	FBLUser.cpp 
	g++ -c FBLUser.cpp

FBLUserLL.o:	FBLUserLL.cpp
	g++ -c FBLUserLL.cpp

FBLComment.o:	FBLComment.cpp 
	g++ -c FBLComment.cpp

FBLCommentLL.o:	FBLCommentLL.cpp
	g++ -c FBLCommentLL.cpp

clean:
	rm -f *.o FBL
