/* File unicodetex not found. */

 /* Geogebra to Asymptote conversion, documentation at artofproblemsolving.com/Wiki, go to User:Azjps/geogebra */
import graph; size(15cm); 
real labelscalefactor = 0.5; /* changes label-to-point distance */
pen dps = linewidth(0.7) + fontsize(10); defaultpen(dps); /* default pen style */ real xmin = -3.2, xmax = 16.8, ymin = -2.2, ymax = 13.8;  /* image dimensions */
Label laxis; laxis.p = fontsize(10); 
xaxis(xmin, xmax, Ticks(laxis, Step = 2, Size = 2, NoZero), Arrows(6), above = true); 
yaxis(ymin, ymax, Ticks(laxis, Step = 2, Size = 2, NoZero), Arrows(6), above = true); /* draws axes; NoZero hides '0' label */ 
 /* draw figures */
draw(shift((10,8.04)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((8,6.95)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((13,7.58)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((9,8.81)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((11,8.33)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((14,9.96)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((6,7.24)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((4,4.26)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((12,10.84)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((7,4.82)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((5,5.68)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyred); /* special point */
draw(shift((10,9.14)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyblue); /* special point */
draw(shift((8,8.14)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyblue); /* special point */
draw(shift((13,8.74)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyblue); /* special point */
draw(shift((9,8.77)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyblue); /* special point */
draw(shift((11,9.26)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyblue); /* special point */
draw(shift((14,8.1)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyblue); /* special point */
draw(shift((6,6.13)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyblue); /* special point */
draw(shift((4,3.1)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyblue); /* special point */
draw(shift((12,9.13)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyblue); /* special point */
draw(shift((7,7.26)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyblue); /* special point */
draw(shift((5,4.74)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavyblue); /* special point */
draw(shift((10,7.46)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavygreen); /* special point */
draw(shift((8,6.77)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavygreen); /* special point */
draw(shift((13,12.74)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavygreen); /* special point */
draw(shift((9,7.11)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavygreen); /* special point */
draw(shift((11,7.81)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavygreen); /* special point */
draw(shift((14,8.84)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavygreen); /* special point */
draw(shift((6,6.08)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavygreen); /* special point */
draw(shift((4,5.39)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavygreen); /* special point */
draw(shift((12,8.15)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavygreen); /* special point */
draw(shift((7,6.42)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavygreen); /* special point */
draw(shift((5,5.73)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), heavygreen); /* special point */
draw(shift((10,6.58)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), orange); /* special point */
draw(shift((8,5.76)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), orange); /* special point */
draw(shift((13,7.71)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), orange); /* special point */
draw(shift((9,8.84)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), orange); /* special point */
draw(shift((11,8.47)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), orange); /* special point */
draw(shift((14,7.04)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), orange); /* special point */
draw(shift((6,5.25)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), orange); /* special point */
draw(shift((4,12.5)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), orange); /* special point */
draw(shift((12,5.56)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), orange); /* special point */
draw(shift((7,7.91)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), orange); /* special point */
draw(shift((5,6.89)) * scale(0.15) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), orange); /* special point */
// real f1 (real x) {return 3.000091+0.500091*x;} //f
// draw(graph(f1,-3.19,16.79), heavyred); 
// real f4 (real x) {return 3.000909+0.5*x;} //f'
// draw(graph(f4,-3.19,16.79), heavyblue); 
// real f7 (real x) {return 3.002455+0.499727*x;} //f^{(2)}
// draw(graph(f7,-3.19,16.79), heavygreen); 
// real f10 (real x) {return 9.231364-0.192273*x;} //f^{(3)}
// draw(graph(f10,-3.19,16.79), orange); 
// real f2 (real x) {return 3.804664*exp(0.071377*x);} //g
// draw(graph(f2,-3.19,16.79), heavyred); 
// real f5 (real x) {return 3.417548*2.718^(0.082249*x);} //g^{(1)}
// draw(graph(f5,-3.19,16.79), heavyblue); 
// real f8 (real x) {return 4.100273*2.718^(0.063981*x);} //g^{(2)}
// draw(graph(f8,-3.19,16.79), heavygreen); 
// real f11 (real x) {return 8.564272*2.718^(-0.017989*x);} //g^{(3)}
// draw(graph(f11,-3.19,16.79), orange); 
real f3 (real x) {return 2.020991*x^0.59939;} //h
draw(graph(f3,0.01,16.79), heavyred); 
real f6 (real x) {return 1.453451*x^0.74991;} //h'
draw(graph(f6,0.01,16.79), heavyblue); 
real f9 (real x) {return 2.47857*x^0.507328;} //h^{(2)}
draw(graph(f9,0.01,16.79), heavygreen); 
real f12 (real x) {return 10.959075*x^(-0.192021);} //h^{(3)}
draw(graph(f12,0.01,16.79), orange); 
 /* dots and labels */
// label("$f^{(A)}(x) = 0.500091x + 3.000091$", (9,4), NE * labelscalefactor,heavyred); 
// label("$f^{(1)}(x) = 0.5x + 3.000909$", (9,3), NE * labelscalefactor,heavyblue); 
// label("$f^{(2)}(x) = 0.499727x + 3.002455$", (9,2), NE * labelscalefactor,heavygreen); 
// label("$f^{(3)}(x) = - 0.192273x + 9.231364$", (9,1), NE * labelscalefactor,orange); 
// label("$g^{(A)}(x) = 3.804664 \times e^{0.071377x}$", (9,4), NE * labelscalefactor,heavyred); 
// label("$g^{(1)}(x) = 3.417548 \times e^{0.082249x}$", (9,3), NE * labelscalefactor,heavyblue); 
// label("$g^{(2)}(x) = 4.100273 \times e^{0.063981x}$", (9,2), NE * labelscalefactor,heavygreen); 
// label("$g^{(3)}(x) = 8.564272 \times e^{-0.017989 x}$", (9,1), NE * labelscalefactor,orange); 
label("$h^{(A)}(x) = 2.020991\times x^{0.59939}$", (9,4), NE * labelscalefactor,heavyred); 
label("$h^{(1)}(x) = 1.453451\times x^{0.74991}$", (9,3), NE * labelscalefactor,heavyblue); 
label("$h^{(2)}(x) = 2.47857\times x^{0.507328}$", (9,2), NE * labelscalefactor,heavygreen); 
label("$h^{(3)}(x) = 10.959075\times x^{-0.192021}$", (9,1), NE * labelscalefactor,orange); 
clip((xmin,ymin)--(xmin,ymax)--(xmax,ymax)--(xmax,ymin)--cycle); 
 /* end of picture */