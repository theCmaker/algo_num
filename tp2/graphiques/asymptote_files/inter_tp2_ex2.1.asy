/* File unicodetex not found. */

 /* Geogebra to Asymptote conversion, documentation at artofproblemsolving.com/Wiki, go to User:Azjps/geogebra */
import graph; size(15cm); 
real labelscalefactor = 0.5; /* changes label-to-point distance */
pen dps = linewidth(0.7) + fontsize(10); defaultpen(dps); /* default pen style */ real xmin = -1, xmax = 15.9, ymin = -1, ymax = 15.9;  /* image dimensions */
Label laxis; laxis.p = fontsize(10); 
xaxis(xmin, xmax, Ticks(laxis, Step = 2, Size = 2, NoZero), Arrows(6), above = true); 
yaxis(ymin, ymax, Ticks(laxis, Step = 2, Size = 2, NoZero), Arrows(6), above = true); /* draws axes; NoZero hides '0' label */ 
 /* draw figures */
real f1 (real x) {return - 229.54999999981407654559006914496421813964843750000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 + 299.16574999975705395627301186323165893554687500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x - 173.10763630938384949331521056592464447021484375000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^2 + 58.54695535709602438600995810702443122863769531250000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^3 - 12.73186235118038567293297091964632272720336914062500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^4 + 1.85990624999853682020045653189299628138542175292968750000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^5 - 0.18496770833318856852578448979329550638794898986816406250000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^6 + 0.01237499999999034337727632504311259253881871700286865234375000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^7 - 0.00053348214285672693538153943393353983992710709571838378906250000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^8 + 0.00001339285714284669147539682393377447056082019116729497909545898437500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^9 - 0.00000014880952380940735718756694726250255911281783482991158962249755859375000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^10;} 
draw(graph(f1,-0.99,15.89), heavyred); 
real f2 (real x) {return - 229.54999999985207637109851930290460586547851562500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 + 299.16574999981492055667331442236900329589843750000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x - 173.10763630941968926890695001929998397827148437500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^2 + 58.54695535710822440478295902721583843231201171875000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^3 - 12.73186235118295250856590428156778216361999511718750000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^4 + 1.85990624999888831681005285645369440317153930664062500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^5 - 0.18496770833322054294889369430165970697999000549316406250000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^6 + 0.01237499999999224636892947160049516241997480392456054687500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^7 - 0.00053348214285679719168231649462086352286860346794128417968750000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^8 + 0.00001339285714284810940855052763254207093268632888793945312500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^9 - 0.00000014880952380941826273676284637936806376501408522017300128936767578125000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^10;} 
draw(graph(f2,-0.99,15.89), heavyblue); 
// real f3 (real x) {return - 12345.19000000004962203092873096466064453125000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 + 16608.06649206355359638109803199768066406250000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x - 9870.94149841273429046850651502609252929687500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^2 + 3416.59389175486194289987906813621520996093750000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^3 - 763.09400914903244483866728842258453369140625000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^4 + 114.97998495370404725690605118870735168457031250000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^5 - 11.84244224537040501843421225203201174736022949218750000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^6 + 0.82365839947090180306332740656216628849506378173828125000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^7 - 0.03703885582010591620560902015313331503421068191528320312500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^8 + 0.00097282848324515224479325237183502395055256783962249755859375000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^9 - 0.00001133708112874782039398297017740446790412534028291702270507812500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^10;} 
// draw(graph(f3,-0.99,15.89), heavyred); 
// real f4 (real x) {return - 12345.18999999995139660313725471496582031250000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 + 16608.06649206353540648706257343292236328125000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x - 9870.94149841276521328836679458618164062500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^2 + 3416.59389175487922329921275377273559570312500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^3 - 763.09400914903608281747438013553619384765625000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^4 + 114.97998495370453042596636805683374404907226562500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^5 - 11.84244224537045653278255485929548740386962890625000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^6 + 0.82365839947090602191082098215701989829540252685546875000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^7 - 0.03703885582010608273906271392661437857896089553833007812500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^8 + 0.00097282848324515354583585935444034475949592888355255126953125000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^9 - 0.00001133708112874781361771939214300175535754533484578132629394531250000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^10 ;} 
// draw(graph(f4,-0.99,15.89), heavyblue); 
// real f5 (real x) {return - 568559.64000000013038516044616699218750000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 + 739678.38126984133850783109664916992187500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x - 424130.45085753966122865676879882812500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^2 + 141275.52322415125672705471515655517578125000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^3 - 30298.69300551146807265467941761016845703125000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^4 + 4375.22205931712960591539740562438964843750000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^5 - 431.15599172453710252739256247878074645996093750000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^6 + 28.65264045965608730170970375183969736099243164062500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^7 - 1.22980299272486770512102793873054906725883483886718750000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^8 + 0.03080623070987653991381627349710470298305153846740722656250000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^9 - 0.00034223159171075837698891564109260343684582039713859558105468750000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^10;} 
// draw(graph(f5,-0.99,15.89), heavyred); 
// real f6 (real x) {return - 568559.64000000024680048227310180664062500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 + 739678.38126984133850783109664916992187500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x - 424130.45085753966122865676879882812500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^2 + 141275.52322415122762322425842285156250000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^3 - 30298.69300551146807265467941761016845703125000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^4 + 4375.22205931713051541009917855262756347656250000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^5 - 431.15599172453715937081142328679561614990234375000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^6 + 28.65264045965609085442338255234062671661376953125000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^7 - 1.22980299272486792716563286376185715198516845703125000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^8 + 0.03080623070987655032215712935794726945459842681884765625000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^9 - 0.00034223159171075843119902426536782513721846044063568115234375000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 * x^10;} 
// draw(graph(f6,-0.99,15.89), heavyblue); 
//serie1
draw(shift((10,9.14)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
draw(shift((8,8.14)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
draw(shift((13,8.74)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
draw(shift((9,8.77)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
draw(shift((11,9.26)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
draw(shift((14,8.1)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
draw(shift((6,6.13)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
draw(shift((4,3.1)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
draw(shift((12,9.13)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
draw(shift((7,7.26)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
draw(shift((5,4.74)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// //serie2
// draw(shift((10,7.46)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((8,6.77)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((13,12.74)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((9,7.11)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((11,7.81)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((14,8.84)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((6,6.08)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((4,5.39)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((12,8.15)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((7,6.42)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((5,5.73)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// //serie3
// draw(shift((10,6.58)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((8,5.76)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((13,7.71)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((9,8.84)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((11,8.47)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((14,7.04)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((6,5.25)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((4,12.5)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((12,5.56)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((7,7.91)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
// draw(shift((5,6.89)) * scale(0.3) * ((0,1)--(0,-1)^^(1,0)--(-1,0)), black); /* special point */
 /* dots and labels */
 label("$f^{(1)}(x) \approx -229.550000 + 299.165750 \cdot x- 173.107636 \cdot x^{2}  + 58.546955 \cdot x^{3}$", (1,14), NE * labelscalefactor,heavyred);
label("$- 12.731862 \cdot x^{4}  + 1.859906 \cdot x^{5} - 0.184968 \cdot x^{6}  + 0.012375 \cdot x^{7}$", (3,13.5), NE * labelscalefactor,heavyred);
label("$ - 0.000533 \cdot x^{8}  + 0.000013 \cdot x^{9} - 0.000000 \cdot x^{10} $", (3,13), NE * labelscalefactor,heavyred); 
label("$g^{(1)}(x) \approx -229.550000 + 299.165750 \cdot x- 173.107636 \cdot x^{2}  + 58.546955 \cdot x^{3}$", (1,12), NE * labelscalefactor,heavyblue);
label("$ - 12.731862 \cdot x^{4}  + 1.859906 \cdot x^{5} - 0.184968 \cdot x^{6}  + 0.012375 \cdot x^{7}$", (3,11.5), NE * labelscalefactor,heavyblue);
label("$ - 0.000533 \cdot x^{8}  + 0.000013 \cdot x^{9} - 0.000000 \cdot x^{10} $", (3,11), NE * labelscalefactor,heavyblue); 
// label("$f^{(2)}(x) \approx -12345.190000 + 16608.066492 \cdot x- 9870.941498 \cdot x^{2}  + 3416.593892 \cdot x^{3} - 763.094009 \cdot x^{4}  + 114.979985 \cdot x^{5} - 11.842442 \cdot x^{6}  + 0.823658 \cdot x^{7} - 0.037039 \cdot x^{8}  + 0.000973 \cdot x^{9} - 0.000011 \cdot x^{10} $", (-32.39732797676179,-4.662579379574618), NE * labelscalefactor,heavyred); 
// label("$g^{(2)}(x) \approx -12345.190000 + 16608.066492 \cdot x- 9870.941498 \cdot x^{2}  + 3416.593892 \cdot x^{3} - 763.094009 \cdot x^{4}  + 114.979985 \cdot x^{5} - 11.842442 \cdot x^{6}  + 0.823658 \cdot x^{7} - 0.037039 \cdot x^{8}  + 0.000973 \cdot x^{9} - 0.000011 \cdot x^{10} $", (-45.90148543609371,-4.662579379574618), NE * labelscalefactor,heavyblue); 
// label("$f^{(3)}(x) \approx -568559.640000 + 739678.381270 \cdot x- 424130.450858 \cdot x^{2}  + 141275.523224 \cdot x^{3} - 30298.693006 \cdot x^{4}  + 4375.222059 \cdot x^{5} - 431.155992 \cdot x^{6}  + 28.652640 \cdot x^{7} - 1.229803 \cdot x^{8}  + 0.030806 \cdot x^{9} - 0.000342 \cdot x^{10} $", (-37.835002047052775,-4.662579379574618), NE * labelscalefactor,heavyred); 
// label("$g^{(3)}(x) \approx -568559.640000 + 739678.381270 \cdot x- 424130.450858 \cdot x^{2}  + 141275.523224 \cdot x^{3} - 30298.693006 \cdot x^{4}  + 4375.222059 \cdot x^{5} - 431.155992 \cdot x^{6}  + 28.652640 \cdot x^{7} - 1.229803 \cdot x^{8}  + 0.030806 \cdot x^{9} - 0.000342 \cdot x^{10} $", (-46.225585215117675,-4.662579379574618), NE * labelscalefactor,heavyblue); 
clip((xmin,ymin)--(xmin,ymax)--(xmax,ymax)--(xmax,ymin)--cycle); 
 /* end of picture */