#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdio.h> 
 
using namespace std;


int f_encode (char *file_name) {
 cout << "Function for encoding file" << endl; 
 char temp_array[100];
 int i = 0;
 
  FILE * file_object;
    file_object = fopen (file_name, "r");
      if (file_object != NULL) {
        while (! feof(file_object)) {
          fgets (temp_array, 100, file_object);
          cout << temp_array << endl;
        }
      }
      fclose (file_object);
      
    for (i = 0; i < 100; i++) {
         temp_array[i] = temp_array[i] + 4;   
        }
        
        cout << temp_array << endl; 

    FILE * result_object;
        result_object = fopen ("/home/jen/codding/Coder/result.txt", "a");
            if (result_object != NULL) 
            fputs (temp_array, result_object);
            fclose (result_object);
        return 0;
}

int f_decode (char *file_name) {
 cout << "Function for decoding file" << endl;
 FILE * file_object;
     file_object = fopen (file_name, "r");
     
      if (file_object != NULL) 
	cout << "it`s success!!1111!!11azaza" << endl; 
    
      if (file_object == NULL) {
	cout << "what the shit?" << endl; 
	return 1;
      }
      
     fclose (file_object);
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