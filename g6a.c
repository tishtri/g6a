/* generate hexagon grid on plane */

#include <stdio.h>
#include <stdlib.h>

char * HELP = "Generator of Petri net models of hexagon grid (with plugs on edges)\n"
              "Product of Tatiana R. Shmeleva \n\n"
              "USAGE: g6a k [p] [b] > hx_model.ndr\n"
              "  k - size of hexagon grid,\n"
              "  p - number of packets in each buffer section,\n"
              "  b - available buffer size,\n"
              "  output format - .ndr file of Tina www.laas.fr/tina\n\n";

#define DI (150.0*x)
#define DJ (170.0*x)
#define DLT (10.0*x)

main( int argc, char * argv[] )
{
 int k,i,j,l,off=0,p=0,b=0;
 int qj, i1, ik;
 double x=2.0;
 
 if( argc < 2 )
 {
   fprintf(stderr,HELP);
   fprintf(stderr, "*** actually: %d arguments\n", argc);
   return 2;
 }
 k = atoi( argv[1] );
 if(argc>2) p = atoi( argv[2] );
 if(argc>3) b = atoi( argv[3] );
 
 for(i=1; i<=2*k-1; i++)   /*   for1 */
 {
	off=(i<=k)?(k-i)*DJ/2:(i-k)*DJ/2+DLT;
	 
    for(j=1; j<=((i<=k)?k+i-1:3*k-1-i); j++)    /*   for2 */
   {
   	   //fprintf(stderr,"i=%d j=%d\n",i,j);
   	   
	  /* buffers and buffer limit */ 
	  printf("p %.1f %.1f {pbl^%d.%d} %d n\n",off+j*DJ+89.0*x, i*DI+98.0*x, i,j, b);
   	  printf("p %.1f %.1f {pb1^%d.%d} %d n\n",off+j*DJ+95.0*x, i*DI+80.0*x, i,j, p);
	  printf("p %.1f %.1f {pb2^%d.%d} %d n\n",off+j*DJ+106.0*x, i*DI+100.0*x, i,j, p);	
	  printf("p %.1f %.1f {pb3^%d.%d} %d n\n",off+j*DJ+100.0*x, i*DI+108.0*x, i,j, p); 
	  printf("p %.1f %.1f {pb4^%d.%d} %d n\n",off+j*DJ+78.0*x, i*DI+108.0*x, i,j, p);
	  printf("p %.1f %.1f {pb5^%d.%d} %d n\n",off+j*DJ+68.0*x, i*DI+98.0*x, i,j, p);	
	  printf("p %.1f %.1f {pb6^%d.%d} %d n\n",off+j*DJ+76.0*x, i*DI+85.0*x, i,j, p);
		  	
   	
   		 // 1 port 
	  printf("p %.1f %.1f {pi1^%d.%d} 0 n\n",off+j*DJ+92.0*x, i*DI+8.0*x, i,j);
	  printf("p %.1f %.1f {pil1^%d.%d} 1 n\n",off+j*DJ+109.0*x, i*DI+16.0*x, i,j);
	  printf("p %.1f %.1f {po1^%d.%d} 0 n\n",off+j*DJ+135.0*x, i*DI+35.0*x, i,j);
	  printf("p %.1f %.1f {pol1^%d.%d} 1 n\n",off+j*DJ+157.0*x, i*DI+45.0*x, i,j);
	  
	  printf("t %.1f %.1f {to1^%d.%d} 0 w n\n", off+j*DJ+142.0*x, i*DI+50.0*x, i, j);
	  printf("e {pb1^%d.%d} {to1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to1^%d.%d} {po1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pol1^%d.%d} {to1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to1^%d.%d} {pbl^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti1,2^%d.%d} 0 w n\n", off+j*DJ+90.0*x, i*DI+18.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti1,2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,2^%d.%d} {pil1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi1^%d.%d} {ti1,2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,2^%d.%d} {pb2^%d.%d} 1 n\n", i, j, i, j);
	 
	  printf("t %.1f %.1f {ti1,3^%d.%d} 0 w n\n", off+j*DJ+96.0*x, i*DI+23.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti1,3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,3^%d.%d} {pil1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi1^%d.%d} {ti1,3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,3^%d.%d} {pb3^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti1,4^%d.%d} 0 w n\n", off+j*DJ+108.0*x, i*DI+28.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti1,4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,4^%d.%d} {pil1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi1^%d.%d} {ti1,4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,4^%d.%d} {pb4^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti1,5^%d.%d} 0 w n\n", off+j*DJ+118.0*x, i*DI+35.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti1,5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,5^%d.%d} {pil1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi1^%d.%d} {ti1,5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,5^%d.%d} {pb5^%d.%d} 1 n\n", i, j, i, j);
	 
	  printf("t %.1f %.1f {ti1,6^%d.%d} 0 w n\n", off+j*DJ+125.*x, i*DI+40.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti1,6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,6^%d.%d} {pil1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi1^%d.%d} {ti1,6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,6^%d.%d} {pb6^%d.%d} 1 n\n", i, j, i, j);
	  
	  if ((i==1)||((i<=k)&&(j==k+i-1)))
      {
      printf("t %.1f %.1f {t1^%d.%d} 0 w n\n", off+j*DJ+130.0*x, i*DI+20.0*x, i, j);
	  printf("e {po1^%d.%d} {t1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {t1^%d.%d} {pol1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pil1^%d.%d} {t1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {t1^%d.%d} {pi1^%d.%d} 1 n\n", i, j, i, j);
		   } 
	  else{
	  }	
	  
    // 2 port 
      printf("p %.1f %.1f {pi2^%d.%d} 0 n\n",off+j*DJ+165.0*x, i*DI+63.0*x, i,j);
	  printf("p %.1f %.1f {pil2^%d.%d} 1 n\n",off+j*DJ+165.0*x, i*DI+88.0*x, i,j);
	  printf("p %.1f %.1f {po2^%d.%d} 0 n\n",off+j*DJ+165.0*x, i*DI+115.0*x, i,j);
	  printf("p %.1f %.1f {pol2^%d.%d} 1 n\n",off+j*DJ+165.0*x, i*DI+135.0*x, i,j);
	  
	  printf("t %.1f %.1f {to2^%d.%d} 0 w n\n", off+j*DJ+156.0*x, i*DI+125.0*x, i, j);
	  printf("e {pb2^%d.%d} {to2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to2^%d.%d} {po2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pol2^%d.%d} {to2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to2^%d.%d} {pbl^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti2,1^%d.%d} 0 w n\n", off+j*DJ+156.0*x, i*DI+68.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti2,1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,1^%d.%d} {pil2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi2^%d.%d} {ti2,1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,1^%d.%d} {pb1^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti2,3^%d.%d} 0 w n\n", off+j*DJ+156.0*x, i*DI+76.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti2,3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,3^%d.%d} {pil2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi2^%d.%d} {ti2,3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,3^%d.%d} {pb3^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti2,4^%d.%d} 0 w n\n", off+j*DJ+156.0*x, i*DI+88.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti2,4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,4^%d.%d} {pil2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi2^%d.%d} {ti2,4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,4^%d.%d} {pb4^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti2,5^%d.%d} 0 w n\n", off+j*DJ+156.0*x, i*DI+98.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti2,5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,5^%d.%d} {pil2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi2^%d.%d} {ti2,5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,5^%d.%d} {pb5^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti2,6^%d.%d} 0 w n\n", off+j*DJ+156.0*x, i*DI+105.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti2,6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,6^%d.%d} {pil2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi2^%d.%d} {ti2,6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,6^%d.%d} {pb6^%d.%d} 1 n\n", i, j, i, j);
	  
	  if (((i<=k)&&(j==k+i-1))||((i>k)&&(j==3*k-i-1)))
      {
      printf("t %.1f %.1f {t2^%d.%d} 0 w n\n", off+j*DJ+180.0*x, i*DI+105.0*x, i, j);
	  printf("e {po2^%d.%d} {t2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {t2^%d.%d} {pol2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pil2^%d.%d} {t2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {t2^%d.%d} {pi2^%d.%d} 1 n\n", i, j, i, j);
		} 
	  else{
	  }	
	  
	// 3 port 
	  printf("p %.1f %.1f {pi3^%d.%d} 0 n\n",off+j*DJ+150.0*x, i*DI+155.0*x, i,j);
	  printf("p %.1f %.1f {pil3^%d.%d} 1 n\n",off+j*DJ+138.0*x, i*DI+165.0*x, i,j);
	  printf("p %.1f %.1f {po3^%d.%d} 0 n\n",off+j*DJ+117.0*x, i*DI+175.0*x, i,j);
	  printf("p %.1f %.1f {pol3^%d.%d} 1 n\n",off+j*DJ+100.0*x, i*DI+185.0*x, i,j);
	  
	  printf("t %.1f %.1f {to3^%d.%d} 0 w n\n", off+j*DJ+105.0*x, i*DI+175.0*x, i, j);
	  printf("e {pb3^%d.%d} {to3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to3^%d.%d} {po3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pol3^%d.%d} {to3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to3^%d.%d} {pbl^%d.%d} 1 n\n", i, j, i, j);
	 
	  printf("t %.1f %.1f {ti3,1^%d.%d} 0 w n\n", off+j*DJ+120.0*x, i*DI+165.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti3,1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,1^%d.%d} {pil3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi3^%d.%d} {ti3,1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,1^%d.%d} {pb1^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti3,2^%d.%d} 0 w n\n", off+j*DJ+125.0*x, i*DI+160.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti3,2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,2^%d.%d} {pil3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi3^%d.%d} {ti3,2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,2^%d.%d} {pb2^%d.%d} 1 n\n", i, j, i, j);
	 
	  printf("t %.1f %.1f {ti3,4^%d.%d} 0 w n\n", off+j*DJ+135.0*x, i*DI+155.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti3,4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,4^%d.%d} {pil3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi3^%d.%d} {ti3,4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,4^%d.%d} {pb4^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti3,5^%d.%d} 0 w n\n", off+j*DJ+140.0*x, i*DI+150.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti3,5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,5^%d.%d} {pil3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi3^%d.%d} {ti3,5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,5^%d.%d} {pb5^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti3,6^%d.%d} 0 w n\n", off+j*DJ+150.0*x, i*DI+145.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti3,6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,6^%d.%d} {pil3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi3^%d.%d} {ti3,6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,6^%d.%d} {pb6^%d.%d} 1 n\n", i, j, i, j);
	  
	  if ((i==2*k-1)||((i>k)&&(j==3*k-i-1))||((i==k)&&(j==k+i-1)))
      {
      printf("t %.1f %.1f {t3^%d.%d} 0 w n\n", off+j*DJ+130.0*x, i*DI+180.0*x, i, j);
	  printf("e {po3^%d.%d} {t3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {t3^%d.%d} {pol3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pil3^%d.%d} {t3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {t3^%d.%d} {pi3^%d.%d} 1 n\n", i, j, i, j);
		   } 
	  else{
	  }	
	  
	  
	  // 4 port 
	  printf("t %.1f %.1f {to4^%d.%d} 0 w n\n", off+j*DJ+30.0*x, i*DI+152.0*x, i, j);
	  printf("e {pb4^%d.%d} {to4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to4^%d.%d} {pbl^%d.%d} 1 n\n", i, j, i, j);
	 
	  printf("t %.1f %.1f {ti4,1^%d.%d} 0 w n\n", off+j*DJ+48.0*x, i*DI+162.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti4,1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti4,1^%d.%d} {pb1^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti4,2^%d.%d} 0 w n\n", off+j*DJ+55.0*x, i*DI+166.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti4,2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti4,2^%d.%d} {pb2^%d.%d} 1 n\n", i, j, i, j);
	 
	  printf("t %.1f %.1f {ti4,3^%d.%d} 0 w n\n", off+j*DJ+62.0*x, i*DI+171.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti4,3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti4,3^%d.%d} {pb3^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti4,5^%d.%d} 0 w n\n", off+j*DJ+70.0*x, i*DI+175.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti4,5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti4,5^%d.%d} {pb5^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti4,6^%d.%d} 0 w n\n", off+j*DJ+78.0*x, i*DI+180.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti4,6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti4,6^%d.%d} {pb6^%d.%d} 1 n\n", i, j, i, j);
	  
	   
	 // port 5 
	 printf("t %.1f %.1f {to5^%d.%d} 0 w n\n", off+j*DJ+15.0*x, i*DI+80.0*x, i, j);
	 printf("e {pb5^%d.%d} {to5^%d.%d} 1 n\n", i, j, i, j);
	 printf("e {to5^%d.%d} {pbl^%d.%d} 1 n\n", i, j, i, j);
	 
	 printf("t %.1f %.1f {ti5,1^%d.%d} 0 w n\n", off+j*DJ+15.0*x, i*DI+100.0*x, i, j);
	 printf("e {pbl^%d.%d} {ti5,1^%d.%d} 1 n\n", i, j, i, j);
	 printf("e {ti5,1^%d.%d} {pb1^%d.%d} 1 n\n", i, j, i, j);
	 
	 printf("t %.1f %.1f {ti5,2^%d.%d} 0 w n\n", off+j*DJ+15.0*x, i*DI+105.0*x, i, j);
	 printf("e {pbl^%d.%d} {ti5,2^%d.%d} 1 n\n", i, j, i, j);
	 printf("e {ti5,2^%d.%d} {pb2^%d.%d} 1 n\n", i, j, i, j);
	 
	 printf("t %.1f %.1f {ti5,3^%d.%d} 0 w n\n", off+j*DJ+15.0*x, i*DI+115.0*x, i, j);
	 printf("e {pbl^%d.%d} {ti5,3^%d.%d} 1 n\n", i, j, i, j);
	 printf("e {ti5,3^%d.%d} {pb3^%d.%d} 1 n\n", i, j, i, j);
	 	 
	 printf("t %.1f %.1f {ti5,4^%d.%d} 0 w n\n", off+j*DJ+15.0*x, i*DI+122.0*x, i, j);
	 printf("e {pbl^%d.%d} {ti5,4^%d.%d} 1 n\n", i, j, i, j);
	 printf("e {ti5,4^%d.%d} {pb4^%d.%d} 1 n\n", i, j, i, j);
	 
	 printf("t %.1f %.1f {ti5,6^%d.%d} 0 w n\n", off+j*DJ+15.0*x, i*DI+130.0*x, i, j);
	 printf("e {pbl^%d.%d} {ti5,6^%d.%d} 1 n\n", i, j, i, j);
	 printf("e {ti5,6^%d.%d} {pb6^%d.%d} 1 n\n", i, j, i, j);
	 
	 // 6 port 
	  printf("t %.1f %.1f {to6^%d.%d} 0 w n\n", off+j*DJ+65.0*x, i*DI+30.0*x, i, j);
	  printf("e {pb6^%d.%d} {to6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to6^%d.%d} {pbl^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti6,1^%d.%d} 0 w n\n", off+j*DJ+50.0*x, i*DI+30.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti6,1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti6,1^%d.%d} {pb1^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti6,2^%d.%d} 0 w n\n", off+j*DJ+45.0*x, i*DI+35.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti6,2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti6,2^%d.%d} {pb2^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti6,3^%d.%d} 0 w n\n", off+j*DJ+35.0*x, i*DI+45.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti6,3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti6,3^%d.%d} {pb3^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti6,4^%d.%d} 0 w n\n", off+j*DJ+30.0*x, i*DI+50.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti6,4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti6,4^%d.%d} {pb4^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti6,5^%d.%d} 0 w n\n", off+j*DJ+20.0*x, i*DI+55.0*x, i, j);
	  printf("e {pbl^%d.%d} {ti6,5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti6,5^%d.%d} {pb5^%d.%d} 1 n\n", i, j, i, j);
	  
	  
	  if (i<=(2*k-1) && j==1)  // if 1  5port
	  {
	  // 5 port	
      printf("p %.1f %.1f {pi5^%d.%d} 0 n\n",off+j*DJ+5.0*x, i*DI+133.0*x, i,j);
	  printf("p %.1f %.1f {pil5^%d.%d} 1 n\n",off+j*DJ+5.0*x, i*DI+115.0*x, i,j);
	  printf("p %.1f %.1f {po5^%d.%d} 0 n\n",off+j*DJ+5.0*x, i*DI+85.0*x, i,j);
	  printf("p %.1f %.1f {pol5^%d.%d} 1 n\n",off+j*DJ+5.0*x, i*DI+68.0*x, i,j);
	  
	  printf("e {to5^%d.%d} {po5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pol5^%d.%d} {to5^%d.%d} 1 n\n", i, j, i, j);
	 
	  printf("e {ti5,1^%d.%d} {pil5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi5^%d.%d} {ti5,1^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti5,2^%d.%d} {pil5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi5^%d.%d} {ti5,2^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti5,3^%d.%d} {pil5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi5^%d.%d} {ti5,3^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti5,4^%d.%d} {pil5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi5^%d.%d} {ti5,4^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti5,6^%d.%d} {pil5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi5^%d.%d} {ti5,6^%d.%d} 1 n\n", i, j, i, j);
	  }
      else{
        }   //end   if 5port

	  
		 
	if (i<=k && j==1)  // if 1
	  {
	  // 6 port 
	  printf("p %.1f %.1f {pi6^%d.%d} 0 n\n",off+j*DJ+15.0*x, i*DI+48.0*x, i,j);
	  printf("p %.1f %.1f {pil6^%d.%d} 1 n\n",off+j*DJ+33.0*x, i*DI+40.0*x, i,j);
	  printf("p %.1f %.1f {po6^%d.%d} 0 n\n",off+j*DJ+55.0*x, i*DI+23.0*x, i,j);
	  printf("p %.1f %.1f {pol6^%d.%d} 1 n\n",off+j*DJ+65.0*x, i*DI+16.0*x, i,j);
	  
	  printf("e {to6^%d.%d} {po6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pol6^%d.%d} {to6^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti6,1^%d.%d} {pil6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi6^%d.%d} {ti6,1^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti6,2^%d.%d} {pil6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi6^%d.%d} {ti6,2^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti6,3^%d.%d} {pil6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi6^%d.%d} {ti6,3^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti6,4^%d.%d} {pil6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi6^%d.%d} {ti6,4^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti6,5^%d.%d} {pil6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi6^%d.%d} {ti6,5^%d.%d} 1 n\n", i, j, i, j);
	  }
      else{
        }   //end   if 1

	  if (i==1 && j>1) // for (1,j) add 6 port   if 4
      {
	  // 6 port 
	  printf("p %.1f %.1f {pi6^%d.%d} 0 n\n",off+j*DJ+15.0*x, i*DI+48.0*x, i,j);
	  printf("p %.1f %.1f {pil6^%d.%d} 1 n\n",off+j*DJ+33.0*x, i*DI+40.0*x, i,j);
	  printf("p %.1f %.1f {po6^%d.%d} 0 n\n",off+j*DJ+55.0*x, i*DI+23.0*x, i,j);
	  printf("p %.1f %.1f {pol6^%d.%d} 1 n\n",off+j*DJ+65.0*x, i*DI+16.0*x, i,j);
	  
	  printf("e {to6^%d.%d} {po6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pol6^%d.%d} {to6^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti6,1^%d.%d} {pil6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi6^%d.%d} {ti6,1^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti6,2^%d.%d} {pil6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi6^%d.%d} {ti6,2^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti6,3^%d.%d} {pil6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi6^%d.%d} {ti6,3^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti6,4^%d.%d} {pil6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi6^%d.%d} {ti6,4^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti6,5^%d.%d} {pil6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi6^%d.%d} {ti6,5^%d.%d} 1 n\n", i, j, i, j);
	  }
      else{
        }   //end   if 4

	  
	  if (i>=k && j==1)  // if 2
	  {
	  // port 4    	
	  printf("p %.1f %.1f {pi4^%d.%d} 0 n\n",off+j*DJ+70.0*x, i*DI+180.0*x, i,j);
	  printf("p %.1f %.1f {pil4^%d.%d} 1 n\n",off+j*DJ+55.0*x, i*DI+175.0*x, i,j);
	  printf("p %.1f %.1f {po4^%d.%d} 0 n\n",off+j*DJ+35.0*x, i*DI+163.0*x, i,j);
	  printf("p %.1f %.1f {pol4^%d.%d} 1 n\n",off+j*DJ+18.0*x, i*DI+153.0*x, i,j);
	  
	  printf("e {to4^%d.%d} {po4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pol4^%d.%d} {to4^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti4,1^%d.%d} {pil4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi4^%d.%d} {ti4,1^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti4,2^%d.%d} {pil4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi4^%d.%d} {ti4,2^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti4,3^%d.%d} {pil4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi4^%d.%d} {ti4,3^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti4,5^%d.%d} {pil4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi4^%d.%d} {ti4,5^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti4,6^%d.%d} {pil4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi4^%d.%d} {ti4,6^%d.%d} 1 n\n", i, j, i, j);
	  }
      else{
        }   //end   if 2
	 	 
	  if (i==(2*k-1) && j>1)  // if last4
	  {
	  // port 4    	
	  printf("p %.1f %.1f {pi4^%d.%d} 0 n\n",off+j*DJ+70.0*x, i*DI+180.0*x, i,j);
	  printf("p %.1f %.1f {pil4^%d.%d} 1 n\n",off+j*DJ+55.0*x, i*DI+175.0*x, i,j);
	  printf("p %.1f %.1f {po4^%d.%d} 0 n\n",off+j*DJ+35.0*x, i*DI+163.0*x, i,j);
	  printf("p %.1f %.1f {pol4^%d.%d} 1 n\n",off+j*DJ+18.0*x, i*DI+153.0*x, i,j);
	  
	  printf("e {to4^%d.%d} {po4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pol4^%d.%d} {to4^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti4,1^%d.%d} {pil4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi4^%d.%d} {ti4,1^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti4,2^%d.%d} {pil4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi4^%d.%d} {ti4,2^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti4,3^%d.%d} {pil4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi4^%d.%d} {ti4,3^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti4,5^%d.%d} {pil4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi4^%d.%d} {ti4,5^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {ti4,6^%d.%d} {pil4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi4^%d.%d} {ti4,6^%d.%d} 1 n\n", i, j, i, j);
	  }
      else{
        }   //end   if last4
	
	
	// bags to 4, 5, 6 ports
	if (((i>=k)&&(j==1))||(i==2*k-1))
      {
      printf("t %.1f %.1f {t4^%d.%d} 0 w n\n", off+j*DJ+40.0*x, i*DI+180.0*x, i, j);
	  printf("e {po4^%d.%d} {t4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {t4^%d.%d} {pol4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pil4^%d.%d} {t4^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {t4^%d.%d} {pi4^%d.%d} 1 n\n", i, j, i, j);
		} 
	  else{
	  }	
	
	if (j==1) 
      {
      printf("t %.1f %.1f {t5^%d.%d} 0 w n\n", off+j*DJ+0.0*x, i*DI+95.0*x, i, j);
	  printf("e {po5^%d.%d} {t5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {t5^%d.%d} {pol5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pil5^%d.%d} {t5^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {t5^%d.%d} {pi5^%d.%d} 1 n\n", i, j, i, j);
		} 
	  else{
	  }	  
	  	 
	if ((i==1)||((i<=k)&&(j==1)))
      {
      printf("t %.1f %.1f {t6^%d.%d} 0 w n\n", off+j*DJ+30.0*x, i*DI+20.0*x, i, j);
	  printf("e {po6^%d.%d} {t6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {t6^%d.%d} {pol6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pil6^%d.%d} {t6^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {t6^%d.%d} {pi6^%d.%d} 1 n\n", i, j, i, j);
		} 
	  else{
	  }	
	
	
	/* add arcs    *******************************************************/
	// 5-2 port arcs
	 if (j>1) 
	  {
   	  printf("e {to5^%d.%d} {pi2^%d.%d} 1 n\n", i, j, i, j-1);
   	  printf("e {pil2^%d.%d} {to5^%d.%d} 1 n\n", i, j-1, i, j);
	 
	  printf("e {po2^%d.%d} {ti5,1^%d.%d} 1 n\n", i, j-1, i, j);
	  printf("e {ti5,1^%d.%d} {pol2^%d.%d} 1 n\n", i, j, i, j-1);
	  
	  printf("e {po2^%d.%d} {ti5,2^%d.%d} 1 n\n", i, j-1, i, j);
	  printf("e {ti5,2^%d.%d} {pol2^%d.%d} 1 n\n", i, j, i, j-1);
	  
	  printf("e {po2^%d.%d} {ti5,3^%d.%d} 1 n\n", i, j-1, i, j);
	  printf("e {ti5,3^%d.%d} {pol2^%d.%d} 1 n\n", i, j, i, j-1);
	  
	  printf("e {po2^%d.%d} {ti5,4^%d.%d} 1 n\n", i, j-1, i, j);
	  printf("e {ti5,4^%d.%d} {pol2^%d.%d} 1 n\n", i, j, i, j-1);
	  
	  printf("e {po2^%d.%d} {ti5,6^%d.%d} 1 n\n", i, j-1, i, j);
	  printf("e {ti5,6^%d.%d} {pol2^%d.%d} 1 n\n", i, j, i, j-1);
	 }
	else
	{
	}
	  
	 if (i>1 && i<=k && j!=1) 	 // if 63-1
     {
      printf("e {to6^%d.%d} {pi3^%d.%d} 1 n\n", i, j, i-1, j-1);
	  printf("e {pil3^%d.%d} {to6^%d.%d} 1 n\n", i-1, j-1, i, j);
	  
	  printf("e {ti6,1^%d.%d} {pol3^%d.%d} 1 n\n", i, j, i-1, j-1);
	  printf("e {po3^%d.%d} {ti6,1^%d.%d} 1 n\n", i-1, j-1, i, j);
	  
	  printf("e {ti6,2^%d.%d} {pol3^%d.%d} 1 n\n", i, j, i-1, j-1);
	  printf("e {po3^%d.%d} {ti6,2^%d.%d} 1 n\n", i-1, j-1, i, j);
	  
	  printf("e {ti6,3^%d.%d} {pol3^%d.%d} 1 n\n", i, j, i-1, j-1);
	  printf("e {po3^%d.%d} {ti6,3^%d.%d} 1 n\n", i-1, j-1, i, j);
	  
	  printf("e {ti6,4^%d.%d} {pol3^%d.%d} 1 n\n", i, j, i-1, j-1);
	  printf("e {po3^%d.%d} {ti6,4^%d.%d} 1 n\n", i-1, j-1, i, j);
	  
	  printf("e {ti6,5^%d.%d} {pol3^%d.%d} 1 n\n", i, j, i-1, j-1);
	  printf("e {po3^%d.%d} {ti6,5^%d.%d} 1 n\n", i-1, j-1, i, j);
	  }
	 else
	  {
	  }	  // end  if 63-1
	  
	  
	  if (i>k) 	 // if 41-1  +++ 63-2
     {
	  // 1-4
	  printf("e {to4^%d.%d} {pi1^%d.%d} 1 n\n", i-1, j+1, i, j);
	  printf("e {pil1^%d.%d} {to4^%d.%d} 1 n\n", i, j, i-1, j+1);
	  
	  printf("e {ti4,1^%d.%d} {pol1^%d.%d} 1 n\n", i-1, j+1, i, j);
	  printf("e {po1^%d.%d} {ti4,1^%d.%d} 1 n\n", i, j, i-1, j+1);
	  
	  printf("e {ti4,2^%d.%d} {pol1^%d.%d} 1 n\n", i-1, j+1, i, j);
	  printf("e {po1^%d.%d} {ti4,2^%d.%d} 1 n\n", i, j, i-1, j+1);
	  
	  printf("e {ti4,3^%d.%d} {pol1^%d.%d} 1 n\n", i-1, j+1, i, j);
	  printf("e {po1^%d.%d} {ti4,3^%d.%d} 1 n\n", i, j, i-1, j+1);
	  
	  printf("e {ti4,5^%d.%d} {pol1^%d.%d} 1 n\n", i-1, j+1, i, j);
	  printf("e {po1^%d.%d} {ti4,5^%d.%d} 1 n\n", i, j, i-1, j+1);
	  
	  printf("e {ti4,6^%d.%d} {pol1^%d.%d} 1 n\n", i-1, j+1, i, j);
	  printf("e {po1^%d.%d} {ti4,6^%d.%d} 1 n\n", i, j, i-1, j+1);
	  
	  //6-3
	  printf("e {to6^%d.%d} {pi3^%d.%d} 1 n\n", i, j, i-1, j);
	  printf("e {pil3^%d.%d} {to6^%d.%d} 1 n\n", i-1, j, i, j);
	  
	  printf("e {ti6,1^%d.%d} {pol3^%d.%d} 1 n\n", i, j, i-1, j);
	  printf("e {po3^%d.%d} {ti6,1^%d.%d} 1 n\n", i-1, j, i, j);
	  
	  printf("e {ti6,2^%d.%d} {pol3^%d.%d} 1 n\n", i, j, i-1, j);
	  printf("e {po3^%d.%d} {ti6,2^%d.%d} 1 n\n", i-1, j, i, j);
	  
	  printf("e {ti6,3^%d.%d} {pol3^%d.%d} 1 n\n", i, j, i-1, j);
	  printf("e {po3^%d.%d} {ti6,3^%d.%d} 1 n\n", i-1, j, i, j);
	  
	  printf("e {ti6,4^%d.%d} {pol3^%d.%d} 1 n\n", i, j, i-1, j);
	  printf("e {po3^%d.%d} {ti6,4^%d.%d} 1 n\n", i-1, j, i, j);
	  
	  printf("e {ti6,5^%d.%d} {pol3^%d.%d} 1 n\n", i, j, i-1, j);
	  printf("e {po3^%d.%d} {ti6,5^%d.%d} 1 n\n", i-1, j, i, j);
	  }    
	  else
	  {
	   }  // end if 41-1  +++ 63-2
	  
	 
	  if (i>1 && i<=k && j!=k-1+i) 	// if 41-2  
     {
      printf("e {to4^%d.%d} {pi1^%d.%d} 1 n\n", i-1, j, i, j);
	  printf("e {pil1^%d.%d} {to4^%d.%d} 1 n\n", i, j, i-1, j);
	  
	  printf("e {ti4,1^%d.%d} {pol1^%d.%d} 1 n\n", i-1, j, i, j);
	  printf("e {po1^%d.%d} {ti4,1^%d.%d} 1 n\n", i, j, i-1, j);
	  
	  printf("e {ti4,2^%d.%d} {pol1^%d.%d} 1 n\n", i-1, j, i, j);
	  printf("e {po1^%d.%d} {ti4,2^%d.%d} 1 n\n", i, j, i-1, j);
	  
	  printf("e {ti4,3^%d.%d} {pol1^%d.%d} 1 n\n", i-1, j, i, j);
	  printf("e {po1^%d.%d} {ti4,3^%d.%d} 1 n\n", i, j, i-1, j);
	  
	  printf("e {ti4,5^%d.%d} {pol1^%d.%d} 1 n\n", i-1, j, i, j);
	  printf("e {po1^%d.%d} {ti4,5^%d.%d} 1 n\n", i, j, i-1, j);
	  
	  printf("e {ti4,6^%d.%d} {pol1^%d.%d} 1 n\n", i-1, j, i, j);
	  printf("e {po1^%d.%d} {ti4,6^%d.%d} 1 n\n", i, j, i-1, j);
	  }
      else
      {
	  }     // end    if 41-2  
	 	 
     }  //   for2 
     
    }   //   for1 
	
	  
 printf("h {g6o-ndr%d}\n", k); 

} /* main */
