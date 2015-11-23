#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "coder.h" 
 
 
int main (int argc, char **argv) {
 
  if ((argv[1] != NULL) && (argv[2] != NULL) && (argv[3]) != NULL) {
    if (strcmp(argv[1], "encode") == 0) {
	f_encode(argv[2], argv[3]);
    } else {
	if (strcmp(argv[1], "decode") == 0) {
	    f_decode(argv[2], argv[3]);
	} else {
	f_usage(argv[0]);
	return 1; 
	}
    }
  } else {
    f_usage(argv[0]);
  } 
 
  return 0;
}