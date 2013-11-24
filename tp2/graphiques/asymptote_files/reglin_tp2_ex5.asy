/* File unicodetex not found. */

 /* Geogebra to Asymptote conversion, documentation at artofproblemsolving.com/Wiki, go to User:Azjps/geogebra */
import graph; size(15cm); 
real labelscalefactor = 0.5; /* changes label-to-point distance */
pen dps = linewidth(0.7) + fontsize(10); defaultpen(dps); /* default pen style */ real xmin = -30, xmax = 515, ymin = -20, ymax = 360;  /* image dimensions */

Label laxis; laxis.p = fontsize(10); 
xaxis(xmin, xmax, Ticks(laxis, Step = 50, Size = 2, NoZero), Arrows(6), above = true); 
yaxis(ymin, ymax, Ticks(laxis, Step = 50, Size = 2, NoZero), Arrows(6), above = true); /* draws axes; NoZero hides '0' label */ 
 /* draw figures */
draw(shift((20,352)) * scale(0.3) * ((0,10)--(0,-10)^^(10,0)--(-10,0)), heavyred); /* special point */
draw(shift((30,128)) * scale(0.3) * ((0,10)--(0,-10)^^(10,0)--(-10,0)), heavyred); /* special point */
draw(shift((40,62.3)) * scale(0.3) * ((0,10)--(0,-10)^^(10,0)--(-10,0)), heavyred); /* special point */
draw(shift((50,35.7)) * scale(0.3) * ((0,10)--(0,-10)^^(10,0)--(-10,0)), heavyred); /* special point */
draw(shift((100,6.3)) * scale(0.3) * ((0,10)--(0,-10)^^(10,0)--(-10,0)), heavyred); /* special point */
draw(shift((300,0.4)) * scale(0.3) * ((0,10)--(0,-10)^^(10,0)--(-10,0)), heavyred); /* special point */
draw(shift((500,0.1)) * scale(0.3) * ((0,10)--(0,-10)^^(10,0)--(-10,0)), heavyred); /* special point */
real f1 (real x) {return 696600.1165566964*x^(-2.527188735648365);} 
draw(graph(f1,0.010004160000001,514.99), heavyred); 
 /* dots and labels */
label("$f(x) = 696600.1165566964\times x^{-2.527188735648365}$", (26,250), NE * labelscalefactor,heavyred); 
clip((xmin,ymin)--(xmin,ymax)--(xmax,ymax)--(xmax,ymin)--cycle); 
 /* end of picture */