#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int len;
  int *data;
} list_int;
static list_int list_int_create(int len) {
  list_int l;
  l.len = len;
  l.data = calloc(len, sizeof(int));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}
typedef struct {
  int len;
  double *data;
} list_float;
static list_float list_float_create(int len) {
  list_float l;
  l.len = len;
  l.data = calloc(len, sizeof(double));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}
typedef struct {
  int len;
  char **data;
} list_string;
static list_string list_string_create(int len) {
  list_string l;
  l.len = len;
  l.data = calloc(len, sizeof(char *));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}
typedef struct {
  int len;
  list_int *data;
} list_list_int;
static list_list_int list_list_int_create(int len) {
  list_list_int l;
  l.len = len;
  l.data = calloc(len, sizeof(list_int));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}
static char *_min_string(list_string v) {
  if (v.len == 0)
    return "";
  char *m = v.data[0];
  for (int i = 1; i < v.len; i++)
    if (strcmp(v.data[i], m) < 0)
      m = v.data[i];
  return m;
}
static int contains_string(char *s, char *sub) {
  return strstr(s, sub) != NULL;
}
static void _json_int(int v) { printf("%d", v); }
static void _json_float(double v) { printf("%g", v); }
static void _json_string(char *s) { printf("\"%s\"", s); }
static void _json_list_int(list_int v) {
  printf("[");
  for (int i = 0; i < v.len; i++) {
    if (i > 0)
      printf(",");
    _json_int(v.data[i]);
  }
  printf("]");
}
static void _json_list_float(list_float v) {
  printf("[");
  for (int i = 0; i < v.len; i++) {
    if (i > 0)
      printf(",");
    _json_float(v.data[i]);
  }
  printf("]");
}
static void _json_list_string(list_string v) {
  printf("[");
  for (int i = 0; i < v.len; i++) {
    if (i > 0)
      printf(",");
    _json_string(v.data[i]);
  }
  printf("]");
}
static void _json_list_list_int(list_list_int v) {
  printf("[");
  for (int i = 0; i < v.len; i++) {
    if (i > 0)
      printf(",");
    _json_list_int(v.data[i]);
  }
  printf("]");
}
typedef struct {
  const char *rating;
  const char *movie_title;
} tmp1_t;
typedef struct {
  int len;
  tmp1_t *data;
} tmp1_list_t;
tmp1_list_t create_tmp1_list(int len) {
  tmp1_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(tmp1_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  int id;
  const char *info;
} info_type_t;
typedef struct {
  int len;
  info_type_t *data;
} info_type_list_t;
info_type_list_t create_info_type_list(int len) {
  info_type_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(info_type_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  int id;
  const char *keyword;
} keyword_t;
typedef struct {
  int len;
  keyword_t *data;
} keyword_list_t;
keyword_list_t create_keyword_list(int len) {
  keyword_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(keyword_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  int id;
  const char *title;
  int production_year;
} title_t;
typedef struct {
  int len;
  title_t *data;
} title_list_t;
title_list_t create_title_list(int len) {
  title_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(title_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  int movie_id;
  int keyword_id;
} movie_keyword_t;
typedef struct {
  int len;
  movie_keyword_t *data;
} movie_keyword_list_t;
movie_keyword_list_t create_movie_keyword_list(int len) {
  movie_keyword_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(movie_keyword_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  int movie_id;
  int info_type_id;
  const char *info;
} movie_info_idx_t;
typedef struct {
  int len;
  movie_info_idx_t *data;
} movie_info_idx_list_t;
movie_info_idx_list_t create_movie_info_idx_list(int len) {
  movie_info_idx_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(movie_info_idx_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  const char *rating;
  const char *title;
} rows_item_t;
typedef struct {
  int len;
  rows_item_t *data;
} rows_item_list_t;
rows_item_list_t create_rows_item_list(int len) {
  rows_item_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(rows_item_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  const char *rating;
  const char *movie_title;
} result_t;
typedef struct {
  int len;
  result_t *data;
} result_list_t;
result_list_t create_result_list(int len) {
  result_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(result_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

static list_int test_Q4_returns_minimum_rating_and_title_for_sequels_result;
static void test_Q4_returns_minimum_rating_and_title_for_sequels() {
  tmp1_t tmp1[] = {(tmp1_t){.rating = "6.2", .movie_title = "Alpha Movie"}};
  int tmp1_len = sizeof(tmp1) / sizeof(tmp1[0]);
  int tmp2 = 1;
  if (test_Q4_returns_minimum_rating_and_title_for_sequels_result.len !=
      tmp1.len) {
    tmp2 = 0;
  } else {
    for (int i3 = 0;
         i3 < test_Q4_returns_minimum_rating_and_title_for_sequels_result.len;
         i3++) {
      if (test_Q4_returns_minimum_rating_and_title_for_sequels_result
              .data[i3] != tmp1.data[i3]) {
        tmp2 = 0;
        break;
      }
    }
  }
  if (!(tmp2)) {
    fprintf(stderr, "expect failed\n");
    exit(1);
  }
}

int main() {
  info_type_t info_type[] = {(info_type_t){.id = 1, .info = "rating"},
                             (info_type_t){.id = 2, .info = "other"}};
  int info_type_len = sizeof(info_type) / sizeof(info_type[0]);
  keyword_t keyword[] = {(keyword_t){.id = 1, .keyword = "great sequel"},
                         (keyword_t){.id = 2, .keyword = "prequel"}};
  int keyword_len = sizeof(keyword) / sizeof(keyword[0]);
  title_t title[] = {
      (title_t){.id = 10, .title = "Alpha Movie", .production_year = 2006},
      (title_t){.id = 20, .title = "Beta Film", .production_year = 2007},
      (title_t){.id = 30, .title = "Old Film", .production_year = 2004}};
  int title_len = sizeof(title) / sizeof(title[0]);
  movie_keyword_t movie_keyword[] = {
      (movie_keyword_t){.movie_id = 10, .keyword_id = 1},
      (movie_keyword_t){.movie_id = 20, .keyword_id = 1},
      (movie_keyword_t){.movie_id = 30, .keyword_id = 1}};
  int movie_keyword_len = sizeof(movie_keyword) / sizeof(movie_keyword[0]);
  movie_info_idx_t movie_info_idx[] = {
      (movie_info_idx_t){.movie_id = 10, .info_type_id = 1, .info = "6.2"},
      (movie_info_idx_t){.movie_id = 20, .info_type_id = 1, .info = "7.8"},
      (movie_info_idx_t){.movie_id = 30, .info_type_id = 1, .info = "4.5"}};
  int movie_info_idx_len = sizeof(movie_info_idx) / sizeof(movie_info_idx[0]);
  rows_item_list_t tmp4 =
      rows_item_list_t_create(info_type.len * movie_info_idx.len * title.len *
                              movie_keyword.len * keyword.len);
  int tmp5 = 0;
  for (int tmp6 = 0; tmp6 < info_type_len; tmp6++) {
    info_type_t it = info_type[tmp6];
    for (int tmp7 = 0; tmp7 < movie_info_idx_len; tmp7++) {
      movie_info_idx_t mi = movie_info_idx[tmp7];
      if (!(it.id == mi.info_type_id)) {
        continue;
      }
      for (int tmp8 = 0; tmp8 < title_len; tmp8++) {
        title_t t = title[tmp8];
        if (!(t.id == mi.movie_id)) {
          continue;
        }
        for (int tmp9 = 0; tmp9 < movie_keyword_len; tmp9++) {
          movie_keyword_t mk = movie_keyword[tmp9];
          if (!(mk.movie_id == t.id)) {
            continue;
          }
          for (int tmp10 = 0; tmp10 < keyword_len; tmp10++) {
            keyword_t k = keyword[tmp10];
            if (!(k.id == mk.keyword_id)) {
              continue;
            }
            if (!((strcmp(it.info, "rating") == 0) &&
                  contains_string(k.keyword, "sequel") && mi.info > "5.0" &&
                  t.production_year > 2005 && mk.movie_id == mi.movie_id)) {
              continue;
            }
            tmp4.data[tmp5] =
                (rows_item_t){.rating = mi.info, .title = t.title};
            tmp5++;
          }
        }
      }
    }
  }
  tmp4.len = tmp5;
  rows_item_list_t rows = tmp4;
  int tmp11 = int_create(rows.len);
  int tmp12 = 0;
  for (int tmp13 = 0; tmp13 < rows.len; tmp13++) {
    rows_item_t r = rows.data[tmp13];
    tmp11.data[tmp12] = r.rating;
    tmp12++;
  }
  tmp11.len = tmp12;
  int tmp14 = int_create(rows.len);
  int tmp15 = 0;
  for (int tmp16 = 0; tmp16 < rows.len; tmp16++) {
    rows_item_t r = rows.data[tmp16];
    tmp14.data[tmp15] = r.title;
    tmp15++;
  }
  tmp14.len = tmp15;
  result_t result[] = {(result_t){.rating = _min_string(tmp11),
                                  .movie_title = _min_string(tmp14)}};
  int result_len = sizeof(result) / sizeof(result[0]);
  printf("[");
  for (int i17 = 0; i17 < result_len; i17++) {
    if (i17 > 0)
      printf(",");
    result_t it = result[i17];
    printf("{");
    _json_string("rating");
    printf(":");
    _json_string(it.rating);
    printf(",");
    _json_string("movie_title");
    printf(":");
    _json_string(it.movie_title);
    printf("}");
  }
  printf("]");
  test_Q4_returns_minimum_rating_and_title_for_sequels_result = result;
  test_Q4_returns_minimum_rating_and_title_for_sequels();
  free(tmp11.data);
  free(tmp14.data);
  return 0;
}
