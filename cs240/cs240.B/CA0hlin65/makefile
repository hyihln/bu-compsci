#
# Specifiy the target
all:	Lin_Huiyi_hlin65_Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Lin_Huiyi_hlin65_Hello:	Lin_Huiyi_hlin65_Hello.o Hello_Class.o
	g++  Lin_Huiyi_hlin65_Hello.o  Hello_Class.o -o Lin_Huiyi_hlin65_Hello.exe


# Specify how the object files should be created from source files
Lin_Huiyi_hlin65_Hello.o:	Lin_Huiyi_hlin65_Hello.cpp
	g++ -c Lin_Huiyi_hlin65_Hello.cpp

Hello_Class.o:	Hello_Class.cpp 
	g++ -c Hello_Class.cpp
# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Lin_Huiyi_hlin65_Hello.exe

