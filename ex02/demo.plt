# gnuplot demo
# here we plot three one dimensional functions
# a few basic options are illustrated

set xlabel "x"
set ylabel "arbitrary units"

plot "out.dat" using 1:2, \
     "out.dat" using 1:3 with lines, \
     "out.dat" using 1:4 with linespoints title "fcn3(x,1.3)/20"  