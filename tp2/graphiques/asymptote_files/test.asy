/* File unicodetex not found. */

 /* Geogebra to Asymptote conversion, documentation at artofproblemsolving.com/Wiki, go to User:Azjps/geogebra */
import graph; size(160.55cm); 
real labelscalefactor = 0.5; /* changes label-to-point distance */
pen dps = linewidth(0.7) + fontsize(10); defaultpen(dps); /* default pen style */ real xmin = 400, xmax = 1000, ymin = 70, ymax = 300;  /* image dimensions */

Label laxis; laxis.p = fontsize(10); 
xaxis(xmin, xmax, Ticks(laxis, Step = 10, Size = 2, NoZero), Arrows(6), above = true); 
yaxis(ymin, ymax, Ticks(laxis, Step = 5, Size = 2, NoZero), Arrows(6), above = true); /* draws axes; NoZero hides '0' label */ 
 /* draw figures */
draw(shift((752,85)) * scale(2) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((855,83)) * scale(2) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((871,162)) * scale(2) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
real f1 (real x) {return 524166663.15-8065079.74*x+55479.77*x^2-224.69*x^3+0.59*x^4;} 
draw(graph(f1,146.07,306.6)); 
 /* dots and labels */
clip((xmin,ymin)--(xmin,ymax)--(xmax,ymax)--(xmax,ymin)--cycle); 
 /* end of picture */