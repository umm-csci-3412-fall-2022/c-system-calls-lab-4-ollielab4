#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

static int num_dirs, num_regular;
void process_path(const char*);

bool is_dir(const char* path) {
	if (path != NULL){
		struct stat *buf = malloc(sizeof(*buf));
		stat(path,buf);
		bool a = S_ISDIR((*buf).st_mode);
		num_dirs++;
		free(buf);
		return a;
	}else{
		return false;
	}
}

void process_directory(const char* path) {
	DIR *dir;
	struct dirent *dp;
	if ((dir = opendir (path)) == NULL) {
		perror ("Cannot open .");
		exit (1);
	}
	chdir(path);
	while ((dp = readdir (dir)) != NULL) { 
		if((dp*).d_name != "." && (dp*).d_name != ".."){
			process_path((dp*).d_name);
		}
	}
	chdir("..");
	closedir(path);



   /*
   * Update the number of directories seen, use opendir() to open the
   * directory, and then use readdir() to loop through the entries
   * and process them. You have to be careful not to process the
   * "." and ".." directory entries, or you'll end up spinning in
   * (infinite) loops. Also make sure you closedir() when you're done.
   *
   * You'll also want to use chdir() to move into this new directory,
   * with a matching call to chdir() to move back out of it when you're
   * done.
   */
}

void process_file(const char* path) {
  /*
   * Update the number of regular files.
   * This is as simple as it seems. :-)
   */
}

void process_path(const char* path) {
  if (is_dir(path)) {
    process_directory(path);
  } else {
    process_file(path);
  }
}

int main (int argc, char *argv[]) {
  // Ensure an argument was provided.
  if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]);
    printf ("       where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }

  num_dirs = 0;
  num_regular = 0;

  process_path(argv[1]);

  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}
