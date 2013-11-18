/* File unicodetex not found. */

 /* Geogebra to Asymptote conversion, documentation at artofproblemsolving.com/Wiki, go to User:Azjps/geogebra */
import graph; size(15cm); 
real labelscalefactor = 0.5; /* changes label-to-point distance */
pen dps = linewidth(0.7) + fontsize(10); defaultpen(dps); /* default pen style */ real xmin = -2.13, xmax = 8.21, ymin = -2.68, ymax = 6.57;  /* image dimensions */

Label laxis; laxis.p = fontsize(10); 
xaxis(xmin, xmax, Ticks(laxis, Step = 1, Size = 2, NoZero), Arrows(6), above = true); 
yaxis(ymin, ymax, Ticks(laxis, Step = 1, Size = 2, NoZero), Arrows(6), above = true); /* draws axes; NoZero hides '0' label */ 
 /* draw figures */
real f1 (real x) {return -6+11*x-6*x^2+x^3;} 
draw(graph(f1,-2.12,13.2), red); 
draw(shift((1,0)) * scale(0.1) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((2,0)) * scale(0.1) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((3,0)) * scale(0.1) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((4,6)) * scale(0.1) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
 /* dots and labels */
label("$f(x) = -6 + 11x - 6x^2 + x^3$", (4,2), NE * labelscalefactor,red); 
clip((xmin,ymin)--(xmin,ymax)--(xmax,ymax)--(xmax,ymin)--cycle); 
 /* end of picture */