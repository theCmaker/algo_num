/* File unicodetex not found. */

 /* Geogebra to Asymptote conversion, documentation at artofproblemsolving.com/Wiki, go to User:Azjps/geogebra */
import graph; size(15cm); 
real labelscalefactor = 0.5; /* changes label-to-point distance */
pen dps = linewidth(0.7) + fontsize(10); defaultpen(dps); /* default pen style */ real xmin = 48, xmax = 108, ymin = -5, ymax = 31;  /* image dimensions */
pen p=fontsize(10pt);
real ystep=10;
xequals(50,ymin,ymax,p,RightTicks(Size=2,end=false,endlabel=false,Step=ystep, NoZero),Arrows(6), above = true);
Label laxis; laxis.p = fontsize(10); 
xaxis(xmin, xmax, Ticks(laxis, Step = 10, Size = 2, NoZero), Arrows(6), above = true); 
yaxis(ymin, ymax, Ticks(laxis, Step = 10, Size = 2, NoZero), Arrows(6), above = true); /* draws axes; NoZero hides '0' label */ 
 /* draw figures */
draw(shift((88,5.89)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((89,6.77)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((90,7.97)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((91,9.11)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((92,10.56)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((93,12.27)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((94,13.92)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((95,15.72)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((96,17.91)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((97,22.13)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
real f1 (real x) {return 0.000020877531085*2.718^(0.14267456117562*x);} 
draw(graph(f1,48.01,107.99), heavyred); 
 /* dots and labels */
label("$f(x) = 0.000020877531085\times e^{0.14267456117562 \cdot x}$", (55,10), NE * labelscalefactor,heavyred); 
clip((xmin,ymin)--(xmin,ymax)--(xmax,ymax)--(xmax,ymin)--cycle); 
 /* end of picture */