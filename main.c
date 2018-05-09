#include <kipr/botball.h>
#include <hough2.h>
int main()
{

const int height = 120;
const int width = 160;
int threshold = 200;

int edges[height][width];
int raw[height][width][3];
    
   
    sizep_t num_points = height * width;
    sizep_t thresholdh = 12;
    double tolerence_t = 15.0;
    double tolerence_r = 5.0;
    sizep_t precision = 1;
	SIZE_TYPE size = {width,height};
    sizep_t max_lines = 50;
    LINE_TYPE *lines;
    

int i,j,r,c,w;
const unsigned char *img;
    while(camera_open()!=1)
    {
    }
       // msleep(1000);
    graphics_open(320,240);
    msleep(500);
    int count;
    
    
    for(count = 0;count < 10;count++)//loop
    {
camera_update();
    msleep(500);
img=get_camera_frame();
    msleep(500);
for(r=0;r<120;r++) {
 for(c=0;c<160;c++) {
     edges[r][c] = 0;
 i=3*(160*r + c); // index of pixel to paint into row r, column c
	for(j = 0;j < 3;j++)
{
raw[r][c][j] = img[i+(2-j)];
}

 }
}
        
     
 



int total = 0;




for (i = 1; i < height - 1; i++)
{
for (j = 1; j < width - 1; j++)
{
    total = abs(raw[i + 1][ j + 1][ 2] - raw[i][ j][ 2]) +
    	abs(raw[i + 1][ j + 1][ 0] - raw[i][ j][ 0]) +
    	abs(raw[i + 1][ j + 1][ 1] - raw[i][ j][ 1]);
    if (total > threshold)
    { edges[i][ j] = 1; }

    total = abs(raw[i][ j + 1][ 2] - raw[i][ j][ 2]) +
    	abs(raw[i][ j + 1][ 0] - raw[i][ j][ 0]) +
    	abs(raw[i][ j + 1][ 1] - raw[i][ j][ 1]);
    if (total > threshold)
    { edges[i][ j] = 1; }

    total = abs(raw[i + 1][ j][ 2] - raw[i][ j][ 2]) +
    	abs(raw[i + 1][ j][ 0] - raw[i][ j][ 0]) +
    	abs(raw[i + 1][ j][ 1] - raw[i][ j][ 1]);
    if (total > threshold)
    { edges[i][ j] = 1; }

    total = abs(raw[i - 1][ j - 1][ 2] - raw[i][ j][ 2]) +
    	abs(raw[i - 1][ j - 1][ 0] - raw[i][ j][ 0]) +
    	abs(raw[i - 1][ j - 1][ 1] - raw[i][ j][ 1]);
    if (total > threshold)
    { edges[i][ j] = 1; }

    total = abs(raw[i][ j - 1][ 2] - raw[i][ j][ 2]) +
    	abs(raw[i][ j - 1][ 0] - raw[i][ j][ 0]) +
    	abs(raw[i][ j - 1][ 1] - raw[i][ j][ 1]);
    if (total > threshold)
    { edges[i][ j] = 1; }

    total = abs(raw[i - 1][ j][ 2] - raw[i][ j][ 2]) +
    	abs(raw[i - 1][ j][ 0] - raw[i][ j][ 0]) +
    	abs(raw[i - 1][ j][ 1] - raw[i][ j][ 1]);
    if (total > threshold)
    { edges[i][ j] = 1; }

    total = abs(raw[i - 1][ j + 1][ 2] - raw[i][ j][ 2]) +
    	abs(raw[i - 1][ j + 1][ 0] - raw[i][ j][ 0]) +
    	abs(raw[i - 1][ j + 1][ 1] - raw[i][ j][ 1]);
    if (total > threshold)
    { edges[i][ j] = 1; }

    total = abs(raw[i + 1][ j - 1][ 2] - raw[i][ j][ 2]) +
    	abs(raw[i + 1][ j - 1][ 0] - raw[i][ j][ 0]) +
    	abs(raw[i + 1][ j - 1][ 1] - raw[i][ j][ 1]);
    if (total > threshold)
    { edges[i][ j] = 1; }
}
}
        
    graphics_fill(0,0,0);
        w = 0;
       for(r=0;r<120;r++) {
 for(c=0;c<160;c++) {
     if(edges[r][c] == 1)
     {
         w++;
graphics_pixel(c,r,127,127,127);
     }
 }
}
    graphics_update();
         POINT_TYPE points[w];
        POINT_TYPE p;
        num_points = w;
        w = 0;
        for(r=0;r<120;r++) {
 for(c=0;c<160;c++) {
     if(edges[r][c] == 1)
     {
         p.x = c;
         p.y = r;
points[w] = p;
         w++;
     }
    

 }
}
    //setup_hough(points,num_points,thresholdh,tolerence_t,tolerence_r,precision,size,max_lines);
        
      //print_classifier();
        //finish_hough();
    }

    return 0;
}
