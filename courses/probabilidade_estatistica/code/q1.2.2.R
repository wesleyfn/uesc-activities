source("q1.2.1.R")

#1.2.2
png(filename="../graphs/q1.2.2a", width=1300, height=550)
  
  x11()
  par(mfrow=c(1, 2))
  plot(masculinotb,
       type='fh',
       x.round=2,
       xlab='Y1',
       ylab='Frequência')
  
  plot(masculinotb,
       type='cfp',
       x.round=2,
       xlab='Y1',
       ylab='Frequência Acumulada',
       col='black')

dev.off()

png(filename="../graphs/q1.2.2b", width=1300, height=550)
  
  x11()
  par(mfrow=c(1, 2))
  plot(femininotb,
       type='fh',
       x.round=2,
       xlab='Y1',
       ylab='Frequência')
  
  plot(femininotb,
       type='cfp',
       x.round=2,
       xlab='Y1',
       ylab='Frequência Acumulada',
       col='black')

dev.off()
