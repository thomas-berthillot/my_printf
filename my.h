#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <stdarg.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdbool.h>

typedef struct {
    void *data;
    size_t size;
} buffer_t;

typedef struct {
    bool minus;
    bool plus;
    bool space;
    bool zero;
    bool hash;
    int width;
    int precision;
} flag_state_t;

typedef struct {
    char *flags;
    char *lenght;
    char *precision;
    char *size;
    char conversion;
} constructor_info_t;

typedef struct format_info {
    int exp;
    int neg;
    int precision;
} format_info_t;

int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
void *my_memcpy(void *dest, void const *src, size_t n);
void append_char(char *s, char c);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
void str_upper(char *str);

int my_delta_realloc(buffer_t *buf, ptrdiff_t delta);
int output_constructor(buffer_t *buf, char const *src, size_t len);
int out_rep(int n, char c, buffer_t *buf);
int emit_text(buffer_t *buf, flag_state_t *st, char const *s, int len);
int emit_number(buffer_t *buf, flag_state_t *st, char const *prefix,
    char const *digits);

int num_len(unsigned long long nb);
char *alloc_str(int len);
void fill_num(char *str, unsigned long long nb, int len);
long get_abs_int(int n);
char *my_itoa(int nb);
char *my_utoa(unsigned int n);
void my_puterr(char const *msg);

int checker(double nb);
char *special_value(double n);
double abs_rounded(double n, int precision);
double get_absf(double n);
char *e_for_0(char *str);
void fill_exposant(char *str, int exp);
char *uppercase(char *hex);
char *my_ftoa(double n, int precision);
char *my_etoa(double n, int precision);
char *my_gtoa(double n, int precision);
char *mybigftoa(double n, int precision);
char *my_bigetoa(double n, int precision);

int hex_len(unsigned int nb);
int oct_len(unsigned int nb);
char *unpeutout(unsigned int nb, int len);
char *unpeutout_hex(unsigned int nb, int len);
char calcul_hexa(unsigned nb);

constructor_info_t flag_parseur(const char *format, int *i);
bool check_size(char c);
bool check_precission(char c);
bool check_flags(char c);
bool check_lenght(char c);
flag_state_t normalize_info(constructor_info_t *info);
void free_constructor_info(constructor_info_t *info);
char const *float_prefix(double val, flag_state_t *st);

int flag_output_constructor(buffer_t *buf, const char *format, int *i,
    va_list *args);
int dispatch_conversion(buffer_t *buf, constructor_info_t *info, va_list *args,
    flag_state_t *st);
int unknown_flag(char flag, buffer_t *buf);

int fc_puller(va_list *args, buffer_t *buf, flag_state_t *st);
int fs_puller(va_list *args, buffer_t *buf, flag_state_t *st);
int fu_puller(va_list *args, buffer_t *buf, flag_state_t *st);
int fi_puller(va_list *args, buffer_t *buf, flag_state_t *st);
int fo_puller(va_list *args, buffer_t *buf, flag_state_t *st);
int fx_puller(va_list *args, buffer_t *buf, flag_state_t *st);
int fbigx_puller(va_list *args, buffer_t *buf, flag_state_t *st);
int ff_puller(va_list *args, buffer_t *buf, flag_state_t *st);
int fbigf_puller(va_list *args, buffer_t *buf, flag_state_t *st);
int fbige_puller(va_list *args, buffer_t *buf, flag_state_t *st);
int fg_puller(va_list *args, buffer_t *buf, flag_state_t *st);
int fe_puller(va_list *args, buffer_t *buf, flag_state_t *st);
int fbigg_puller(va_list *args, buffer_t *buf, flag_state_t *st);


int my_printf(const char *format, ...);

#endif
