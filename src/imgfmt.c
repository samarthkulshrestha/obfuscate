#include <stdio.h>
#include <stdint.h>

#define NOB_IMPLEMENTATION
#include "../nob.h"

#define STB_C_LEXER_IMPLEMENTATION
#include "stb_c_lexer.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void usage(const char *program) {
  fprintf(stderr, "usage: %s <input.c> <input.png>\n", program);
}

int main(int argc, char **argv) {
  const char *program = nob_shift_args(&argc, &argv);

  if (argc <= 0) {
    usage(program);
    fprintf(stderr, "error: no input C file provided.\n");
    return 1;
  }

  const char *input_c_path = nob_shift_args(&argc, &argv);

  if (argc <= 0) {
    usage(program);
    fprintf(stderr, "error: no input image provided.\n");
    return 1;
  }

  const char *input_img_path = nob_shift_args(&argc, &argv);

  Nob_String_Builder sb = {0};
  if (!nob_read_entire_file(input_c_path, &sb)) return 1;

  stb_lexer l = {0};
  static char string_store[1024];
  stb_c_lexer_init(&l, sb.items, sb.items + sb.count, string_store, NOB_ARRAY_LEN(string_store));

  int img_width, img_height;
  uint32_t *pixels = (uint32_t*)stbi_load(input_img_path, &img_width, &img_height, NULL, 4);

  if (pixels == NULL) {
    fprintf(stderr, "error: could not load image %s\n", input_img_path);
    return 1;
  }

  for (int y = 0; y < img_height; ++y) {
    for (int x = 0; x < img_width;) {
      uint32_t pix = pixels[y * img_width + x];
      if (pix == 0xFF000000) {
        printf(" ");
        x += 1;
      } else {
        if (stb_c_lexer_get_token(&l)) {
          int n = l.where_lastchar - l.where_firstchar + 1;
          printf("%.*s", n, l.where_firstchar);
          x += n;
        } else {
          // ran out of tokens
          return 0;
        }
      }
    }
    printf("\n");
  }

  // rest of the unused tokens
  while (stb_c_lexer_get_token(&l)) {
    int n = l.where_lastchar - l.where_firstchar + 1;
    printf("%.*s ", n, l.where_firstchar);
  }

  return 0;
}
