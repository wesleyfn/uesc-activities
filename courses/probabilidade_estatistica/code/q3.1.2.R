source("q3.1.1.R")

png(filename="../graphs/q3.1.2", width=1100, height=550)

  x11()
  par(mfrow=c(1, 2))
  plot(Y1Masculino,
       Y2Masculino,
       pch=20,
       cex=0.3,
       xlab='Y1',
       ylab='Y2',
       col='black',
       main="Masculino")
  
  plot(Y1Feminino,
       Y2Feminino,
       pch=20,
       cex=0.3,
       xlab='Y1',
       ylab='Y2',
       col='black',
       main="Feminino")
  
  dev.off()
  