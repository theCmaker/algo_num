/* File unicodetex not found. */

 /* Geogebra to Asymptote conversion, documentation at artofproblemsolving.com/Wiki, go to User:Azjps/geogebra */
import graph; size(15cm); 
real labelscalefactor = 0.5; /* changes label-to-point distance */
pen dps = linewidth(0.7) + fontsize(10); defaultpen(dps); /* default pen style */ real xmin = -5.5, xmax = 17.8, ymin = -1.5, ymax = 13.8;  /* image dimensions */
Label laxis; laxis.p = fontsize(10); 
xaxis(xmin, xmax, Ticks(laxis, Step = 2, Size = 2, NoZero), Arrows(6), above = true); 
yaxis(ymin, ymax, Ticks(laxis, Step = 2, Size = 2, NoZero), Arrows(6), above = true); /* draws axes; NoZero hides '0' label */ 
 /* draw figures */
draw(shift((10,8.04)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((8,6.95)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((13,7.58)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((9,8.81)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((11,8.33)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((14,9.96)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((6,7.24)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((4,4.26)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((12,10.84)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((7,4.82)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((5,5.68)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
real f1 (real x) {return 3.000091+0.500091*x;} 
draw(graph(f1,-5.5653696561,17.79), heavyred); 
real f2 (real x) {return 3.804664*exp(0.071377*x);} 
draw(graph(f2,-5.5653696561,17.79), heavyblue); 
real f3 (real x) {return 2.020991*x^0.59939;} 
draw(graph(f3,0.0100000924,17.79), heavygreen); 
 /* dots and labels */
label("$f(x) = 0.500091x+ 3.000091 $", (10,5), NE * labelscalefactor,heavyred); 
label("$g(x) = 3.804664 \times e^{0.071377x}$", (10,4), NE * labelscalefactor,heavyblue); 
label("$h(x) = 2.020991 \times x^{0.59939}$", (10,3), NE * labelscalefactor,heavygreen); 
clip((xmin,ymin)--(xmin,ymax)--(xmax,ymax)--(xmax,ymin)--cycle); 
 /* end of picture */