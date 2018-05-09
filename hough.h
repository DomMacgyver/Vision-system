#define PI 3.14159265

typedef int dim_t;
typedef int grade_t;
typedef unsigned int sizep_t;

typedef struct {
	double t;
	double r;
} LINE_TYPE;

typedef struct {
	dim_t x;
	dim_t y;
} POINT_TYPE;

typedef struct {
	dim_t width;
	dim_t height;
	dim_t diagonal;
	dim_t semi_diagonal;
} SIZE_TYPE;

typedef struct {
	sizep_t* pindex;
	sizep_t count;
	dim_t r;
	grade_t t;
	short processed;
} _CELL_TYPE;

typedef struct {
	double t;
	double r;
	_CELL_TYPE** cells;
	sizep_t lenght;
} _CENTER_TYPE;

typedef struct {
	sizep_t length;
	_CENTER_TYPE* centers;

} _CLASSIFIER_TYPE;

sizep_t _precision;
unsigned int _circumference;
unsigned int _semi_circumference;

SIZE_TYPE _dimensions;
_CELL_TYPE** _accumulator;
POINT_TYPE* _input_points;
sizep_t _num_points;

sizep_t _threshold;
sizep_t _tolerance_t;
sizep_t _tolerance_r;
sizep_t _max_lines;
_CLASSIFIER_TYPE _classifier;

double *_SIN_CACHE;
double *_COS_CACHE;

void setup_hough(POINT_TYPE*, sizep_t, sizep_t, double, double, sizep_t, SIZE_TYPE, sizep_t);
void finish_hough(void);

double _distance_r(double, double);
double _distance_t(double, double);
void _classify(_CELL_TYPE*);
void print_classifier(void);

inline double _cached_sin(grade_t);
inline double _cached_cos(grade_t);
inline dim_t _r(dim_t, dim_t, grade_t);


void plot_point(sizep_t);
sizep_t get_lines(LINE_TYPE**);