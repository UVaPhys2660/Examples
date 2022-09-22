set xlabel "re"
set ylabel "im"
plot [-2:0.5][-1:1] "mandel.dat" using 1:2:3 with image ti ""

set term png
set output "mandel.png"
replot
set output
st term pop

