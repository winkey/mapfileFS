/*

  gcc -Wall mapfileFS.c `pkg-config fuse --cflags --libs` -o mapfileFS
*/

#define FUSE_USE_VERSION 26

#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

static const char *mapfileFS_str = "mapfileFS World!\n";


/*******************************************************************************
 This function returns metadata concerning a file specified by path in a special
 stat structure. It has to be declared static, as all functions passed in the
 fuse_operations structure to fuse_main(), to work properly. 
*******************************************************************************/

static int mapfileFS_getattr(const char *path, struct stat *stbuf)
{
	int res = 0;

	memset(stbuf, 0, sizeof(struct stat));

    /***** is it a dir? *****/

	if (strcmp(path, "/") == 0) {
		stbuf->st_mode = S_IFDIR | 0755;
		stbuf->st_nlink = 2;

    /***** is it a file *****/

	} else if (strcmp(path, mapfileFS_path) == 0) {
		stbuf->st_mode = S_IFREG | 0444;
		stbuf->st_nlink = 1;
		stbuf->st_size = strlen(mapfileFS_str); //fixme
	} else
		res = -ENOENT;

	return res;
}

/*******************************************************************************
 Next very important function is used to read directory contents. Because our
 implementation is very simple, we will be intrested only in path, buf and
 filler arguments passed to it. Path is the path to the directory from which we
 will have to read our contents, buf will hold them, and filler is a
 fuse_fill_dir_t function which we will use to add contents to directory.
 Offset and fi are not important now. 
*******************************************************************************/

static int mapfileFS_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
			 off_t offset, struct fuse_file_info *fi)
{
	(void) offset;
	(void) fi;

	if (strcmp(path, "/") != 0)
		return -ENOENT;

	filler(buf, ".", NULL, 0);
	filler(buf, "..", NULL, 0);
	//filler(buf, mapfileFS_path + 1, NULL, 0);

	return 0;
}

static int mapfileFS_open(const char *path, struct fuse_file_info *fi)
{
	if (strcmp(path, mapfileFS_path) != 0)
		return -ENOENT;

	if ((fi->flags & 3) != O_RDONLY)
		return -EACCES;

	return 0;
}


static int mapfileFS_read(const char *path, char *buf, size_t size, off_t offset,
		      struct fuse_file_info *fi)
{
	size_t len;
	(void) fi;
	if(strcmp(path, mapfileFS_path) != 0)
		return -ENOENT;

	len = strlen(mapfileFS_str);
	if (offset < len) {
		if (offset + size > len)
			size = len - offset;
		memcpy(buf, mapfileFS_str + offset, size);
	} else
		size = 0;

	return size;
}

static struct fuse_operations mapfileFS_oper = {
	.getattr	= mapfileFS_getattr,
	.readdir	= mapfileFS_readdir,
	.open		= mapfileFS_open,
	.read		= mapfileFS_read,
};

int main(int argc, char *argv[])
{
	return fuse_main(argc, argv, &mapfileFS_oper, NULL);
}
