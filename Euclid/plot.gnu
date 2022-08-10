set title "Euclid plot"
set xrange[10:100]
set yrange[10:1000]
set xlabel "Input size"
set ylabel "Basic op count"
set style data linespoints 
plot "euclidB.txt" title "E Best case","euclidW.txt" title "E Worst case","consecB.txt" title "C Best case",""