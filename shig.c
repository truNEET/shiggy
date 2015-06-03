#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	FILE *fp;	
} png_t;

png_t *png_open(const char *path);
void png_write(png_t *self, void *buffer, size_t size);
void png_close(png_t *self);

png_t *png_open(const char *path)
{
	png_t *png = (png_t*)malloc(sizeof(png_t));
	png->fp = fopen(path, "wb");

	char buffer[] = {
		0x89, 0x50, 0x4e, 0x47,
		0x0d, 0x0a, 0x1a, 0x0a
	};

	png_write(png, &buffer, sizeof(buffer));

	return png;
}

void png_write(png_t *self, void *buffer, size_t size)
{
	fwrite(buffer, sizeof(char), size, self->fp);
}

void png_close(png_t *self)
{
	char buffer[] = {
		'I', 'E', 'N', 'D'
	};

	png_write(self, &buffer, sizeof(buffer));
	
	fclose(self->fp);
	free(self);
}

int main(int argc, char **argv)
{
	png_t *png = png_open("shig.png");

	png_close(png);
	
	return 0;
}
