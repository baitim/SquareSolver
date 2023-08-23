#ifndef Defines_enums_structs_const
#define Defines_enums_structs_const

#define ANSI_DEFAULT_COLOUR  "\033[0m"
#define ANSI_YELLOW          "\033[33m"
#define ANSI_LIGHT_RED       "\033[91m"
#define ANSI_LIGHT_GREEN     "\033[92m"
#define ANSI_LIGHT_YELLOW    "\033[93m"
#define ANSI_LIGHT_BLUE      "\033[94m"
#define ANSI_LIGHT_CYAN      "\033[96m"

#ifndef NDEBUG
#define ASSERT(x)\
        if (!(x)) {\
                printf(ANSI_LIGHT_RED "Text in assert: (%s)\n", #x);\
                printf("File: %s\n", __FILE__);\
                printf("Function: %s\n", __PRETTY_FUNCTION__);\
                printf("Line: %d\n" ANSI_DEFAULT_COLOUR, __LINE__);\
                exit(0);\
        }
#else
#define ASSERT(...)
#endif

#define TEST_ON

enum number_roots {
        ROOT_0,
        ROOT_1_QUAD,
        ROOT_2_QUAD,
        ROOT_1_LINE,
        ROOT_INF,
        ROOT_ERR
};

enum user_choice {
        USER_CONTINUE,
        USER_CORRECT,
        USER_EXIT
};

struct coefs_roots {
        double a, b, c;
        double root1, root2;
        number_roots count_root;
};

struct cmd_input_data {
        bool is_coeffs_input;
        double a, b, c;
        bool is_test_on;
        char *name_test_file;
};

const double EPSILON = 1e-7;

#endif
