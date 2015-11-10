#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdio.h> 
#include <stdlib.h>
 
using namespace std;


int f_encode (char *file_for_encoding) {
 cout << "Function for encoding file" << endl; 
 char *temp_array = NULL;     
 int i = 0;
 int offset = 0;
 
  FILE * fdEncode;
    fdEncode = fopen (file_for_encoding, "r");
      if (fdEncode != NULL) {
          
          fseek (fdEncode, 0, SEEK_END);
          int file_size = ftell(fdEncode);
          fseek (fdEncode, 0, SEEK_SET);
          
          cout << file_size << endl;
          
          temp_array = (char*) malloc(file_size);
          if (temp_array == NULL)
            return 1;
          
                 
          while (!feof(fdEncode)) {
                fgets (temp_array + offset, file_size, fdEncode);
                offset = strlen (temp_array) + 1;
          }
          cout << temp_array << endl;
      }
      fclose (fdEncode);
      
    for (i = 0; i < 100; i++) {
         temp_array[i] = temp_array[i] + 4;   
        }

    FILE * fdResult;
        fdResult = fopen ("/home/jen/codding/Coder/result.txt", "a");
            if (fdResult != NULL) 
            fputs (temp_array, fdResult);
            fclose (fdResult);
        return 0;
        
        
}

int f_decode (char *file_for_decoding) {
 cout << "Function for decoding file" << endl;
 char temp_array[100];
 int i = 0;
 
  FILE * fdDecode;
    fdDecode = fopen (file_for_decoding, "r");
      if (fdDecode != NULL) {
        while (! feof(fdDecode)) {
          fgets (temp_array, 100, fdDecode);
          cout << temp_array << endl;
        }
      }
      fclose (fdDecode);
      
    for (i = 0; i < 100; i++) {
         temp_array[i] = temp_array[i] - 4;   
        }

    FILE * fdResult;
        fdResult = fopen ("/home/jen/codding/Coder/enc_result.txt", "a");
            if (fdResult != NULL) 
            fputs (temp_array, fdResult);
            fclose (fdResult);
        return 0;
}

 
int main (int argc, char **argv) {
 
  if ((argv[1] != NULL) && (argv[2] != NULL)) {
    if (strcmp(argv[1], "encode") == 0) {
	f_encode(argv[2]);
    } else {
	if (strcmp(argv[1], "decode") == 0) {
	    f_decode(argv[2]);
	} else {
	cout << "You shall not pass! What the " << argv[1] << "????" << endl;
	return 1; 
	}
    }
  } else {
    cout << "What do you mean by saying it..?" << endl;
  } 
 
  return 0;
}