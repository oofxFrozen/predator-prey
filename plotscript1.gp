set terminal pngcairo size 800,600 enhanced font 'Verdana,10'
set output 'results2.png'

set title "Predator-Prey model"
set xlabel "K"
set ylabel "V"

set xrange [-80:120]
set yrange [-80:120]

plot 'kv.dat' using 1:2 with points title "K(V)"
