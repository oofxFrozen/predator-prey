set terminal pngcairo size 800,600 enhanced font 'Verdana,10'
set output 'results1.png'

set title "Predator-Prey model"
set xlabel "t"
set ylabel "V/K"

set xrange [0:100]
set yrange [-80:120]

plot 'v.dat' using 2:1 with points title "V(t)", \
     'k.dat' using 2:1 with points title "K(t)"
