#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	FILE *fp;	
} png_t;

png_t *png_open(const char *path);
void png_close(png_t *self);

png_t *png_open(const char *path)
{
	png_t *png = (png_t*)malloc(sizeof(png_t));
	png->fp = fopen(path, "wb");

	return png;
}

void png_close(png_t *self)
{
	fclose(self->fp);
	free(self);
}

int main(int argc, char **argv)
{
	png_t *png = png_open("shig.png");

	png_close(png);
	
	return 0;
}
