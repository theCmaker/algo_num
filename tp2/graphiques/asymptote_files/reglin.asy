/* File unicodetex not found. */

 /* Geogebra to Asymptote conversion, documentation at artofproblemsolving.com/Wiki, go to User:Azjps/geogebra */
import graph; size(15cm); 
real labelscalefactor = 0.5; /* changes label-to-point distance */
pen dps = linewidth(0.7) + fontsize(10); defaultpen(dps); /* default pen style */ real xmin = -10.866393756, xmax = 11, ymin = -3.3601306561, ymax = 19.1909883867;  /* image dimensions */
pen ttffqq = rgb(0.2,1,0); pen qqqqcc = rgb(0,0,0.8); 
Label laxis; laxis.p = fontsize(10); 
xaxis(xmin, xmax, Ticks(laxis, Step = 2, Size = 2, NoZero), Arrows(6), above = true); 
yaxis(ymin, ymax, Ticks(laxis, Step = 2, Size = 2, NoZero), Arrows(6), above = true); /* draws axes; NoZero hides '0' label */ 
 /* draw figures */
draw(shift((0.5,0.49)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((1,1.6)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((1.5,3.36)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((2,6.44)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
draw(shift((2.5,10.16)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0))); /* special point */
real f1 (real x) {return 4.836*x-2.844;} 
draw(graph(f1,-10.856393756,19.8718202538), heavyblue); 
real f2 (real x) {return 0.299115*exp(1.491228*x);} 
draw(graph(f2,-10.856393756,19.8718202538), heavyred); 
real f3 (real x) {return 1.70314*x^1.88175;} 
draw(graph(f3,0.0100250751,19.8718202538), heavygreen); 
 /* dots and labels */
label("$(0.5, 0.49)$", (1.0467175961,0.3923172622), NE * labelscalefactor); 
label("$(1, 1.6)$", (1.6296221271,1.4852632578), NE * labelscalefactor); 
label("$(1.5, 3.36)$", (2.0303689922,3.2339768507), NE * labelscalefactor); 
label("$(2, 6.44)$", (2.7589996559,6.403520238), NE * labelscalefactor); 
label("$(2.5, 10.16)$", (3.3054726537,10.2288312227), NE * labelscalefactor); 
label("$f(x) = 4.836x - 2.844$", (-10,4), NE * labelscalefactor,heavyblue); 
label("$g(x) = 0.299115 \times e^{1.491228x}$", (-10,3), NE * labelscalefactor,heavyred); 
label("$h(x) = 1.70314 \times x^{1.88175}$", (-10,2), NE * labelscalefactor,heavygreen); 
clip((xmin,ymin)--(xmin,ymax)--(xmax,ymax)--(xmax,ymin)--cycle); 
 /* end of picture */