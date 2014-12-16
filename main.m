[W,H,im] =read_im('temp','00_02.jpg',1);
attsLex =createLexAtts( );
[a,b,c,d] =img2attr(im);

candidates =read_windows();
%windows =[2,4,50,80;20,36,120,290;];

windows = [candidates(:).y1; candidates(:).x1;candidates(:).y2; candidates(:).x2]';
x = AttWindows(windows,d,c+1,b+1 );

s = x' *attsLex;

