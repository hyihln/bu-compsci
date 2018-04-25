/* Prog.c */
#include <stdio.h>
void bad()
{
  /* Your implementation goes here */
	char* new_name = "Quick brown fox jumped over the lazy dog";
	unsigned char* temp;
	temp = (unsigned char*) (&new_name);

	int Offset_name = 0x38;
	int Offset_age = 0x40;
	int ret_offset = 0x1B;
	int addr_ret_orig = 0x00007fffffffe6c0 /*+ 8*/;
	int stack_offset_ret_addr = 0x48 /*0x50*/;

	*((char **) (temp + Offset_name)) = new_name;
	*((char **) (temp + Offset_age)) = 1000;

	temp = (unsigned char*) (&new_name);
	*((unsigned long *) (temp+stack_offset_ret_addr)) += ret_offset;
}

int main(){
  struct {
    char *name;
    int age;
  } student = {.name = "John", .age = 22};
  bad();
  printf("student.name = %s\nstudent.age = %d\n", student.name, student.age);
  return 0;
}
