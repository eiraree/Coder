#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


int f_usage (char* program_name) {
    printf ("Usage: \n"
        "   %s [mode] [file1] [file2] \n"
        "   mode - 'encode' or 'decode' \n"
        "   file1 - file name we want to operate \n"
        "   file2 - file name we will store the result to \n", program_name);
    return 0;
}


int f_encode (char *file_for_encoding, char *coded_file) {
 char *temp_array = NULL;     
 int i = 0;
 int file_size = 0;
 int number;
 
  FILE * fdEncode;
    fdEncode = fopen (file_for_encoding, "r");
    
    if (fdEncode == NULL) {
            printf ("[Error]: File not found! \n");
            return 1;
      }
    
      if (fdEncode != NULL) {
          
          fseek (fdEncode, 0, SEEK_END);
          file_size = ftell(fdEncode);
          fseek (fdEncode, 0, SEEK_SET);
          
          temp_array = (char*) malloc(file_size);
          
          if (temp_array == NULL)
            return 1;
          
          fread (temp_array, 1, file_size, fdEncode);    
      }
      
      
    fclose (fdEncode);
    
    printf ("Enter value, please: \n");
    scanf ("%i", &number);
      
    for (i = 0; i <= file_size; i++) {
         temp_array[i] = temp_array[i] + number;   
        }

    FILE * fdResult;
        fdResult = fopen (coded_file, "w");
        
        if (fdResult != NULL) {
            fwrite (temp_array, 1, file_size, fdResult);
        } 

        if (fdResult == NULL) 
            return 1;
            
        fclose (fdResult);
        free (temp_array);
        return 0;
                
}


int f_decode (char *file_for_decoding, char *decoded_file) {
 char *temp_array = NULL;     
 int i = 0;
 int file_size = 0;
 int number;
 
  FILE * fdDecode;
    fdDecode = fopen (file_for_decoding, "r");
    
    if (fdDecode == NULL) {
            printf ("[Error]: File not found! \n");
            return 1;
      }
      
      if (fdDecode != NULL) {
          
          fseek (fdDecode, 0, SEEK_END);
          file_size = ftell(fdDecode);
          fseek (fdDecode, 0, SEEK_SET);
        
          temp_array = (char*) malloc(file_size);
          if (temp_array == NULL)
            return 1;
          
          fread (temp_array, 1, file_size, fdDecode);   
      }
      fclose (fdDecode);
      
      printf ("Enter value, please: \n");
      scanf ("%i", &number);
      
    for (i = 0; i <= file_size; i++) {
         temp_array[i] = temp_array[i] - number;   
        }

    FILE * fdResult;
        fdResult = fopen (decoded_file, "w");
            if (fdResult != NULL) {
                fwrite (temp_array, 1, file_size, fdResult);
                fclose (fdResult);
            }
            
            if (fdResult == NULL) 
                return 1;
        
    free (temp_array);
        return 0;
    
}