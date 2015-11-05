#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdio.h> 
 
using namespace std;


int f_encode (char *file_for_encoding) {
 cout << "Function for encoding file" << endl; 
 char temp_array[100];     //лажа
 int i = 0;
 
  FILE * file_object;
    file_object = fopen (file_for_encoding, "r");
      if (file_object != NULL) {
        while (! feof(file_object)) {
          fgets (temp_array, 100, file_object);  //лажа
          cout << temp_array << endl;
        }
      }
      fclose (file_object);
      
    for (i = 0; i < 100; i++) {
         temp_array[i] = temp_array[i] + 4;   // лажа
        }

    FILE * result_object;
        result_object = fopen ("/home/jen/codding/Coder/result.txt", "a");
            if (result_object != NULL) 
            fputs (temp_array, result_object);
            fclose (result_object);
        return 0;
        
        //лажа
}

int f_decode (char *file_for_decoding) {
 cout << "Function for decoding file" << endl;
 char temp_array[100];
 int i = 0;
 
  FILE * file_object;
    file_object = fopen (file_for_decoding, "r");
      if (file_object != NULL) {
        while (! feof(file_object)) {
          fgets (temp_array, 100, file_object);
          cout << temp_array << endl;
        }
      }
      fclose (file_object);
      
    for (i = 0; i < 100; i++) {
         temp_array[i] = temp_array[i] - 4;   
        }

    FILE * result_object;
        result_object = fopen ("/home/jen/codding/Coder/enc_result.txt", "a");
            if (result_object != NULL) 
            fputs (temp_array, result_object);
            fclose (result_object);
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