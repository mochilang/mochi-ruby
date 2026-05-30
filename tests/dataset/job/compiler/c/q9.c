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
static int contains_list_string(list_string v, char *item) {
  for (int i = 0; i < v.len; i++)
    if (strcmp(v.data[i], item) == 0)
      return 1;
  return 0;
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
  const char *alternative_name;
  const char *character_name;
  const char *movie;
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
  int person_id;
  const char *name;
} aka_name_t;
typedef struct {
  int len;
  aka_name_t *data;
} aka_name_list_t;
aka_name_list_t create_aka_name_list(int len) {
  aka_name_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(aka_name_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  int id;
  const char *name;
} char_name_t;
typedef struct {
  int len;
  char_name_t *data;
} char_name_list_t;
char_name_list_t create_char_name_list(int len) {
  char_name_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(char_name_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  int person_id;
  int person_role_id;
  int movie_id;
  int role_id;
  const char *note;
} cast_info_t;
typedef struct {
  int len;
  cast_info_t *data;
} cast_info_list_t;
cast_info_list_t create_cast_info_list(int len) {
  cast_info_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(cast_info_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  int id;
  const char *country_code;
} company_name_t;
typedef struct {
  int len;
  company_name_t *data;
} company_name_list_t;
company_name_list_t create_company_name_list(int len) {
  company_name_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(company_name_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  int movie_id;
  int company_id;
  const char *note;
} movie_companie_t;
typedef struct {
  int len;
  movie_companie_t *data;
} movie_companie_list_t;
movie_companie_list_t create_movie_companie_list(int len) {
  movie_companie_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(movie_companie_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  int id;
  const char *name;
  const char *gender;
} name_t;
typedef struct {
  int len;
  name_t *data;
} name_list_t;
name_list_t create_name_list(int len) {
  name_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(name_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  int id;
  const char *role;
} role_type_t;
typedef struct {
  int len;
  role_type_t *data;
} role_type_list_t;
role_type_list_t create_role_type_list(int len) {
  role_type_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(role_type_t));
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
  const char *alt;
  const char *character;
  const char *movie;
} matches_item_t;
typedef struct {
  int len;
  matches_item_t *data;
} matches_item_list_t;
matches_item_list_t create_matches_item_list(int len) {
  matches_item_list_t l;
  l.len = len;
  l.data = calloc(len, sizeof(matches_item_t));
  if (!l.data && len > 0) {
    fprintf(stderr, "alloc failed\n");
    exit(1);
  }
  return l;
}

typedef struct {
  const char *alternative_name;
  const char *character_name;
  const char *movie;
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

static list_int
    test_Q9_selects_minimal_alternative_name__character_and_movie_result;
static void test_Q9_selects_minimal_alternative_name__character_and_movie() {
  tmp1_t tmp1[] = {(tmp1_t){.alternative_name = "A. N. G.",
                            .character_name = "Angel",
                            .movie = "Famous Film"}};
  int tmp1_len = sizeof(tmp1) / sizeof(tmp1[0]);
  int tmp2 = 1;
  if (test_Q9_selects_minimal_alternative_name__character_and_movie_result
          .len != tmp1.len) {
    tmp2 = 0;
  } else {
    for (int i3 = 0;
         i3 <
         test_Q9_selects_minimal_alternative_name__character_and_movie_result
             .len;
         i3++) {
      if (test_Q9_selects_minimal_alternative_name__character_and_movie_result
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
  aka_name_t aka_name[] = {(aka_name_t){.person_id = 1, .name = "A. N. G."},
                           (aka_name_t){.person_id = 2, .name = "J. D."}};
  int aka_name_len = sizeof(aka_name) / sizeof(aka_name[0]);
  char_name_t char_name[] = {(char_name_t){.id = 10, .name = "Angel"},
                             (char_name_t){.id = 20, .name = "Devil"}};
  int char_name_len = sizeof(char_name) / sizeof(char_name[0]);
  cast_info_t cast_info[] = {(cast_info_t){.person_id = 1,
                                           .person_role_id = 10,
                                           .movie_id = 100,
                                           .role_id = 1000,
                                           .note = "(voice)"},
                             (cast_info_t){.person_id = 2,
                                           .person_role_id = 20,
                                           .movie_id = 200,
                                           .role_id = 1000,
                                           .note = "(voice)"}};
  int cast_info_len = sizeof(cast_info) / sizeof(cast_info[0]);
  company_name_t company_name[] = {
      (company_name_t){.id = 100, .country_code = "[us]"},
      (company_name_t){.id = 200, .country_code = "[gb]"}};
  int company_name_len = sizeof(company_name) / sizeof(company_name[0]);
  movie_companie_t movie_companies[] = {
      (movie_companie_t){
          .movie_id = 100, .company_id = 100, .note = "ACME Studios (USA)"},
      (movie_companie_t){
          .movie_id = 200, .company_id = 200, .note = "Maple Films"}};
  int movie_companies_len =
      sizeof(movie_companies) / sizeof(movie_companies[0]);
  name_t name[] = {(name_t){.id = 1, .name = "Angela Smith", .gender = "f"},
                   (name_t){.id = 2, .name = "John Doe", .gender = "m"}};
  int name_len = sizeof(name) / sizeof(name[0]);
  role_type_t role_type[] = {(role_type_t){.id = 1000, .role = "actress"},
                             (role_type_t){.id = 2000, .role = "actor"}};
  int role_type_len = sizeof(role_type) / sizeof(role_type[0]);
  title_t title[] = {
      (title_t){.id = 100, .title = "Famous Film", .production_year = 2010},
      (title_t){.id = 200, .title = "Old Movie", .production_year = 1999}};
  int title_len = sizeof(title) / sizeof(title[0]);
  list_string matches = list_string_create(4);
  matches.data[0] = "(voice)";
  matches.data[1] = "(voice: Japanese version)";
  matches.data[2] = "(voice) (uncredited)";
  matches.data[3] = "(voice: English version)";
  matches_item_list_t tmp4 = matches_item_list_t_create(
      aka_name.len * name.len * cast_info.len * char_name.len * title.len *
      movie_companies.len * company_name.len * role_type.len);
  int tmp5 = 0;
  for (int tmp6 = 0; tmp6 < aka_name_len; tmp6++) {
    aka_name_t an = aka_name[tmp6];
    for (int tmp7 = 0; tmp7 < name_len; tmp7++) {
      name_t n = name[tmp7];
      if (!(an.person_id == n.id)) {
        continue;
      }
      for (int tmp8 = 0; tmp8 < cast_info_len; tmp8++) {
        cast_info_t ci = cast_info[tmp8];
        if (!(ci.person_id == n.id)) {
          continue;
        }
        for (int tmp9 = 0; tmp9 < char_name_len; tmp9++) {
          char_name_t chn = char_name[tmp9];
          if (!(chn.id == ci.person_role_id)) {
            continue;
          }
          for (int tmp10 = 0; tmp10 < title_len; tmp10++) {
            title_t t = title[tmp10];
            if (!(t.id == ci.movie_id)) {
              continue;
            }
            for (int tmp11 = 0; tmp11 < movie_companies_len; tmp11++) {
              movie_companie_t mc = movie_companies[tmp11];
              if (!(mc.movie_id == t.id)) {
                continue;
              }
              for (int tmp12 = 0; tmp12 < company_name_len; tmp12++) {
                company_name_t cn = company_name[tmp12];
                if (!(cn.id == mc.company_id)) {
                  continue;
                }
                for (int tmp13 = 0; tmp13 < role_type_len; tmp13++) {
                  role_type_t rt = role_type[tmp13];
                  if (!(rt.id == ci.role_id)) {
                    continue;
                  }
                  if (!((contains_list_string(matches, ci.note)) &&
                        cn.country_code == "[us]" &&
                        (contains_string(mc.note, "(USA)") ||
                         contains_string(mc.note, "(worldwide)")) &&
                        n.gender == "f" && contains_string(n.name, "Ang") &&
                        rt.role == "actress" && t.production_year >= 2005 &&
                        t.production_year <= 2015)) {
                    continue;
                  }
                  tmp4.data[tmp5] = (matches_item_t){
                      .alt = an.name, .character = chn.name, .movie = t.title};
                  tmp5++;
                }
              }
            }
          }
        }
      }
    }
  }
  tmp4.len = tmp5;
  matches_item_list_t matches = tmp4;
  int tmp14 = int_create(matches.len);
  int tmp15 = 0;
  for (int tmp16 = 0; tmp16 < matches.len; tmp16++) {
    matches_item_t x = matches.data[tmp16];
    tmp14.data[tmp15] = x.alt;
    tmp15++;
  }
  tmp14.len = tmp15;
  int tmp17 = int_create(matches.len);
  int tmp18 = 0;
  for (int tmp19 = 0; tmp19 < matches.len; tmp19++) {
    matches_item_t x = matches.data[tmp19];
    tmp17.data[tmp18] = x.character;
    tmp18++;
  }
  tmp17.len = tmp18;
  int tmp20 = int_create(matches.len);
  int tmp21 = 0;
  for (int tmp22 = 0; tmp22 < matches.len; tmp22++) {
    matches_item_t x = matches.data[tmp22];
    tmp20.data[tmp21] = x.movie;
    tmp21++;
  }
  tmp20.len = tmp21;
  result_t result[] = {(result_t){.alternative_name = _min_string(tmp14),
                                  .character_name = _min_string(tmp17),
                                  .movie = _min_string(tmp20)}};
  int result_len = sizeof(result) / sizeof(result[0]);
  printf("[");
  for (int i23 = 0; i23 < result_len; i23++) {
    if (i23 > 0)
      printf(",");
    result_t it = result[i23];
    printf("{");
    _json_string("alternative_name");
    printf(":");
    _json_string(it.alternative_name);
    printf(",");
    _json_string("character_name");
    printf(":");
    _json_string(it.character_name);
    printf(",");
    _json_string("movie");
    printf(":");
    _json_string(it.movie);
    printf("}");
  }
  printf("]");
  test_Q9_selects_minimal_alternative_name__character_and_movie_result = result;
  test_Q9_selects_minimal_alternative_name__character_and_movie();
  free(tmp14.data);
  free(tmp17.data);
  free(tmp20.data);
  return 0;
}
