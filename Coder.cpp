#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdio.h> 
#include <stdlib.h>
 
using namespace std;

void f_usage () {
    printf ("Usage: \n");
    printf ("   program_name [mode] [file1] [file2] \n");
    printf ("   mode - 'encode' or 'decode' \n");
    printf ("   file1 - file name we want to operate \n");
    printf ("   file2 - file name we will store the result to \n"); 
}


int f_encode (char *file_for_encoding, char *coded_file) {
 cout << "Function for encoding file" << endl; 
 char *temp_array = NULL;     
 char *fname_array = NULL; 
 int i = 0;
 // int offset = 0;
 int file_size = 0;
 
  FILE * fdEncode;
    fdEncode = fopen (file_for_encoding, "r");
      if (fdEncode != NULL) {
          
          fseek (fdEncode, 0, SEEK_END);
          file_size = ftell(fdEncode);
          fseek (fdEncode, 0, SEEK_SET);
          
          // cout << file_size << endl;
          
          temp_array = (char*) malloc(file_size);
          if (temp_array == NULL)
            return 1;
          
          fread (temp_array, 1, file_size, fdEncode);    
                 
        /*  while (!feof(fdEncode)) {
                fgets (temp_array + offset, file_size, fdEncode);
                offset = strlen (temp_array); *
          } */
          // cout << temp_array << endl;
      }
      fclose (fdEncode);
      
    for (i = 0; i <= file_size; i++) {
         temp_array[i] = temp_array[i] + 4;   
        }
    
    /* int fname_size = strlen (file_for_encoding) + strlen(".coded.txt");
        
    fname_array = (char*) malloc (fname_size);
    if (fname_array == NULL)
        return 1;
    strcpy (fname_array, file_for_encoding);
    strcat (fname_array, ".coded.txt");
    free (fname_array); */

    FILE * fdResult;
        fdResult = fopen (coded_file, "w");
            if (fdResult != NULL) {
                fwrite (temp_array, 1, file_size, fdResult);
                fclose (fdResult);
            }
        free (temp_array);
        return 0;
                
}


int f_decode (char *file_for_decoding, char *decoded_file) {
 cout << "Function for decoding file" << endl;
 char *temp_array = NULL;     
 int i = 0;
 int file_size = 0;
 
  FILE * fdDecode;
    fdDecode = fopen (file_for_decoding, "r");
      if (fdDecode != NULL) {
          
          fseek (fdDecode, 0, SEEK_END);
          file_size = ftell(fdDecode);
          fseek (fdDecode, 0, SEEK_SET);
          
          // cout << file_size << endl;
          
          temp_array = (char*) malloc(file_size);
          if (temp_array == NULL)
            return 1;
          
          fread (temp_array, 1, file_size, fdDecode);   
                 
         /* while (!feof(fdDecode)) {
                fgets (temp_array, file_size, fdDecode);
          } */
      }
      fclose (fdDecode);
      
    for (i = 0; i <= file_size; i++) {
         temp_array[i] = temp_array[i] - 4;   
        }

    FILE * fdResult;
        fdResult = fopen (decoded_file, "w");
            if (fdResult != NULL) {
                fwrite (temp_array, 1, file_size, fdResult);
                fclose (fdResult);
            }
    free (temp_array);
        return 0;
    
}

 
int main (int argc, char **argv) {
 
  if ((argv[1] != NULL) && (argv[2] != NULL) && (argv[3]) != NULL) {
    if (strcmp(argv[1], "encode") == 0) {
	f_encode(argv[2], argv[3]);
    } else {
	if (strcmp(argv[1], "decode") == 0) {
	    f_decode(argv[2], argv[3]);
	} else {
	f_usage();
	return 1; 
	}
    }
  } else {
    f_usage();
  } 
 
  return 0;
}