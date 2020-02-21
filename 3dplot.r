#!/usr/bin/env Rscript
library(rgl)
#file <- readline("Enter file to plot interactively")
args <- commandArgs(TRUE)
data <- read.table(args[1], sep=" ")
xs <- as.matrix(data[1])
ys <- as.matrix(data[2])
zs <- as.matrix(data[3])
plot3d(xs,ys,zs, col="red", size=1)
play3d(function(time) {Sys.sleep(0.01); list()} )