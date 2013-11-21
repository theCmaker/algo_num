/* File unicodetex not found. */

 /* Geogebra to Asymptote conversion, documentation at artofproblemsolving.com/Wiki, go to User:Azjps/geogebra */
import graph; size(30cm); 
real labelscalefactor = 0.5; /* changes label-to-point distance */
pen dps = linewidth(0.7) + fontsize(10); defaultpen(dps); /* default pen style */ real xmin = 400, xmax = 900, ymin = -2, ymax = 100;  /* image dimensions */
pen qqwuqq = rgb(0,0.392156862745098,0); 
Label laxis; laxis.p = fontsize(10); 
xaxis(xmin, xmax, Ticks(laxis, Step = 100, Size = 2, NoZero), Arrows(6), above = true); 
yaxis(ymin, ymax, Ticks(laxis, Step = 100, Size = 2, NoZero), Arrows(6), above = true); /* draws axes; NoZero hides '0' label */ 
 /* draw figures */
draw(shift((752,85)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((855,83)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((828,82)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((809,77)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((734,79)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((610,81)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((582,83)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((492,81)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((569,81)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((462,80)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((643,84)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((862,84)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((524,82)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((679,80)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((902,226)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((918,260)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((871,162)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((875,186)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((921,281)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((907,243)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
draw(shift((894,223)) * scale(0.00635) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), qqwuqq); /* special point */
real f1 (real x) {return 73581192209.962600708007812500 - 1459287367.863512516021728516 * x + 13300351.970502268522977829 * x^2 - 73765.523296602768823504 * x^3 + 277.759281212842438435 * x^4 - 0.749863232601135521 * x^5 + 0.001493269569857343 * x^6 - 0.000002220975304171 * x^7 + 0.000000002467239262 * x^8 - 0.000000000002021899 * x^9 + 0.000000000000001188 * x^10 - 0.000000000000000000 * x^11 + 0.000000000000000000 * x^12 - 0.000000000000000000 * x^13 ;} 
draw(graph(f1,400.01,899.99)); 
real f2 (real x) {return 621022623331.5474-4157904770.816573*x+11598209.746190542*x^2-17253.085748098776*x^3+14.435304071826478*x^4-0.006440873378374*x^5+0.000001197328784*x^6;} 
draw(graph(f2,400.01,899.99)); 
draw((xmin, 0*xmin + 80)--(xmax, 0*xmax + 80)); /* line */
 /* dots and labels */
clip((xmin,ymin)--(xmin,ymax)--(xmax,ymax)--(xmax,ymin)--cycle); 
 /* end of picture */